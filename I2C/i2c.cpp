/* Here I emulate LTC2943 status and control registers over I2C for more 
thorough testing without using actual hardware. These methods should of course 
be replace with real hardware. NOTE: I'm interpreting that all i2c...() methods 
work in blocking manner. -Lukas N.*/

#include "i2c.hpp"

#include "LTC2943_registers.hpp"
static bool isInitialized = false;

bool i2cInit(void)
{
    isInitialized = true;
    return true;
}

bool i2cDeinit(void)
{
    isInitialized = false;
    return true;
}

bool i2cIsInitialized(void)
{
    return isInitialized;
}

static uint8_t LTC2943_I2C_REGS[2] = 
{
    0x00, // REG_A (status reg)
    0x3C // REG_B (control reg)
};

void LTC2943_I2C_EMULATE_STATUS_REG(uint8_t statusReg)
{   
    LTC2943_I2C_REGS[REG_A] = statusReg;
}

void LTC2943_I2C_EMULATE_CONTROL_REG(uint8_t controlReg)
{   
    LTC2943_I2C_REGS[REG_B] = controlReg;
}

static uint8_t accessingDeviceAddress = 0;
static uint8_t accessingRegisterAddress = 0;

#include <cstring>
// Read data from I2C device to pDst buffer
bool i2cRead(uint8_t address, uint8_t *pDst, uint16_t dataSize)
{
    if(i2cIsInitialized)
    {
        if(address == LTC2943_I2C_ADDRESS && dataSize > 0)
        {
            if(accessingRegisterAddress < sizeof(LTC2943_I2C_REGS))
            {
                memset(pDst, LTC2943_I2C_REGS[accessingRegisterAddress], 1);
                memset(pDst + 1, 0x00, dataSize - 1);
                return true;
            }
        }
    }
    return false;
}

// Write data from pSrc buffer to I2C device
bool i2cWrite(uint8_t address, const uint8_t *pSrc, uint16_t dataSize) 
{
    if(i2cIsInitialized)
    {
        if(address == LTC2943_I2C_ADDRESS && dataSize > 0)
        {
            if(accessingRegisterAddress < sizeof(LTC2943_I2C_REGS))
            {
                accessingRegisterAddress = *pSrc;
                if(dataSize > 1)
                {
                    LTC2943_I2C_REGS[accessingRegisterAddress] = *(pSrc + 1);
                }
                return true;
            }
        }
    }
    return false;
}
