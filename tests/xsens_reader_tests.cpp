#include "gtest/gtest.h"

#include "xsens_reader_handler.h"

class XsensReaderTests : public ::testing::Test
{
    protected:
        void SetUp(void) override
        {}
};

TEST_F(XsensReaderTests, ConstructorTest)
{
    XsControl* control = XsControl::construct();
    XsPortInfo mtPort;
    XsDevice* device = control->device(mtPort.deviceId());
    xsens_reader::XsensReaderHandler callback;

    device->addCallbackHandler(&callback);

    EXPECT_TRUE(true);
}