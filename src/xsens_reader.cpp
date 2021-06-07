#include "xsens_reader.h"

#include <xsensdeviceapi.h>
#include <xstypes/xstime.h>
#include <xscommon/xsens_mutex.h>

namespace xsens_reader
{
    XsensReader::XsensReader(size_t max_packets_number_in_buffer) 
        : max_packets_number_in_buffer_{max_packets_number_in_buffer}
    {}

    XsDataPacket XsensReader::getNextPacket(void)
    {
        assert(packetAvailable());
		xsens::Lock locky(&mutex_);
		XsDataPacket oldest_packet(packet_buffer_.front());
		packet_buffer_.pop_front();
		--packets_number_in_buffer_;
		return oldest_packet;
    }

    bool XsensReader::packetAvailable(void) const
    {
        xsens::Lock locky(&mutex_);
		return packets_number_in_buffer_ > 0u;
    }

    void XsensReader::onLiveDataAvailable(XsDevice *device, const XsDataPacket *packet)
    {
        xsens::Lock locky(&mutex_);
        assert(packet != nullptr);
        while (packets_number_in_buffer_ >= max_packets_number_in_buffer_)
            (void)getNextPacket();

        packet_buffer_.push_back(*packet);
        ++packets_number_in_buffer_;
        assert(packets_number_in_buffer_ <= max_packets_number_in_buffer_);
    }
}
