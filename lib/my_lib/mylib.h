#ifndef __MYLIB_H__
#define __MYLIB_H__

#include "main.h"
#include <ssd1306.h>

void show_start_screen(void);
void show_ready_screen(void);

void set_feed_speed(int speed);

int start_feed(void);
void start_clean(void);
int start_add_feed(void);

void stop_feed(void);

void show_buffer(uint8_t Buffer[1]);
void int_to_hex(int num,char *str);
void off_all_led();

#endif
