#pragma once
#include"main.h"
typedef int STATUS; //״̬��Ϣ
typedef  struct OUR_MSG {
	int blood;
	int enemy;
	int card;

};
STATUS init_connect();
STATUS get_ip(char ip[]);//�����ұ��ص�ַ
STATUS connect_ip( char ip[]);
STATUS send_msg( OUR_MSG* msg);
STATUS get_msg( OUR_MSG* msg);

STATUS PUT_CARD(USER * POEPLE,USER *AI,int card); // ����˫�����ƣ�Ȼ���ж��Ƿ���ƣ����ƾ��Լ���ɵļ��ƣ�������1��
