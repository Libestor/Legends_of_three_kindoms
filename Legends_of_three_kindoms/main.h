#pragma once
#include<stdio.h>
#include<Windows.h>
typedef int STATUS;
typedef struct USER {
	char ip[20];
	int port;
	//手牌

};
 enum CS {
	server = 1,
	client = 2
};
 STATUS init_all(USER* user);
 STATUS GameOver(); //gameover成功就进入新一盘游戏，否则就直接停止程序

