#pragma once
#include<stdio.h>
#include<Windows.h>
#include"skills_cards.h"
#include"LinkList.h"
typedef int STATUS;
enum warloads {
	ZhangFei,
	DianWei,
};
typedef struct USER {
	char ip[20];
	WARLORD wj;
	Head* shoupai;

};
 enum CS {
	server = 1,
	client = 2
};
 STATUS init_all(USER* user);
 STATUS GameOver(); //gameover�ɹ��ͽ�����һ����Ϸ�������ֱ��ֹͣ����



