#pragma once

#include <functional>
#include <stdint.h>
#include <thread>
#include <atomic>

#include "Gpio.hpp"

namespace Analog
{
    class Input : public Gpio
    {
    private:
        inline static std::vector<Input *> s_inputQueue = {};
        inline static bool s_running = true;

    public:
        explicit Input(uint gpio, uint adcIdx);
        ~Input();

        void init() override;

        static void runLoop();

        template <typename Func>
        void installCallback(Func f)
        {
            m_callback = f;
        }

    private:
        void callback(float voltage);

        std::function<void(float voltage)> m_callback;
    };
}