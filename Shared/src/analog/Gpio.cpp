#include "analog/Gpio.hpp"

using namespace Analog;

Gpio::Gpio(uint gpio, uint adcIdx) : m_gpio(gpio), m_adcIdx(adcIdx)
{
    if(!s_init)
    {
        adc_init();
    }

    if(m_gpio < 26 || m_gpio > 29)
    {
        ERR_START
        printf("Error: GPIO %u must be [26, 29]\n", gpio);
        ERR_END
    }

    if (s_claimedPinMap.count(gpio) > 0)
    {
        ERR_START
        printf("Error: GPIO %u already claimed!\n", gpio);
        ERR_END
    }
    init();
}

void Gpio::init()
{
    s_claimedPinMap[m_gpio] = true;
    adc_gpio_init(m_gpio);
}