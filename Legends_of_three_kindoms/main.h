#pragma once
#include<stdio.h>
#include<Windows.h>
typedef int STATUS;
typedef struct USER {
	char ip[20];
	int port;
	//����

};
 enum CS {
	server = 1,
	client = 2
};
 STATUS init_all(USER* user);
 STATUS GameOver(); //gameover�ɹ��ͽ�����һ����Ϸ�������ֱ��ֹͣ����

