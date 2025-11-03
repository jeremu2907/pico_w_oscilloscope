#include "digital/Output.hpp"

using namespace Digital;

Output::Output(uint gpio): Gpio(gpio)
{
    init();
}

void Output::init()
{
    Gpio::init();
    gpio_set_dir(m_gpio, true);
}

void Output::setHigh()
{
    put(true);
}

void Output::setLow()
{
    put(false);
}

void Output::put(bool high)
{
    m_high = high;
    gpio_put(m_gpio, m_high);
}
