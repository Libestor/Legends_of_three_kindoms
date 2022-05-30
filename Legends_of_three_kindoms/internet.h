#pragma once
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
