// LTC2943 driver code

#include "LTC2943_registers.hpp"

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
    return true;
}

bool LTC2943::deinit()
{
    return true;
}

