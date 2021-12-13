#include <stdio.h>
#include <stdint.h>

#include "joysticks.h"
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"

#define HOME_INTERVAL_MIN 2000
#define HOME_INTERVAL_MAX 2500

uint16_t A_x_value;
uint16_t A_y_value;
uint16_t B_y_value;

void joysticks_init()
{
    adc_init();
    adc_gpio_init(JOYSTICKA_X_AXIS_GPIO_PIN);
    adc_gpio_init(JOYSTICKA_Y_AXIS_GPIO_PIN);
    adc_gpio_init(JOYSTICKB_Y_AXIS_GPIO_PIN);
}

uint16_t joystickA_read_x_axis()
{
    adc_select_input(JOYSTICKA_X_AXIS_ADC_PIN);
    return adc_read();
}

uint16_t joystickA_read_y_axis()
{
    adc_select_input(JOYSTICKA_Y_AXIS_ADC_PIN);
    return adc_read();
}

uint16_t joystickB_read_y_axis()
{

    adc_select_input(JOYSTICKB_Y_AXIS_ADC_PIN);
    return adc_read();
}

int8_t joystickA_read_x_direction()
{
    A_x_value = joystickA_read_x_axis();
    if (HOME_INTERVAL_MIN < A_x_value &&
        A_x_value < HOME_INTERVAL_MAX)
    {
        return 0;
    }
    else if (A_x_value < HOME_INTERVAL_MAX)
    {
        return 1;
    }
    else if (A_x_value > HOME_INTERVAL_MIN)
    {
        return -1;
    }
}

int8_t joystickA_read_y_direction()
{
    A_y_value = joystickA_read_y_axis();
    if (HOME_INTERVAL_MIN < A_y_value &&
        A_y_value < HOME_INTERVAL_MAX)
    {
        return 0;
    }
    else if (A_y_value < HOME_INTERVAL_MAX)
    {
        return 1;
    }
    else if (A_y_value > HOME_INTERVAL_MIN)
    {
        return -1;
    }
}

int8_t joystickB_read_y_direction()
{
    B_y_value = joystickB_read_y_axis();
    if (HOME_INTERVAL_MIN < B_y_value &&
        B_y_value < HOME_INTERVAL_MAX)
    {
        return 0;
    }
    else if (B_y_value < HOME_INTERVAL_MAX)
    {
        return 1;
    }
    else if (B_y_value > HOME_INTERVAL_MIN)
    {
        return -1;
    }
}