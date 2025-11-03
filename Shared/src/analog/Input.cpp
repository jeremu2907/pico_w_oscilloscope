#include "analog/Input.hpp"

using namespace Analog;

Input::Input(uint gpio, uint adcIdx) : Gpio(gpio, adcIdx)
{
    init();
    s_inputQueue.emplace_back(this);
}

Input::~Input()
{
    s_running = false;
    s_inputQueue.clear();
}

void Input::init()
{
    Gpio::init();
}

void Input::runLoop()
{
    if(!s_running) return;
    for (auto &input : s_inputQueue)
    {
        adc_select_input(input->m_adcIdx);
        auto raw = adc_read();
        float voltage = (raw / 4095.0f) * 3.3f;
        input->callback(voltage);
        printf("%f\n", voltage);
    }
}

void Input::callback(float voltage)
{
    m_callback(voltage);
}
