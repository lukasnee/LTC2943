#include "LTC2943.hpp"
#include "i2c.hpp"

#include <iostream>

int main (int argc, char *argv[]) 
{ 
    i2cInit();
    i2cDeinit();
    i2cIsInitialized();
    const uint16_t dataSize = 512;
    uint8_t pDst[dataSize];
    i2cRead(0xA0, pDst, dataSize);
    i2cWrite(0xA0, pDst, dataSize);
    {
        LTC2943 ltc2943;
    }
    std::cin >> pDst[0];
}