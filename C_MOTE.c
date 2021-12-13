#include <stdio.h>

#include "pico/stdlib.h"
#include "display_routines.h"

int main()
{
    stdio_init_all();
    display_routines_init();
    return 0;
} // tp6 is bootsel