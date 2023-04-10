#include "mylib.h"

void show_start_screen(void)
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("Welcome to use", Font_11x18, White);
    ssd1306_UpdateScreen();
}

