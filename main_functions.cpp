#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <cwchar>
#include <thread>
#include <string>
#include <conio.h>
#include <fcntl.h>
#include <io.h>
#include <condition_variable>
#include <mutex>
#include <io.h>
#include <fstream>
#include <ctime>
#include "main_functions.h"
#include "boss.h"
#include "levels.h"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#define MAX_SIZE_SNAKE 32
#define MAX_SIZE_FOOD 32
#define MAX_SPEED 50
using namespace std;

unsigned char vborder = 205, hborder = 186, lowerleft = 200, lowerright = 188, upperleft = 201, upperright = 187;
int a = rand() % (WIDTH_CONSOLE - 4) + 4;
int b = rand() % (HEIGHT_CONSOLE - 4) + 4;
extern int levelscore[];

void drawSlogan()
{
    unsigned char ngangtren = 220, caotrai = 221, caophai = 222, ngangduoi = 223, ngang = 219;
    int x = 20, y = 0;
    Sleep(400);
    //In chu S
    for (int i = 0; i < 11; i++)
    {
        GotoXY(x + i - 3, y); cout << ngangtren;
    }
    for (int i = 0; i < 3; i++)
    {
        GotoXY(x - 3, y + 1 + i); cout << ngang;
    }
    for (int i = 0; i < 10; i++)
    {
        GotoXY(x - 3 + i, y + 4); cout << ngangduoi;
    }
    for (int i = 0; i < 4; i++)
    {
        GotoXY(x + 7, y + 4 + i); cout << ngang;
    }
    for (int i = 0; i < 10; i++)
    {
        GotoXY(x - 3 + i, y + 7); cout << ngangtren;
    }
    //In chu N
    Sleep(400);
    for (int i = y + 1; i < y + 8; i++)
    {
        GotoXY(x + 15, i); cout << ngang;
    }
    GotoXY(x + 15, y); cout << ngangtren;
    for (int i = 0; i < 6; i++)
    {
        GotoXY(x + 16 + 2 * i, y + i); cout << ngangtren;
        GotoXY(x + 16 + 2 * i, y + 1 + i); cout << ngangduoi;
        GotoXY(x + 17 + 2 * i, y + 1 + i); cout << ngang;
    }
    GotoXY(x + 28, y); cout << ngangtren;
    for (int i = 0; i < 7; i++)
    {
        GotoXY(x + 28, y + i + 1); cout << ngang;
    }
    //In chu A
    Sleep(400);
    for (int i = 0; i < 9; i++)
    {
        GotoXY(x + 37 + i, y); cout << ngangtren;
    }
    for (int i = 0; i < 7; i++)
    {
        GotoXY(x + 36, y + 1 + i); cout << ngang;
        GotoXY(x + 46, y + 1 + i); cout << ngang;
    }
    for (int i = 0; i < 9; i++)
    {
        GotoXY(x + 37 + i, y + 4); cout << ngangduoi;
    }
    //In chu K
    Sleep(400);
    GotoXY(x + 54, y); cout << ngangtren;
    for (int i = 0; i < 7; i++)
    {
        GotoXY(x + 54, y + 1 + i); cout << ngang;
    }
    GotoXY(x + 55, y + 4); cout << ngangduoi;

    GotoXY(x + 56, y + 4); cout << ngangtren;
    GotoXY(x + 56, y + 3); cout << ngangtren;
    GotoXY(x + 57, y + 5); cout << ngangduoi;
    GotoXY(x + 57, y + 3); cout << ngangduoi;
    GotoXY(x + 58, y + 5); cout << ngangtren;
    GotoXY(x + 58, y + 2); cout << ngangtren;
    GotoXY(x + 59, y + 6); cout << ngangduoi;
    GotoXY(x + 59, y + 2); cout << ngangduoi;
    GotoXY(x + 60, y + 6); cout << ngangtren;
    GotoXY(x + 60, y + 1); cout << ngangtren;
    GotoXY(x + 61, y + 7); cout << ngangduoi;
    GotoXY(x + 61, y + 1); cout << ngangduoi;
    GotoXY(x + 62, y + 7); cout << ngangtren;
    GotoXY(x + 62, y); cout << ngangtren;
    //In chu E
    Sleep(400);
    for (int i = 0; i < 10; i++)
    {
        GotoXY(x + 70 + i, y); cout << ngangtren;
        GotoXY(x + 70 + i, y + 7); cout << ngangtren;
    }
    for (int i = 0; i < 9; i++)
    {
        GotoXY(x + 71 + i, y + 4); cout << ngangduoi;
    }
    for (int i = 0; i < 7; i++)
    {
        GotoXY(x + 70, y + 1 + i); cout << ngang;
    }
    //In chu G
    Sleep(400);
    for (int i = 0; i < 9; i++)
    {
        GotoXY(x - 2 + i, y + 11); cout << ngangtren;
        GotoXY(x - 2 + i, y + 18); cout << ngangduoi;
    }
    for (int i = 0; i < 6; i++)
    {
        GotoXY(x - 3, y + 12 + i); cout << ngang;
    }
    GotoXY(x + 7, y + 12); cout << ngangduoi;
    for (int i = 0; i < 2; i++)
    {
        GotoXY(x + 7, y + 16 + i); cout << ngang;
    }
    for (int i = 0; i < 2; i++)
    {
        GotoXY(x + 5 + i, y + 16); cout << ngangduoi;
        GotoXY(x + 8 + i, y + 16); cout << ngangduoi;
    }
    //In chu A
    for (int i = 0; i < 9; i++)
    {
        GotoXY(x + 18 + i, y + 11); cout << ngangtren;
    }
    for (int i = 0; i < 6; i++)
    {
        GotoXY(x + 17, y + 12 + i); cout << ngang;
        GotoXY(x + 27, y + 12 + i); cout << ngang;
    }
    GotoXY(x + 17, y + 18); cout << ngangduoi;
    GotoXY(x + 27, y + 18); cout << ngangduoi;
    for (int i = 0; i < 9; i++)
    {
        GotoXY(x + 18 + i, y + 15); cout << ngangduoi;
    }
    //In chu M
    GotoXY(x + 35, y + 18); cout << ngangduoi;
    for (int i = 0; i < 6; i++)
    {
        GotoXY(x + 35, y + 12 + i); cout << ngang;
    }
    GotoXY(x + 35, y + 11); cout << ngangtren;

    for (int i = 0; i < 7; i++)
    {
        GotoXY(x + 36 + 2 * i, y + 11 + i); cout << ngangtren;
        GotoXY(x + 37 + 2 * i, y + 12 + i); cout << ngangduoi;
    }
    for (int i = 0; i < 7; i++)
    {
        GotoXY(x + 50 + 2 * i, y + 18 - i); cout << ngangduoi;
        GotoXY(x + 51 + 2 * i, y + 17 - i); cout << ngangtren;
    }
    GotoXY(x + 64, y + 11); cout << ngangtren;
    for (int i = 0; i < 6; i++)
    {
        GotoXY(x + 64, y + 12 + i); cout << ngang;
    }
    GotoXY(x + 64, y + 18); cout << ngangduoi;
    //In chu E
    for (int i = 0; i < 10; i++)
    {
        GotoXY(x + 70 + i, y + 11); cout << ngangtren;
        GotoXY(x + 70 + i, y + 18); cout << ngangduoi;
    }
    for (int i = 0; i < 6; i++)
    {
        GotoXY(x + 70, y + 12 + i); cout << ngang;
    }
    for (int i = 0; i < 9; i++)
    {
        GotoXY(x + 71 + i, y + 15); cout << ngangduoi;
    }
}

void deadAnimation() {
    int flag = 1;
    GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
    printf("%c", ' ');
    for (int i = 0; i < SIZE_SNAKE; i++) {
        GotoXY(snake[i].x, snake[i].y);
        if (flag % 2 != 0) {
            printf("%c ", '*');
        }
        else if (flag % 2 == 0) {
            printf(" %c", '.');
        }
        for (double x = 0; x < 100000000; x++);
        flag++;

    }
    for (double x = 0; x < 1000000000; x++);
}

//Hàm đổi cỡ chữ
void doiCoChu()
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 24;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}



void drawMenu()
{
    unsigned char vborder = 205, hborder = 186, lowerleft = 200, lowerright = 188, upperleft = 201, upperright = 187;
    GotoXY(17 + 25, 19);
    for (int i = 0; i < 26; i++)
        cout << vborder;
    GotoXY(16 + 25, 19); cout << upperleft;
    GotoXY(16 + 25, 20); cout << hborder;
    GotoXY(16 + 25, 21); cout << hborder;
    GotoXY(16 + 25, 22); cout << hborder;
    GotoXY(16 + 25, 23); cout << hborder;
    GotoXY(16 + 25, 24); cout << hborder;
    GotoXY(16 + 25, 25); cout << hborder;
    GotoXY(16 + 25, 26); cout << lowerleft;
    GotoXY(17 + 25, 26);
    for (int i = 0; i < 26; i++)
        cout << vborder;
    GotoXY(16 + 27 + 25, 19); cout << upperright;
    GotoXY(16 + 27 + 25, 20); cout << hborder;
    GotoXY(16 + 27 + 25, 21); cout << hborder;
    GotoXY(16 + 27 + 25, 22); cout << hborder;
    GotoXY(16 + 27 + 25, 23); cout << hborder;
    GotoXY(16 + 27 + 25, 24); cout << hborder;
    GotoXY(16 + 27 + 25, 25); cout << hborder;
    GotoXY(16 + 27 + 25, 26); cout << lowerright;
}

void drawblahblah()
{
    system("cls");
    for (;;)
    {
        doiCoChu();

        GotoXY(25, 8); cout << "\b\b\b\b\b\b\b\b\b\bLoading   " << flush;
        Sleep(50);
        cout << "\b\b\b\b\b\b\b\b\b\bLOading   " << flush;
        Sleep(50);
        cout << "\b\b\b\b\b\b\b\b\b\bLoAding   " << flush;
        Sleep(50);
        cout << "\b\b\b\b\b\b\b\b\b\bLoaDing   " << flush;
        Sleep(50);
        cout << "\b\b\b\b\b\b\b\b\b\bLoadIng   " << flush;
        Sleep(50);
        cout << "\b\b\b\b\b\b\b\b\b\bLoadiNg   " << flush;
        Sleep(50);
        cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " << flush;
        Sleep(50);
        cout << "\b\b\b\b\b\b\b\b\b\bLoading.  " << flush;
        Sleep(50);
        cout << "\b\b\b\b\b\b\b\b\b\bLoading.." << flush;
        Sleep(50);
        cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << flush;
        Sleep(50);
        system("cls");
        GotoXY(25, 8); for (int r = 1; r <= 20; r++)
        {
            for (int q = 0; q <= 100000000; q++);
            printf("%c", 177);
        }
        system("cls");
        GotoXY(26, 8); cout << "PRESS ANY KEY TO CONTINUE";
        cin.get();
        system("cls");
        break;
    }
}

void DeleteScrollBar()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
    GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);

    short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
    short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

    short scrBufferWidth = scrBufferInfo.dwSize.X;
    short scrBufferHeight = scrBufferInfo.dwSize.Y;

    COORD newSize;
    newSize.X = scrBufferWidth;
    newSize.Y = winHeight;

    int Status = SetConsoleScreenBufferSize(hOut, newSize);

    GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);
}

void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

int foodRandomizer()
{
    srand(time(NULL));
    return rand() % 10 + 1;
}

void GotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void FixConsoleWindow()
{
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}


void textAnima(char* x) {
    for (int i = 0; x[i] != '\0'; i++) {
        for (double k = 0; k < 20000000; k++);
        printf("%c", x[i]);
    }
}


bool IsValid(int x, int y) {
    for (int i = 0; i < SIZE_SNAKE; i++) {
        if (snake[i].x == x && snake[i].y == y) {
            return false;
        }
    }
    return true;
}


void GenerateFood() {
    int x, y;
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE_FOOD; i++) {
        do {
            x = rand() % (WIDTH_CONSOLE - 1) + 1;
            y = rand() % (HEIGHT_CONSOLE - 1) + 1;
        } while (IsValid(x, y) == false);
        food[i] = { x,y };
    }
}

void GenerateFoodType()
{
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE_FOOD; i++)
    {
        foodtype[i] = rand() % 5 + 1;
    }
}

void ResetData()
{
    CHAR_LOCK = 'A', MOVING = 'D', SPEED = 12; FOOD_INDEX = 8, WIDTH_CONSOLE = 80, HEIGHT_CONSOLE = 20, SIZE_SNAKE = 8, foodcount = 8, score = 0;
    snake[0] = { 10, 5 }; snake[1] = { 11, 5 };
    snake[2] = { 12, 5 }; snake[3] = { 13, 5 };
    snake[4] = { 14, 5 }; snake[5] = { 15, 5 };
    snake[6] = { 16, 5 }; snake[7] = { 17, 5 };
    snake[8] = { 18, 5 };
    GenerateFood();
    GenerateFoodType();
}

void DrawBoard(int x, int y, int width, int height)
{
    int curPosX = 0, curPosY = 0;
    /*
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 11);
    */
    cout << CYAN;
    GotoXY(x, y); cout << upperleft;
    for (int i = 1; i < width; i++)
    {
        cout << vborder;
    }
    cout << upperright;
    GotoXY(x, height + y); cout << lowerleft;
    for (int i = 1; i < width; i++)
    {
        cout << vborder;
    }
    cout << lowerright;
    for (int i = y + 1; i < height + y; i++)
    {
        GotoXY(x, i); cout << hborder;
        GotoXY(x + width, i); cout << hborder;
    }
    GotoXY(curPosX, curPosY);

    {
        GotoXY(82, 0); cout << upperleft;
        for (int i = 83; i < 94; i++)
        {
            GotoXY(i, 0); cout << vborder;
        }
        GotoXY(94, 0); cout << upperright;
        for (int i = 1; i < 20; i++)
        {
            GotoXY(94, i); cout << hborder;
        }
        GotoXY(94, 20); cout << lowerright;
        for (int i = 83; i < 94; i++)
        {
            GotoXY(i, 20); cout << vborder;
        }
        GotoXY(82, 20); cout << lowerleft;
        for (int i = 1; i < 20; i++)
        {
            GotoXY(82, i); cout << hborder;
        }


        GotoXY(0, 21); cout << upperleft;
        for (int i = 1; i < 94; i++)
        {
            GotoXY(i, 21); cout << vborder;
            GotoXY(i, 26); cout << vborder;
        }
        GotoXY(94, 21); cout << upperright;
        for (int i = 22; i < 26; i++)
        {
            GotoXY(94, i); cout << hborder;
            GotoXY(0, i); cout << hborder;
        }
        GotoXY(0, 26); cout << lowerleft;
        GotoXY(94, 26); cout << lowerright;
    }

    GotoXY(85, 10);
    cout << "Score:";
    GotoXY(85, 12);
    cout << "Level:";
    GotoXY(85, 14);
    cout << "Energy";
    GotoXY(85, 15);
    cout << upperleft;
    for (int i = 86; i < 91; i++)
    {
        cout << vborder;
    }
    cout << upperright;
    GotoXY(85, 16);
    cout << hborder;
    GotoXY(91, 16);
    cout << hborder;
    GotoXY(85, 17);
    cout << lowerleft;
    for (int i = 86; i < 91; i++)
    {
        cout << vborder;
    }
    cout << lowerright;
}

void draws()
{
    GotoXY(87, 5);
    cout << upperleft;
    cout << vborder;
    cout << upperright;
    GotoXY(87, 6);
    cout << hborder;
    cout << "S";
    cout << hborder;
    GotoXY(87, 7); cout << lowerleft;
    cout << vborder;
    cout << lowerright;

}
void drawa()
{
    GotoXY(83, 5);
    cout << upperleft;
    cout << vborder;
    cout << upperright;
    GotoXY(83, 6);
    cout << hborder;
    cout << "A";
    cout << hborder;
    GotoXY(83, 7); cout << lowerleft;
    cout << vborder;
    cout << lowerright;

}
void draww()
{
    GotoXY(87, 1);
    cout << upperleft;
    cout << vborder;
    cout << upperright;
    GotoXY(87, 2); cout << hborder;
    cout << "W";
    cout << hborder;
    GotoXY(87, 3); cout << lowerleft;
    cout << vborder;
    cout << lowerright;
}
void drawd()
{
    GotoXY(91, 5);
    cout << upperleft;
    cout << vborder;
    cout << upperright;
    GotoXY(91, 6);
    cout << hborder;
    cout << "D";
    cout << hborder;
    GotoXY(91, 7); cout << lowerleft;
    cout << vborder;
    cout << lowerright;
    return;
}

void StartGame()
{
    level = 1;
    system("CLS");
    DrawBlankSpace(" ");
    ResetData();
    DrawBoard(0, 0, WIDTH_CONSOLE, HEIGHT_CONSOLE);
    STATE = 1;
}

void ExitGame(HANDLE t)
{
    system("CLS");
    DrawBlankSpace(" ");
    TerminateThread(t, 1);
}

void SaveGame(string file) { // Phan Nay co chinh nha
    ofstream myFile;
    myFile.open(file, ios::out);
    if (myFile.is_open()) {
        myFile << SIZE_SNAKE;
        myFile << " ";
        for (int i = 0; i < SIZE_SNAKE; i++) {
            myFile << snake[i].x;
            myFile << " ";
            myFile << snake[i].y;
            myFile << " ";
        }
        myFile << level;
        myFile << " ";
        myFile << score;
        myFile << " ";
        myFile << FOOD_INDEX;
        myFile << " ";
        myFile << food[FOOD_INDEX].x;
        myFile << " ";
        myFile << food[FOOD_INDEX].y;
        myFile << " ";
        myFile << foodcount;
        myFile << " ";
        myFile << foodtype[FOOD_INDEX];
        myFile << " ";
        myFile << SPEED;
        myFile << endl;
        myFile.close();
    }
    else
    {
        myFile.close();
        cout << "ERORR 404" << endl;
    }

}
void PauseGame(HANDLE t)
{
    SuspendThread(t);
}

void Eat() {
    snake[SIZE_SNAKE] = food[FOOD_INDEX];
    int temp = foodRandomizer();
    if ((foodtype[FOOD_INDEX] == 5 && level != 999) || (temp == 10 && level == 999))
    {
        score += 20;
    }
    else
    {
        score += 10;
    }
    if (FOOD_INDEX == MAX_SIZE_FOOD - 1)
    {
        PlaySound("Evolution", NULL, SND_ASYNC);
        FOOD_INDEX = 8;
        foodcount = 8;
        SIZE_SNAKE = 8;
        if (SPEED == MAX_SPEED) SPEED = 1;
        GenerateFood();
        GenerateFoodType();
    }
    else {
        PlaySound("Chewing", NULL, SND_ASYNC);
        foodcount++;
        FOOD_INDEX++;
        SIZE_SNAKE++;
        SPEED++;
    }
}

void ProcessDead() {
    STATE = 0;
    PlaySound("death", NULL, SND_ASYNC); // chạy phần âm thanh 
    deadAnimation();// Chạy hiệu hứng chết của rắn 
    system("CLS");
    if (level != 999)
    {
        GotoXY(WIDTH_CONSOLE / 4 + 14, HEIGHT_CONSOLE / 2);
        char str[] = "You Died";
        char str2[] = "Press Y to restart or press any keys to exit";
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 4);
        textAnima(str);
        SetConsoleTextAttribute(h, 15);
        GotoXY(WIDTH_CONSOLE / 4, HEIGHT_CONSOLE / 2 - 3);
        textAnima(str2);
    }
    else
    {
        GotoXY(WIDTH_CONSOLE / 4 + 14, HEIGHT_CONSOLE / 2);
        char str[] = "YOU HAVE COMPLETED THE GAME!";
        char str2[] = "Press Y to restart or press any keys to exit";
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 4);
        textAnima(str);
        SetConsoleTextAttribute(h, 15);
        GotoXY(WIDTH_CONSOLE / 4, HEIGHT_CONSOLE / 2 - 3);
        textAnima(str2);
    }

}

void Touch()
{
    for (int i = 0; i < SIZE_SNAKE - 2; i++)
    {
        if (snake[SIZE_SNAKE - 1].x == snake[i].x && snake[SIZE_SNAKE - 1].y == snake[i].y)
        {
            ProcessDead();
            break;
        }
    }
}

void drawmoving()
{
    cout << CYAN;
    drawa();
    draww();
    draws();
    drawd();
    if (MOVING == 'A')
    {
        cout << YELLOW;
        drawa();
        return;
    }
    if (MOVING == 'S')
    {
        cout << YELLOW;
        draws();
        return;
    }
    if (MOVING == 'D')
    {
        cout << YELLOW;
        drawd();
        return;
    }
    if (MOVING == 'W')
    {
        cout << YELLOW;
        draww();
        return;
    }
}

void DrawSnakeAndFood()
{
    if (foodtype[FOOD_INDEX] == 5)
    {
        cout << BLUE;
    }
    else
    {
        cout << YELLOW;
    }
    if (score < 50)
    {
        GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
        printf("%c", SNAKE_STRUCTURE[foodcount]);
    }
    cout << GREEN;

    for (int i = 0; i < SIZE_SNAKE - 1; i++)
    {
        GotoXY(snake[i].x, snake[i].y);
        printf("%c", SNAKE_STRUCTURE[i]);
    }

    cout << RED;
    GotoXY(snake[SIZE_SNAKE - 1].x, snake[SIZE_SNAKE - 1].y);
    printf("%c", SNAKE_STRUCTURE[SIZE_SNAKE - 1]);

    drawmoving();

    if (score >= levelscore[level  - 1] && level != 999)
    {
        drawgate(a, b);
        //drawgate(0, HEIGHT_CONSOLE / 2 - 1);
    }

    GotoXY(91, 10);
    cout << score;
    GotoXY(91, 12);
    cout << level;
    int i = 0;
    int s = score / 10;
    while (i <= score / 10 && i < 6)
    {

        if (i != 0)
        {
            GotoXY(85 + i, 16);

            cout << char(219);
        }
        i++;



    }
}

void DrawBlankSpace(const char* str)
{
    GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
    printf(str);
    for (int i = 0; i < SIZE_SNAKE; i++)
    {
        GotoXY(snake[i].x, snake[i].y);
        printf(str);
    }
}


void MoveRight()
{
    if (snake[SIZE_SNAKE - 1].x + 1 == WIDTH_CONSOLE)
    {
        if (level != 1)
        {
            ProcessDead();
        }
        else
        {
            for (int i = 0; i < SIZE_SNAKE - 1; i++)
            {
                snake[i].x = snake[i + 1].x;
                snake[i].y = snake[i + 1].y;
            }
            snake[SIZE_SNAKE - 1].x = 1;
        }
    }
    else
    {
        //if (snake[SIZE_SNAKE - 1].x + 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y)
        if (level == 1)
        {
            if (score <= levelscore[level - 1])
            {
                if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y)
                {
                    Eat();
                }
                else if (snake[SIZE_SNAKE - 1].x + 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y && snake[SIZE_SNAKE - 1].x + 2 == WIDTH_CONSOLE && level == 1)
                {
                    Eat();
                    for (int i = 0; i < SIZE_SNAKE - 1; i++)
                    {
                        snake[i].x = snake[i + 1].x;
                        snake[i].y = snake[i + 1].y;
                    }
                    snake[SIZE_SNAKE - 1].x = 1;
                }
            }
        }
        else
        {
            if (score <= levelscore[level - 1] || level == 999)
            {
                if (snake[SIZE_SNAKE - 1].x + 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y)
                    Eat();
            }
        }
        for (int i = 0; i < SIZE_SNAKE - 1; i++)
        {
            snake[i].x = snake[i + 1].x;
            snake[i].y = snake[i + 1].y;
        }
        snake[SIZE_SNAKE - 1].x++;
    }
}

void MoveLeft()
{
    if (snake[SIZE_SNAKE - 1].x - 1 == 0)
    {
        if (level != 1)
        {
            ProcessDead();
        }
        else
        {
            for (int i = 0; i < SIZE_SNAKE - 1; i++)
            {
                snake[i].x = snake[i + 1].x;
                snake[i].y = snake[i + 1].y;
            }
            snake[SIZE_SNAKE - 1].x = WIDTH_CONSOLE - 1;
        }
    }
    else
    {
        //if (snake[SIZE_SNAKE - 1].x - 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y)
        if (level != 1)
        {
            if (score <= levelscore[level - 1] || level == 999)
            {
                if (snake[SIZE_SNAKE - 1].x - 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y)
                {
                    Eat();
                }
            }
        }

        //if (snake[SIZE_SNAKE - 1].x - 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y)
        else
        {
            if (score <= levelscore[level - 1])
            {
                if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y)
                {
                    Eat();
                }
                else if (snake[SIZE_SNAKE - 1].x - 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y && snake[SIZE_SNAKE - 1].x - 2 == 0 && level == 1)
                {
                    Eat();
                    for (int i = 0; i < SIZE_SNAKE - 1; i++)
                    {
                        snake[i].x = snake[i + 1].x;
                        snake[i].y = snake[i + 1].y;
                    }
                    snake[SIZE_SNAKE - 1].x = WIDTH_CONSOLE - 1;
                }
            }

        }

        for (int i = 0; i < SIZE_SNAKE - 1; i++)
        {
            snake[i].x = snake[i + 1].x;
            snake[i].y = snake[i + 1].y;
        }
        snake[SIZE_SNAKE - 1].x--;
    }
}

void MoveDown()
{
    if (snake[SIZE_SNAKE - 1].y + 1 == HEIGHT_CONSOLE) {

        if (level != 1)
        {
            ProcessDead();
        }
        else
        {
            for (int i = 0; i < SIZE_SNAKE - 1; i++)
            {
                snake[i].x = snake[i + 1].x;
                snake[i].y = snake[i + 1].y;
            }
            snake[SIZE_SNAKE - 1].y = 1;
        }
    }
    else
    {
        //if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y + 1 == food[FOOD_INDEX].y) {
        if (level != 1)
        {
            if (score <= levelscore[level - 1] || level == 999)
            {
                if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y + 1 == food[FOOD_INDEX].y)
                {
                    Eat();
                }
            }

        }
        //if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y + 1 == food[FOOD_INDEX].y) {
        else
        {
            if (score <= levelscore[level - 1])
            {
                if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y) {
                    Eat();
                }
                else if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y + 1 == food[FOOD_INDEX].y && snake[SIZE_SNAKE - 1].y + 2 == HEIGHT_CONSOLE && level == 1)
                {
                    Eat();
                    for (int i = 0; i < SIZE_SNAKE - 1; i++)
                    {
                        snake[i].x = snake[i + 1].x;
                        snake[i].y = snake[i + 1].y;
                    }
                    snake[SIZE_SNAKE - 1].y = 1;
                }
            }
        }

        for (int i = 0; i < SIZE_SNAKE - 1; i++) {
            snake[i].x = snake[i + 1].x;
            snake[i].y = snake[i + 1].y;
        }
        snake[SIZE_SNAKE - 1].y++;
    }
}

void MoveUp()
{
    if (snake[SIZE_SNAKE - 1].y - 1 == 0)
    {
        if (level != 1)
        {
            ProcessDead();
        }
        else
        {
            for (int i = 0; i < SIZE_SNAKE - 1; i++)
            {
                snake[i].x = snake[i + 1].x;
                snake[i].y = snake[i + 1].y;
            }
            snake[SIZE_SNAKE - 1].y = HEIGHT_CONSOLE - 1;
        }
    }
    else
    {
        //if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y - 1 == food[FOOD_INDEX].y)
        if (level != 1)
        {
            if (score <= levelscore[level - 1] || level == 999)
            {
                if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y - 1 == food[FOOD_INDEX].y)
                {
                    Eat();
                }
            }
        }
        else
        {
            if (score <= levelscore[level - 1])
            {
                if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y)
                {
                    Eat();
                }
                else if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y - 1 == food[FOOD_INDEX].y && snake[SIZE_SNAKE - 1].y - 2 == 0 && level == 1)
                {
                    Eat();
                    for (int i = 0; i < SIZE_SNAKE - 1; i++)
                    {
                        snake[i].x = snake[i + 1].x;
                        snake[i].y = snake[i + 1].y;
                    }
                    snake[SIZE_SNAKE - 1].y = HEIGHT_CONSOLE - 1;
                }
            }

        }

        for (int i = 0; i < SIZE_SNAKE - 1; i++)
        {
            snake[i].x = snake[i + 1].x;
            snake[i].y = snake[i + 1].y;
        }
        snake[SIZE_SNAKE - 1].y--;
    }
}

void drawBonus(const char* str)
{
    if (foodtype[FOOD_INDEX] == 5)
    {
        cout << BLUE;
    }
    else
    {
        cout << YELLOW;
    }
    if (score < 50)
    {
        GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
        printf(str);
    }
    char head = 35, left = 60, right = 62;
    cout << RESET;

    for (int i = 0; i < SIZE_SNAKE - 1; i++)
    {
        if (i % 2 == 0)
        {
            GotoXY(snake[i].x, snake[i].y);
            printf("%c", left);
        }

        else
        {
            GotoXY(snake[i].x, snake[i].y);
            printf("%c", right);
        }
    }

    cout << YELLOW;
    GotoXY(snake[SIZE_SNAKE - 1].x, snake[SIZE_SNAKE - 1].y);
    printf("%c", head);

    drawmoving();
    GotoXY(91, 10);
    cout << score;
    GotoXY(91, 12);
    if (level != 999) cout << level;
    else cout << "BONUS!";

    if (score >= levelscore[level - 1] && level != 999)
    {
        drawgate(a, b);
    }
}

void ThreadFunc()
{
    while (1)
    {
        if (score >= levelscore[level - 1] && level != 999)
        {
            touchgate(a, b);
            passlevel(a, b);
        }
        if (level == 2) touchappear();
        if (level == 3) touchimpediment();
        if (level == 4) touchu();
        if (level == 5) touchktlt();
        if (STATE != 0)
        {
            Touch();
        }
        if (STATE == 1)
        {
            DrawBlankSpace(" ");
            switch (MOVING)
            {
            case 'A':
                MoveLeft();
                break;
            case 'D':
                MoveRight();
                break;
            case 'W':
                MoveUp();
                break;
            case 'S':
                MoveDown();
                break;
            }
        }
        if (level == 2 && STATE != 0)
        {
            drawappear();
        }
        if (level == 3 && STATE != 0)
        {
            drawimpediment();
        }
        if (level == 4 && STATE != 0)
        {
            drawu();
        }
        if (level == 5 && STATE != 0)
        {
            drawktlt();
        }
        if (STATE != 0 && level != 999)
        {
            DrawSnakeAndFood();
        }
        else if (STATE != 0 && level == 999)
        {
            drawBonus("0");
        }
        this_thread::sleep_for(chrono::microseconds(1));
        Sleep(900 / SPEED);
    }

}

void LoadingGame()
{
    system("CLS");
    DrawBlankSpace(" ");
    level = 1;
    SPEED = 8; FOOD_INDEX = 8, WIDTH_CONSOLE = 80, HEIGHT_CONSOLE = 20, SIZE_SNAKE = 8, foodcount = 8;
    score = 0;
    DrawBoard(0, 0, WIDTH_CONSOLE, HEIGHT_CONSOLE);
    GenerateFood();
    STATE = 1;
}


int LoadGame(string file)
{
    fstream myFile;
    myFile.open(file, ios::in);
    if (myFile.is_open()) {
        int Num = 0;
        int DoDai = 0;
        int Disk = 0;
        int Cot = -1;
        while (myFile >> Disk) {
            if (Cot == -1) {
                SIZE_SNAKE = Disk;
                Num = SIZE_SNAKE * 2 + 7;
                Cot++;
                continue;
            }
            else if (Cot == Num) {
                SPEED = Disk;
            }
            else if (Cot == Num - 1) {
                foodtype[FOOD_INDEX] = Disk;
            }
            else if (Cot == Num - 2) {
                foodcount = Disk;
            }
            else if (Cot == Num - 3) {
                food[FOOD_INDEX].y = Disk;
            }
            else if (Cot == Num - 4) {
                food[FOOD_INDEX].x = Disk;
            }
            else if (Cot == Num - 5) {
                FOOD_INDEX = Disk;
            }
            else if (Cot == Num - 6) {
                score = Disk;
            }
            else if (Cot == Num - 7) {
                level = Disk;
            }
            else if (Cot == 0 || Cot % 2 == 0) {
                snake[DoDai].x = Disk;

            }
            else {
                snake[DoDai].y = Disk;
                DoDai++;
            }
            Cot++;
        }
        myFile.close();
        return 0;
    }
    else
    {
        myFile.close();
        GotoXY(25, 9);
        cout << "Khong ton tai file tren" << endl;
        GotoXY(2, 19);
        system("PAUSE");
        return -1;
    }
}

void CreateUser(string& file)
{
    GotoXY(0, 28);
    string x;
    int i = 0;
    do {
        if (i == 0) {
            cout << "Nhap ten ? ";
            cout << endl;
            getline(cin, x);
            string t = ".txt";
            file = x + t;
            i++;
        }
        else {
            cout << "Ten tren da ton tai moi nhap lai ? " << endl;
            getline(cin, x);
            string t = ".txt";
            file = x + t;
        }
    } while (checkDuplicate(file));
    string List = "List.txt";
    fstream myList;
    myList.open(List, ios::app);
    myList << " ";
    myList << file;
    myList.close();
    StartGame();
    SaveGame(file);

}

int loadFile(char file[50][200]) {
    int n = 0;
    fstream myFile;
    myFile.open("List.txt", ios::in);
    if (myFile.is_open()) {
        char can[200];
        while (myFile >> can) {
            strcpy_s(file[n], strlen(can) + 1, can);
            n++;
        }
    }
    else {
        cout << "Loi" << endl;
    }
    myFile.close();
    return n; // so luong cua ten trong file
}

bool checkDuplicate(string file) {
    char list[50][200];
    int n = 0;
    char buffer[200];
    strcpy_s(buffer, file.length() + 1, file.c_str());
    n = loadFile(list);
    for (int i = 0; i < n; i++) {
        if (strncmp(buffer, list[i], strlen(list[i] + 1)) == 0) {
            return true; // co ton tai ten
        }
    }
    return false;
}



string displayLoad() {
    string file;
    char list[50][200];
    int n = 0;
    n = loadFile(list);
    system("CLS");
    WIDTH_CONSOLE = 80; HEIGHT_CONSOLE = 20;
    DrawBoard(0, 0, WIDTH_CONSOLE, HEIGHT_CONSOLE);
    GotoXY(30, 1);
    cout << "Nhap file : ";
    int x = 5;
    int y = 5;
    string s = ".txt";
    for (int i = 0; i < n; i++) {
        if (y + 1 == HEIGHT_CONSOLE) {
            x = x + 10;
            if (x + 1 >= WIDTH_CONSOLE) {
                break;
            }
        }
        GotoXY(x, y);
        cout << list[i];
        y++;
    }
    GotoXY(43, 1);
    getline(cin, file);
    file = file + s;
    return file;
}

