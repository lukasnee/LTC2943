#include <gtest/gtest.h>
#include "LTC2943.hpp"

TEST(LTC2943Tests, init) 
{
    LTC2943 ltc;
    ASSERT_EQ(ltc.init(), LTC2943::RESULT_OK);
}

TEST(LTC2943Tests, deinit)
{
    LTC2943 ltc;
    ltc.init();
    ASSERT_EQ(ltc.deinit(), LTC2943::RESULT_OK);
}

// goal tests
TEST(LTC2943Tests, ChangeChipAdcModeIntoAutomaticMode) 
{   
    LTC2943 ltc;
    ltc.init();
    ASSERT_EQ(LTC2943::RESULT_OK, ltc.setAdcMode(LTC2943::adcModeAutomatic));
}

TEST(LTC2943Tests, ChangeChipAdcModeIntoScanMode) 
{
    LTC2943 ltc;
    ltc.init();
    ASSERT_EQ(LTC2943::RESULT_OK, ltc.setAdcMode(LTC2943::adcModeScan));
}

TEST(LTC2943Tests, ChangeChipAdcModeIntoManualMode) 
{
    LTC2943 ltc;
    ltc.init();
    ASSERT_EQ(LTC2943::RESULT_OK, ltc.setAdcMode(LTC2943::adcModeManual));
}

TEST(LTC2943Tests, ChangeChipAdcModeIntoSleepMode) 
{
    LTC2943 ltc;
    ltc.init();
    ASSERT_EQ(LTC2943::RESULT_OK, ltc.setAdcMode(LTC2943::adcModeSleep));
}

TEST(LTC2943Tests, GetChipAdcMode) 
{
    LTC2943 ltc;
    ltc.init();
    LTC2943::AdcMode adcMode;
    ltc.getAdcMode(adcMode); 
    ASSERT_EQ(LTC2943::adcModeSleep, adcMode);
}

TEST(LTC2943Tests, CheckIfTemperatureAlertIsPending) 
{
    
    EXPECT_TRUE(true);
}

TEST(LTC2943Tests, CheckIfVoltageAlertIsPending) 
{
    EXPECT_TRUE(true);
}
