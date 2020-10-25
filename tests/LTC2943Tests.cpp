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
    LTC2943 ltc;
    ltc.init();
    bool isPending;
    ASSERT_EQ(LTC2943::RESULT_OK, ltc.checkTemperatureAlert(isPending));
    ASSERT_FALSE(isPending);
}

TEST(LTC2943Tests, CheckIfVoltageAlertIsPending) 
{
    LTC2943 ltc;
    ltc.init();
    bool isPending;
    ASSERT_EQ(LTC2943::RESULT_OK, ltc.checkVoltageAlert(isPending));
    ASSERT_FALSE(isPending);
}


// i2c emulation backdoor prototypes
void LTC2943_I2C_EMULATE_STATUS_REG(uint8_t statusReg);
void LTC2943_I2C_EMULATE_CONTROL_REG(uint8_t controlReg);


// goal tests
TEST(LTC2943Tests, ChangeChipAdcModeIntoManualModeOnEmulatedI2C) 
{   
#define EMULATED_CONTROL_REG_VAL 0xF0
LTC2943_I2C_EMULATE_CONTROL_REG(EMULATED_CONTROL_REG_VAL);

    LTC2943 ltc;
    ltc.init();

    LTC2943::AdcMode adcMode;
    ltc.getAdcMode(adcMode); 
    ASSERT_EQ(LTC2943::adcModeAutomatic, adcMode);

    ltc.setAdcMode(LTC2943::adcModeManual);

    ltc.getAdcMode(adcMode); 
    ASSERT_EQ(LTC2943::adcModeManual, adcMode);
}

