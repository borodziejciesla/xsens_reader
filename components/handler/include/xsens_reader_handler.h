#ifndef XSENS_READER_INCLUDE_XSENS_READER_HANDLER_H_
#define XSENS_READER_INCLUDE_XSENS_READER_HANDLER_H_

#include <xsensdeviceapi.h>
#include <xstypes/xstime.h>
#include <xscommon/xsens_mutex.h>

#include <list>
#include <memory>

namespace xsens_reader
{
    class XsensReaderHandler : public XsCallback
    {
        public:
            XsensReaderHandler(size_t max_packets_number_in_buffer = 5u);
            ~XsensReaderHandler(void) = default;

            XsDataPacket getNextPacket(void);
            bool packetAvailable(void) const;

        protected:
            virtual void onLiveDataAvailable(XsDevice *device, const XsDataPacket *packet);

        private:
            mutable xsens::Mutex mutex_;

            size_t max_packets_number_in_buffer_;
            size_t packets_number_in_buffer_ = 0u;
            std::list<XsDataPacket> packet_buffer_;
    };
}

#endif //XSENS_READER_INCLUDE_XSENS_READER_HANDLER_H_
