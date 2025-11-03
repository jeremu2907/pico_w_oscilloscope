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

    float gp26volts = 0.0;
    float gp27volts = 0.0;
    float leftOverVolts = 0.0;

    Analog::Input gp27A1(27, GPIO_27_ADC);
    Analog::Input gp26A0(26, GPIO_26_ADC);

    gp26A0.installCallback(
        [&gp26volts, &gp27volts, &leftOverVolts](float voltage)
        {
            leftOverVolts = voltage;
            gp26volts = MAX_VOLTAGE - gp27volts - leftOverVolts;
            printf("%f\n", gp26volts, gp26volts + gp27volts + leftOverVolts);
        }
    );
    gp27A1.installCallback(
        [&gp26volts, &gp27volts, &leftOverVolts](float voltage)
        {
            gp27volts = MAX_VOLTAGE - voltage;
            printf("%f\n", gp27volts, gp26volts + gp27volts + leftOverVolts);
        }
    );

    MAIN_LOOP_START
    Analog::Input::runLoop();
    MAIN_LOOP_END
}
