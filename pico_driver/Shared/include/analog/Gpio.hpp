#pragma once

#include <functional>
#include <vector>
#include <cstdio>
#include <map>
#include "hardware/adc.h"
#include "pico/stdlib.h"

#include "Macro.hpp"

namespace Analog
{
    class Gpio
    {
    private:
        inline static std::map<uint, bool> s_claimedPinMap{};
        inline static bool s_init = false;

    public:
        Gpio(uint gpio, uint adcIdx);
        ~Gpio();

        virtual void init();

    protected:
        uint m_gpio;
        uint m_adcIdx;
    };
}