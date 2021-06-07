#include "gtest/gtest.h"

#include "xsens_reader.h"

class XsensReaderTests : public ::testing::Test
{
    protected:
        void SetUp(void) override
        {}
};

TEST_F(XsensReaderTests, ConstructorTest)
{
    xsens_reader::XsensReader reader;
    EXPECT_TRUE(true);
}