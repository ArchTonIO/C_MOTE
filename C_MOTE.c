#include <stdio.h>
#include "pico/stdlib.h"
#include "oled.h"

int main()
{
    stdio_init_all();
    display_init(4, 5);
    display_clear();
    display_print("BELLA LI, GUARDA QUI\nCOSA CAZZO FAI");
    display_update();
    return 0;
}