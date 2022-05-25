#pragma once

typedef int STATUS;
typedef struct SOCKET {

};

typedef  struct MSG {
	int blood;
	int card;
};
SOCKET* init_socket();
STATUS connect_port(SOCKET Socket,int port);
STATUS connect_ip(SOCKET Socket, char ip[], int port);
STATUS send_msg(SOCKET Socket, MSG msg);
STATUS get_msg(SOCKET Socket, MSG* msg);
