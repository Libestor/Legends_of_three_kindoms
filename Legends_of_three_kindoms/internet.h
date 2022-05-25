#pragma once
typedef int STATUS; //状态信息
typedef  struct MSG {
	int blood;
	int enemy;
	int card;
};
STATUS init_connect();
STATUS get_ip(char ip[]);//告诉我本地地址
STATUS connect_ip( char ip[]);
STATUS send_msg( MSG msg);
STATUS get_msg( MSG* msg);
