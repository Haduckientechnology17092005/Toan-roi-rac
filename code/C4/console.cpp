#include <stdio.h>
#include "console.h"

int inputKey()
{
    int ch = getch();
    if (ch == ERR) {
        return key_none;
    }
    if (ch == 27) { // handle special keys
        ch = getch();
        if (ch == 91) {
            ch = getch();
            switch (ch) {
                case 65: return key_Up;
                case 66: return key_Down;
                case 67: return key_Right;
                case 68: return key_Left;
                default: return key_none;
            }
        }
    }
    return ch;
}

//-------------------------Screen-------------------------
void clrscr()
{
    clear();
    refresh();
}

//screen: goto [x,y]
void gotoXY(int column, int line)
{
    move(line, column);
    refresh();
}

//screen: get [x]
int whereX()
{
    int x, y;
    getyx(stdscr, y, x);
    return x;
}

//screen: get [y]
int whereY()
{
    int x, y;
    getyx(stdscr, y, x);
    return y;
}

void TextColor(int color)
{
    attron(COLOR_PAIR(color));
}

int main()
{
    initscr(); // start ncurses mode
    keypad(stdscr, TRUE); // enable keyboard mapping
    nodelay(stdscr, TRUE); // non-blocking input
    noecho(); // do not print input values
    start_color(); // start color functionality

    // Define color pairs
    for (int i = 0; i < 16; ++i) {
        init_pair(i, i, ColorCode_Back);
    }

    clrscr();
    gotoXY(10, 10);
    printw("Hello, World!");
    refresh();

    int ch;
    while ((ch = inputKey()) != 'q') {
        if (ch != key_none) {
            clrscr();
            gotoXY(10, 10);
            printw("Key pressed: %d", ch);
            refresh();
        }
    }

    endwin(); // end ncurses mode
    return 0;
}
