#include <gtest/gtest.h>
#include "LTC2943.hpp"

TEST(LTC2943Tests, initDeinit) 
{
    LTC2943::Result res;
    LTC2943 ltc2943;
    res = ltc2943.init();
    ASSERT_EQ(res, LTC2943::RESULT_OK);
    ltc2943.deinit();
    ASSERT_EQ(res, LTC2943::RESULT_OK);
}

// goal tests

TEST(LTC2943Tests, ChangeChipAdcModeIntoAutomaticMode) 
{   
    LTC2943 ltc2943;
    ltc2943.init();
    ltc2943.setAdcMode(LTC2943::adcModeAutomatic);
}

TEST(LTC2943Tests, ChangeChipAdcModeIntoScanMode) 
{
    LTC2943 ltc2943;
    ltc2943.init();
    ltc2943.setAdcMode(LTC2943::adcModeScan);
}

TEST(LTC2943Tests, ChangeChipAdcModeIntoManualMode) 
{
    LTC2943 ltc2943;
    ltc2943.init();
    ltc2943.setAdcMode(LTC2943::adcModeManual);
}

TEST(LTC2943Tests, ChangeChipAdcModeIntoSleepMode) 
{
    LTC2943 ltc2943;
    ltc2943.init();
    ltc2943.setAdcMode(LTC2943::adcModeSleep);
}

TEST(LTC2943Tests, GetChipAdcMode) {
    LTC2943 ltc2943;
    ltc2943.init();
    LTC2943::AdcMode adcMode;
    ltc2943.getAdcMode(adcMode); 
    ASSERT_EQ(adcMode, LTC2943::adcModeSleep);
}

TEST(LTC2943Tests, CheckIfTemperatureAlertIsPending) 
{
    
    EXPECT_TRUE(true);
}

TEST(LTC2943Tests, CheckIfVoltageAlertIsPending) 
{
    EXPECT_TRUE(true);
}
