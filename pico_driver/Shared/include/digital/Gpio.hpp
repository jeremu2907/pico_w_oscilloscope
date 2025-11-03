#pragma once

#include <functional>
#include <vector>
#include <cstdio>
#include <map>
#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"

#include "Macro.hpp"

namespace Digital
{
    class Gpio
    {
    private:
        inline static std::map<uint, bool> s_claimedPinMap{};

    public:
        Gpio(uint gpio);
        ~Gpio();

        uint gpio() const;
        virtual void init();

        static void onboardLedOn();
        static void onboardLedOff();

    protected:
        uint m_gpio;
        bool m_out;
        bool m_high;
    };
}