#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "oled.h"
#include "bitmaps.h"
#include "buttons.h"
#include "joysticks.h"

void display_routines_init()
{
    display_init(4, 5);
    joysticks_init();
    buttons_init();
    const uint8_t x_displacement = 92;
    const uint8_t y_displacement = 14;
    int8_t x;
    int8_t y;
    while (1)
    {
        x = joystickA_read_x_direction();
        y = joystickA_read_y_direction();
        buttons_update_states();
        if (x == 0 && y == 0)
        {
            display_draw_bitmap(x_displacement, y_displacement, center, 36, 36, 1);
            display_update();
        }
        if (x == 1 && y == 0)
        {
            display_draw_bitmap(x_displacement, y_displacement, right, 36, 36, 1);
            display_update();
        }
        if (x == 0 && y == 1)
        {
            display_draw_bitmap(x_displacement, y_displacement, up, 36, 36, 1);
            display_update();
        }
        if (x == -1 && y == 0)
        {
            display_draw_bitmap(x_displacement, y_displacement, left, 36, 36, 1);
            display_update();
        }
        if (x == 0 && y == -1)
        {
            display_draw_bitmap(x_displacement, y_displacement, down, 36, 36, 1);
            display_update();
        }
        if (x == 1 && y == 1)
        {
            display_draw_bitmap(x_displacement, y_displacement, upper_right, 36, 36, 1);
            display_update();
        }
        if (x == -1 && y == 1)
        {
            display_draw_bitmap(x_displacement, y_displacement, upper_left, 36, 36, 1);
            display_update();
        }
        if (x == -1 && y == -1)
        {
            display_draw_bitmap(x_displacement, y_displacement, lower_left, 36, 36, 1);
            display_update();
        }
        if (x == 1 && y == -1)
        {
            display_draw_bitmap(x_displacement, y_displacement, lower_right, 36, 36, 1);
            display_update();
        }
        if (button_get_state("A") == false)
        {
            display_clear();
            display_draw_bitmap(116, 52, button_empty, 12, 12, 1);
        }
        else
        {
            display_draw_bitmap(116, 52, button_full, 12, 12, 1);
        }
    }
}