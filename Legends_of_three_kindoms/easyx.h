#pragma once
typedef int STATUS;
STATUS connect_local(); //告诉我是什么连接（服务端或者客户端）
STATUS get_server_ip(char ip[]);//告诉我ip
STATUS out_clink(); //从客户端界面返回到主界面


