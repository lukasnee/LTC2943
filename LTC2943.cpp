// LTC2943 driver code

#include <iostream>

#include "i2c.hpp"
#include "LTC2943.hpp"

LTC2943::LTC2943()
{
    init();
}

LTC2943::~LTC2943()
{
    deinit();
}

bool LTC2943::init()
{
    std::cout << "ltc2943 init" << std::endl;
    return true;
}

bool LTC2943::deinit()
{
    std::cout << "ltc2943 deinit" << std::endl;
    return true;
}

