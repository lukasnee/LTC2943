// Dummy code 

#include <string>
#include <iostream>

static const std::string prefix = "called: ";
static const std::string suffix = "";

#include "i2c.hpp"

bool i2cInit(void)
{
    std::cout << prefix << "i2cInit()" << suffix << std::endl;
    return true;
}

bool i2cDeinit(void)
{
    std::cout << prefix << "i2cDeInit()" << suffix << std::endl;
    return true;
}

bool i2cIsInitialized(void)
{
    std::cout << prefix << "i2cIsInitialized()" << suffix << std::endl;
    return true;
}

// Read data from I2C device to pDst buffer
bool i2cRead(uint8_t address, uint8_t *pDst, uint16_t dataSize)
{
    std::cout << prefix << "i2cRead("\
        << "address:0x" << std::uppercase << std::hex << (uint32_t)address << ", "\
        << "pDst:0x" << std::uppercase << std::hex << reinterpret_cast<uint32_t>(pDst) << ", "\
        << "dataSize:" << dataSize \
        << ")" << suffix << std::endl;
    return true;
}

// Write data from pSrc buffer to I2C device
bool i2cWrite(uint8_t address, const uint8_t *pSrc, uint16_t dataSize) 
{
    std::cout << prefix << "i2cRead("\
        << "address:0x" << std::uppercase << std::hex << (uint32_t)address << ", "\
        << "pSrc:0x" << std::uppercase << std::hex << reinterpret_cast<uint32_t>(pSrc) << ", "\
        << "dataSize:" << dataSize \
        << ")" << suffix << std::endl;
    return true;
}
