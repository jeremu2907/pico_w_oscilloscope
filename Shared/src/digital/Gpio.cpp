#include "digital/Gpio.hpp"

using namespace Digital;

Gpio::Gpio(uint gpio) : m_gpio(gpio), m_high(false)
{
    if (s_claimedPinMap.count(gpio) > 0)
    {
        ERR_START
        printf("Error: GPIO %u already claimed!\n", gpio);
        ERR_END
    }
    init();
}

Gpio::~Gpio()
{
    s_claimedPinMap.erase(m_gpio);
}

uint Gpio::gpio() const
{
    return m_gpio;
}
void Gpio::init()
{
    s_claimedPinMap[m_gpio] = true;
    gpio_init(m_gpio);
}

void Gpio::onboardLedOn()
{
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
}

void Gpio::onboardLedOff()
{
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
}