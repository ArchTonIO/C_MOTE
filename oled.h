#ifndef OLED_H
#define OLED_H

#define height 64

void display_init(uint8_t sda, uint8_t scl);
void display_set_x_cursor(int x);
void display_set_y_cursor(int y);
void display_home_cursor();
void display_set_pixel_cursor(uint8_t x, uint8_t y);
void display_print(const char *str);
void display_draw_letter_at(uint8_t x, uint8_t y, char c);
void display_draw_bitmap(int16_t x,
                         int16_t y,
                         const uint8_t bitmap[],
                         int16_t w,
                         int16_t h, uint16_t color);
void display_draw_animation(int16_t x,
                            int16_t y,
                            const uint8_t bitmaps_array[][1024],
                            int16_t w,
                            int16_t h, uint16_t color,
                            uint8_t frames_number,
                            uint16_t duration_ms);
void display_update();
void display_clear();

#endif