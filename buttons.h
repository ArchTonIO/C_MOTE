#ifndef PINS_H
#define PINS_H

/* buttons pins declarations */
#define BUTTON1_PIN 2
#define BUTTON2_PIN 3
#define BUTTON3_PIN 6
#define BUTTON4_PIN 7
#define BUTTON5_PIN 8
#define BUTTON6_PIN 9
#define BUTTON7_PIN 10
#define BUTTON8_PIN 11

/* buttons functions */
void buttons_init();
void buttons_update_states();
bool button_get_state(char *button_name);

#endif