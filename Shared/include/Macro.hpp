#pragma once

#define ERR_START while (true) { sleep_ms(1000);
#define ERR_END tight_loop_contents(); }

#define MAIN_LOOP_START while (true) {
#define MAIN_LOOP_END }

#define GPIO_26_ADC 0
#define GPIO_27_ADC 1
#define GPIO_28_ADC 2

#define MAX_VOLTAGE 3.3
#define MID_VOLTAGE 3.3 / 2
#define MID_VOLTAGE_HI MID_VOLTAGE + 0.3
#define MID_VOLTAGE_LO MID_VOLTAGE - 0.3