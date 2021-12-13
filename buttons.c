/* standard includes */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* custom includes */
#include "buttons.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"

/* button constants */
#define BUTTONS_NUM 8

uint8_t BUTTONS_PINS[BUTTONS_NUM] = {
    BUTTON1_PIN,
    BUTTON2_PIN,
    BUTTON3_PIN,
    BUTTON4_PIN,
    BUTTON5_PIN,
    BUTTON6_PIN,
    BUTTON7_PIN,
    BUTTON8_PIN};

char *BUTTONS_NAMES[BUTTONS_NUM] = {
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
};

struct button
{
    char *name;
    uint8_t pin;
    bool state;
};

struct button buttons[BUTTONS_NUM];

void buttons_init()
{
    for (uint8_t i = 0; i < BUTTONS_NUM; i++)
    {

        gpio_init(BUTTONS_PINS[i]);
        gpio_set_dir(BUTTONS_PINS[i], GPIO_IN);
        gpio_pull_down(BUTTONS_PINS[i]);
        buttons[i].name = BUTTONS_NAMES[i];
        buttons[i].pin = BUTTONS_PINS[i];
        buttons[i].state = false;
    }
}

void buttons_update_states()
{
    for (uint8_t i = 0; i < BUTTONS_NUM; i++)
    {
        buttons[i].state = gpio_get(buttons[i].pin);
    }
}

bool button_get_state(char *button_name)
{
    for (uint8_t i = 0; i < BUTTONS_NUM ; i++)
    {
        if (button_name == buttons[i].name)
        {
            return buttons[i].state;
        }
    }
}