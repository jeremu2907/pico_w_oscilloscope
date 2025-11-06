#include "analog/Input.hpp"
#include "digital/Gpio.hpp"
#include "Macro.hpp"

int main()
{
    if (cyw43_arch_init())
    {
        printf("Wi-Fi init failed!\n");
        return 1;
    }

    stdio_init_all();
    Digital::Gpio::onboardLedOn();

    Analog::Input gp26A0(26, GPIO_26_ADC);

    gp26A0.installCallback(
        [](float voltage)
        {
            printf("%f\n", voltage * 3.0 + ((voltage > 0.05)? 0.2 : 0.0));
        }
    );

    MAIN_LOOP_START
    Analog::Input::runLoop();
    MAIN_LOOP_END
}
