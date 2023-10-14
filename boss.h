#pragma once

void processDeadBoss();
void bossInit();

void drawBoss();

void emptyBoss(const char* str);

void bossEat();

void bossMoveRight();

void bossMoveLeft();

void bossMoveUp();

void bossMoveDown(); 



int errorCheck(int curPosX, int curPosY);

void bossTouch();

void moveState(int bossMoving);

void movingLogic();

