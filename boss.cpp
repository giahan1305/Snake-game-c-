#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <ctime>
#include <conio.h>
#include "main_functions.h"
#include <thread>
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

int bossMoving;

void processDeadBoss()
{
    BOSS_STATE = 0;
    system("CLS");
}

void bossInit()
{
    bossMoving = 1;
    BOSS_STATE = 1;
    SIZE_BOSS = 9;
    boss[0] = { 25, 10 }; boss[1] = { 26, 10 };
    boss[2] = { 27, 10 }; boss[3] = { 28, 10 };
    boss[4] = { 29, 10 }; boss[5] = { 30, 10 };
    boss[6] = { 31, 10 }; boss[7] = { 32, 10 };
    boss[8] = { 33, 10 };
    BOSS_SPEED = 6; BOSS_SCORE = 0;
}

void drawBoss()
{
    if (BOSS_STATE == 1)
    {
        char head = 35, left = 60, right = 62;
        cout << RESET;
        for (int i = 0; i < SIZE_BOSS - 1; i++)
        {
            if (i % 2 == 0)
            {
                GotoXY(boss[i].x, boss[i].y);
                printf("%c", left);
            }
            else
            {
                GotoXY(boss[i].x, boss[i].y);
                printf("%c", right);
            }
        }
        cout << RED;
        GotoXY(boss[SIZE_BOSS - 1].x, boss[SIZE_BOSS - 1].y);
        printf("%c", head);
    }
}

void emptyBoss(const char* str)
{
    GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
    printf(str);
    for (int i = 0; i < SIZE_SNAKE; i++)
    {
        GotoXY(boss[i].x, boss[i].y);
        printf(str);
    }
}

void bossEat()
{
    boss[SIZE_BOSS] = food[FOOD_INDEX];
    foodcount++;
    FOOD_INDEX++;
    BOSS_SPEED++;
    SIZE_BOSS++;
}

void bossMoveRight()
{
    if (boss[SIZE_BOSS].x + 1 == WIDTH_CONSOLE)
    {
        processDeadBoss();
    }
    if (boss[SIZE_BOSS].x == food[FOOD_INDEX].x && boss[SIZE_BOSS].y == food[FOOD_INDEX].y && BOSS_STATE != 0)
    {
        bossEat();
    }
    for (int i = 0; i < SIZE_SNAKE - 1; i++)
    {
        snake[i].x = snake[i + 1].x;
        snake[i].y = snake[i + 1].y;
    }
    snake[SIZE_SNAKE - 1].x++;
}

void bossMoveLeft()
{
    if (boss[SIZE_BOSS].x - 1 == 0)
    {
        processDeadBoss();
    }
    if (boss[SIZE_BOSS].x == food[FOOD_INDEX].x && boss[SIZE_BOSS].y == food[FOOD_INDEX].y && BOSS_STATE != 0)
    {
        bossEat();
    }
    for (int i = 0; i < SIZE_SNAKE - 1; i++)
    {
        snake[i].x = snake[i + 1].x;
        snake[i].y = snake[i + 1].y;
    }
    snake[SIZE_SNAKE - 1].x--;
}

void bossMoveUp()
{
    if (boss[SIZE_BOSS].y - 1 == 0)
    {
        processDeadBoss();
    }
    if (boss[SIZE_BOSS].x == food[FOOD_INDEX].x && boss[SIZE_BOSS].y == food[FOOD_INDEX].y && BOSS_STATE != 0)
    {
        bossEat();
    }
    for (int i = 0; i < SIZE_SNAKE - 1; i++)
    {
        snake[i].x = snake[i + 1].x;
        snake[i].y = snake[i + 1].y;
    }
    snake[SIZE_SNAKE - 1].y--;
}

void bossMoveDown()
{
    if (boss[SIZE_BOSS].y + 1 == HEIGHT_CONSOLE)
    {
        processDeadBoss();
    }
    if (boss[SIZE_BOSS].x == food[FOOD_INDEX].x && boss[SIZE_BOSS].y == food[FOOD_INDEX].y && BOSS_STATE != 0)
    {
        bossEat();
    }
    for (int i = 0; i < SIZE_SNAKE - 1; i++)
    {
        snake[i].x = snake[i + 1].x;
        snake[i].y = snake[i + 1].y;
    }
    snake[SIZE_SNAKE - 1].y++;
}



int errorCheck(int curPosX, int curPosY)
{
    if (curPosX + 2 == WIDTH_CONSOLE || curPosX - 2 == 0)
    {
        return bossMoving = 1;
    }
    else if (curPosY + 2 == HEIGHT_CONSOLE || curPosY - 2 == 0)
    {
        return bossMoving = 2;
    }
    return bossMoving;
}

void bossTouch()
{
    for (int i = 0; i < SIZE_SNAKE - 2; i++)
    {
        if (boss[SIZE_BOSS - 1].x == snake[i].x && boss[SIZE_BOSS - 1].y == snake[i].y)
        {
            processDeadBoss();
            break;
        }
    }
}

void moveState(int bossMoving)
{
    switch (bossMoving)
    {
    case 1:
    {
        bossMoveRight;
        break;
    }
    case 2:
    {
        bossMoveLeft;
        break;
    }
    case 3:
    {
        bossMoveUp;
        break;
    }
    case 4:
    {
        bossMoveDown();
        break;
    }
    default: 
        return;
    }
    return;
}

void movingLogic()
{
    int xDistance = food[FOOD_INDEX].x - boss[SIZE_BOSS - 1].x;
    int yDistance = food[FOOD_INDEX].y - boss[SIZE_BOSS - 1].y;
    if (xDistance < 0)
    {
        moveState(2);
    }
    else if (xDistance > 0)
    {
        moveState(1);
    }
    if (yDistance < 0)
    {
        moveState(3);
    }
    else if (yDistance > 0)
    {
        moveState(4);
    }
    int temp = errorCheck(boss[SIZE_BOSS - 1].x, boss[SIZE_BOSS].y);
    moveState(temp);
}

