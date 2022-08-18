#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <dirent.h>

#define ESC 27
#define MAX_RANGE 10

//PROTOTIPADO
void hideCursor();
//void gameWindowSize(SHORT, SHORT);
void gotoXY(int, int);
void print(int, int, int, char);

/*void gameWindowSize(SHORT x, SHORT y) {
    hc = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, x, y};
    SetConsoleWindowInfo(hc, 1, &windowSize);
}*/

void hideCursor() {
    HANDLE hc;
    CONSOLE_CURSOR_INFO cci;
    hc = GetStdHandle(STD_OUTPUT_HANDLE);
    cci.dwSize = 100;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hc, &cci); 
}

/*void gotoxy(int x, int y) {
    HANDLE hc;
    COORD cordXY;
    cordXY.X = x;
    cordXY.Y = y;

    SetConsoleCursorPosition(hc, cordXY);
}*/

void gotoXY(int x, int y) {
    printf("%c[%d;%dH", ESC, y, x);
}

void print(int x, int y, int color, char c) {
    printf("%c[1;%dm", ESC, color); // color rojo (32) al caracter impreso
    gotoXY(x, y);
    printf("%c", c);
    printf("%c[0m", ESC); //reestablece el color por defecto de la consola
}

int randomNumber() {
    
    int n = 0;
    srand(time(NULL));
    //srand((unsigned) time(&t));
    n =  rand() % MAX_RANGE;
    
    return n + 1;
}