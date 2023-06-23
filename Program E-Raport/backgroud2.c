#include <windows.h>
#include <conio.h>
#include <stdio.h>

#define outputHandle GetStdHandle(STD_OUTPUT_HANDLE)

#define BLACK 0
#define DARK_BLUE 1
#define DARK_GREEN 2
#define DARK_CYAN 3
#define DARK_RED 4
#define DARK_PURPLE 5
#define DARK_YELLOW 6
#define DARK_WHITE 7

#define GRAY 8
#define BLUE 9
#define GREEN 10
#define CYAN 11
#define RED 12
#define PURPLE 13
#define YELLOW 14
#define WHITE 15

int text_color = FOREGROUND_INTENSITY;
int background_color = 0;

void set_cursor_position(int x, int y)
{
    COORD position = {x, y};
    SetConsoleCursorPosition(outputHandle, position);
}

void set_text_color(int color)
{
    SetConsoleTextAttribute(outputHandle, color | (background_color << 4));
    text_color = color;
}

void set_background_color(int color)
{
    SetConsoleTextAttribute(outputHandle, text_color | (color << 4));
    background_color = color;
}

void awal()
{
    set_background_color(15);
    set_text_color(13);
    for (int x = 0; x <= 139; x++)
    {
        for (int y = 0; y <= 39; y++)
        {
            set_cursor_position(x, y);
            if (x == 0 || x == 139 || y == 0 || y == 39 || x == 35)
            {
                printf("%c", 219);
                Sleep(15);
            }
            else
            {
                printf(" ");
            }
        }
    }
    set_text_color(10);
    for (int i = 0; i <= 25; i++)
    {
        for (int x = 0; x <= 4; x++)
        {
            Sleep(1);
            set_cursor_position(5 + i, 5);
            printf("%c", 219);
            set_cursor_position(5 + i, 9);
            printf("%c", 219);
            set_cursor_position(5, 5 + x);
            printf("%c", 219);
            set_cursor_position(30, 5 + x);
            printf("%c", 219);

            set_cursor_position(5 + i, 14);
            printf("%c", 219);
            set_cursor_position(5 + i, 18);
            printf("%c", 219);
            set_cursor_position(5, 14 + x);
            printf("%c", 219);
            set_cursor_position(30, 14 + x);
            printf("%c", 219);

            set_cursor_position(5 + i, 23);
            printf("%c", 219);
            set_cursor_position(5 + i, 27);
            printf("%c", 219);
            set_cursor_position(5, 23 + x);
            printf("%c", 219);
            set_cursor_position(30, 23 + x);
            printf("%c", 219);

            set_cursor_position(5 + i, 32);
            printf("%c", 219);
            set_cursor_position(5 + i, 36);
            printf("%c", 219);
            set_cursor_position(5, 32 + x);
            printf("%c", 219);
            set_cursor_position(30, 32 + x);
            printf("%c", 219);
        }
    }
    set_cursor_position(12, 7);
    set_text_color(0);
    printf("SUCI AMANAH");
    set_cursor_position(0, 0);
}
