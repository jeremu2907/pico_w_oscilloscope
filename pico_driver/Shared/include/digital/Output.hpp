#pragma once

#include "pico/stdlib.h"
#include <functional>

#include "Gpio.hpp"

namespace Digital
{
    class Output : public Gpio
    {
    public:
        explicit Output(uint gpio);
        ~Output() = default;

        void setHigh();
        void setLow();

    private:
        void init() override;
        void put(bool high);
    };
}