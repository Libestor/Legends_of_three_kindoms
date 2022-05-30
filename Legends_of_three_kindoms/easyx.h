#pragma once
#pragma once
#include<stdio.h>
#include<easyx.h>
// 引用图形库头文件
#include <graphics.h>
//包含多媒体设备接口头文件
#include<mmsystem.h>  
#include<windows.h>
//使用_getch() 
#include <conio.h>
//加载静态库
#pragma comment(lib,"winmm.lib")
//背景音乐函数
void BGM();
//音效调用函数
void music(char text[]);
//图片调用函数
void picture(int x, int y, const char text[]);
//鼠标位置判断（点击牌和确认）
int mousepick(ExMessage msg);
//主菜单点击判断
int zhucaidan();
//出牌和弃牌动画函数
void picture_move(int x, int y, const char text[]);
//按钮
void button(int x, int y, int w, int h, const char text[]);
//窗口标题
void change();
typedef int STATUS;
STATUS connect_local(); //告诉我是什么连接（服务端或者客户端）
STATUS get_server_ip(char ip[]);//告诉我ip
STATUS out_clink(); //从客户端界面返回到主界面


