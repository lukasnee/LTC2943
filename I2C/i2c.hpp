#ifndef I2C_HPP
#define I2C_HPP

#include <cstdint>

bool i2cInit(void);

bool i2cDeinit(void);

bool i2cIsInitialized(void);

// Read data from I2C device to pDst buffer
bool i2cRead(uint8_t address, uint8_t *pDst, uint16_t dataSize); 

// Write data from pSrc buffer to I2C device
bool i2cWrite(uint8_t address, const uint8_t *pSrc, uint16_t dataSize);

#endif //I2C_HPP