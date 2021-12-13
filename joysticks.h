#ifndef JOYSTICKS_H
#define JOYSTICKS_H

/* joysticks GPIO pins declaration */
#define JOYSTICKA_X_AXIS_GPIO_PIN 27
#define JOYSTICKA_Y_AXIS_GPIO_PIN 26
#define JOYSTICKB_Y_AXIS_GPIO_PIN 28

/* joysticks ADC pins declaration */
#define JOYSTICKA_X_AXIS_ADC_PIN 1
#define JOYSTICKA_Y_AXIS_ADC_PIN 0
#define JOYSTICKB_Y_AXIS_ADC_PIN 2

/* joysticks functions */
void joysticks_init();

uint16_t joystickA_read_x_axis();
uint16_t joystickA_read_y_axis();
uint16_t joystickB_read_y_axis();

int8_t joystickA_read_x_direction();
int8_t joystickA_read_y_direction();
int8_t joystickB_read_y_direction();

#endif

