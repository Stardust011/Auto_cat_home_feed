#ifndef __MYLIB_H__
#define __MYLIB_H__

#include "main.h"
#include <ssd1306.h>

void show_start_screen(void);
void show_ready_screen(void);

int start_feed(void);
int start_add_feed(void);

void stop_feed(void);

#endif
