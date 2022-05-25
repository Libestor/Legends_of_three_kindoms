#pragma once

typedef int STATUS; //×´Ì¬ÐÅÏ¢

typedef  struct MSG {
	int blood;
	int card;
};
STATUS init_connect();
STATUS connect_port(int port);
STATUS connect_ip( char ip[], int port);
STATUS send_msg( MSG msg);
STATUS get_msg( MSG* msg);
