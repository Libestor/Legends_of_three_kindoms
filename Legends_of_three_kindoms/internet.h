#pragma once
#include"main.h"
typedef int STATUS; //状态信息
typedef  struct OUR_MSG {
	int blood;
	int enemy;
	int card;

};
STATUS init_connect();
STATUS get_ip(char ip[]);//告诉我本地地址
STATUS connect_ip( char ip[]);
STATUS send_msg( OUR_MSG* msg);
STATUS get_msg( OUR_MSG* msg);

STATUS PUT_CARD(USER * POEPLE,USER *AI,int card); // 传入双方手牌，然后判断是否出牌，出牌就自己完成的减牌，并返回1，
