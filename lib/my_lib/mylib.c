#include "mylib.h"

void show_start_screen(void)
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("Welcome", Font_11x18, White);
    ssd1306_SetCursor(0, 19);
    ssd1306_WriteString("By Stardusts", Font_11x18, White);
    ssd1306_UpdateScreen();
}

void show_ready_screen(void)
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 19);
    ssd1306_WriteString("System On", Font_11x18, White);
    ssd1306_UpdateScreen();
}

