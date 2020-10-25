// LTC2943 driver code

#include "LTC2943_registers.hpp"

#include "i2c.hpp"
#include "LTC2943.hpp"

// function result managing helpers
#define RESULT_TYPE             LTC2943::Result
#define _RESULT_OK              LTC2943::RESULT_OK
#define _RESULT_ARGUMENT_NULL   LTC2943::RESULT_ARGUMENT_NULL

#define R_BEGIN RESULT_TYPE _RESULT = _RESULT_OK;
#define R_CHECK(resultTypeFnc) \
    _RESULT = (resultTypeFnc); \
    if(_RESULT != _RESULT_OK) { goto R_END_LABEL; }
#define R_RETURN(result) _RESULT = result; goto R_END_LABEL
#define R_NULL_CHECK(ptrArg) if(ptrArg == NULL) R_RETURN(_RESULT_ARGUMENT_NULL)
#define R_FINAL R_END_LABEL:;
#define R_END return _RESULT;
#define R_FINAL_END R_FINAL R_END;

LTC2943::LTC2943()
{
}

LTC2943::~LTC2943()
{
    
}

LTC2943::Result LTC2943::getAdcMode(AdcMode &mode)
{
R_BEGIN
    ControlReg reg;
    R_CHECK(getControl(reg));
    mode = static_cast<AdcMode>(reg.fields.adcMode);
R_FINAL_END
}

LTC2943::Result LTC2943::setAdcMode(AdcMode mode)
{
R_BEGIN
    ControlReg reg;
    R_CHECK(getControl(reg));
    reg.fields.adcMode = mode;
    R_CHECK(setControl(reg));
R_FINAL_END
}

LTC2943::Result LTC2943::setControl(ControlReg reg)
{
R_BEGIN
    const uint8_t writeMsg[2] = {static_cast<uint8_t>(REG_B), reg.byte};
    const uint8_t * pWriteMsg = reinterpret_cast<const uint8_t *>(&writeMsg);
    R_CHECK(write(pWriteMsg, 2));
R_FINAL_END
}

LTC2943::Result LTC2943::getControl(ControlReg &reg)
{
R_BEGIN
    const uint8_t controlReg = REG_B;
    R_CHECK(write(&controlReg, 1));
    R_CHECK(read(&reg.byte, 1));
R_FINAL_END
}

LTC2943::Result LTC2943::getStatus(StatusReg &reg)
{
R_BEGIN
    const uint8_t statusReg = REG_A;
    R_CHECK(write(&statusReg, 1));
    R_CHECK(read(&reg.byte, 1));
R_FINAL_END
}

LTC2943::Result LTC2943::write(const uint8_t * pSrc, uint16_t dataSize)
{
R_BEGIN
    R_CHECK(isIntialized());
    if(i2cWrite(LTC2943_I2C_ADDRESS, pSrc, dataSize) == false)
    {
        R_RETURN(RESULT_WRITE_FAIL);
    }
R_FINAL_END
}

LTC2943::Result LTC2943::read(uint8_t * pDst, uint16_t dataSize)
{
R_BEGIN
    R_CHECK(isIntialized());
    if(i2cRead(LTC2943_I2C_ADDRESS, pDst, dataSize) == false)
    {
        R_RETURN(RESULT_READ_FAIL);
    }
R_FINAL_END
}

LTC2943::Result LTC2943::isIntialized()
{
R_BEGIN
    if(i2cIsInitialized() == false)
    {
        R_RETURN(RESULT_NOT_INITIALIZED);
    }
R_FINAL_END
}

LTC2943::Result LTC2943::init()
{
R_BEGIN
    if(i2cInit() == false)
    {
        R_RETURN(RESULT_INIT_FAIL);
    }
R_FINAL_END
}

LTC2943::Result LTC2943::deinit()
{
R_BEGIN
    if(i2cDeinit() == false)
    {
        R_RETURN(RESULT_DEINIT_FAIL);
    }
R_FINAL_END
}
