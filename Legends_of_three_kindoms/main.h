#pragma once
#include<stdio.h>
#include<Windows.h>
#include"skills_cards.h"
#include"LinkList.h"
typedef int STATUS;
enum all_warloads {
	ZhangFei,
	DianWei,
};
enum all_cards {
	sha,
	shan,
	tao

};
typedef struct USER {
	char ip[20];
	WARLORD wj;
	Head* shoupai;
	int card_num;
};
 enum CS {
	server = 1,
	client = 2
};
 STATUS init_all(USER* user);
 STATUS GameOver(); //gameover成功就进入新一盘游戏，否则就直接停止程序



