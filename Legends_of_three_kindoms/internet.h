#pragma once
typedef int STATUS; //״̬��Ϣ
typedef  struct MSG {
	int blood;
	int enemy;
	int card;
};
STATUS init_connect();
STATUS get_ip(char ip[]);//�����ұ��ص�ַ
STATUS connect_ip( char ip[]);
STATUS send_msg( MSG msg);
STATUS get_msg( MSG* msg);
