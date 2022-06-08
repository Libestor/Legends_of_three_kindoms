#pragma once
//#include<stdio.h>
//#include<Windows.h>
#include"easyx.h"
#include"skills_cards.h"
#include"LinkList.h"
#include"internet.h"
typedef int STATUS;

void losscard(USER* people, USER* ai);
USER* init_User();
STATUS GameOver(USER* people,USER* ai); //gameover成功就进入新一盘游戏，否则就直接停止程序

 