#pragma once
#pragma once
#include"main.h"
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
///////////////////////////////////////////////////////////复杂函数
//杀音效
void sha_music();
//闪音效
void shan_music();
//桃音效
void tao_music();
//回合界面 你的回合 对手的回合
void state(USER *Our,USER *enemy); //绘制当前个人武将和敌方武将   牌都是按照从左往右开始算的
//攻击时
int attack(USER *Our,USER *enemy,int card);  // 绘制双方状态，并把第card牌放到屏幕中间
//被攻击时
void attacked(USER* Our, USER* enemy,  int enemy_card_id); //绘制双方状态，并把enemy_card_id放到屏幕中间
//竞争函数
void competition(USER* Our, USER* enemy, int card, int enemy_card_i); //绘制双方状态，把我方第card牌放到中件，对面id牌也放到中间
//报错
void wrong();//发生错误并退出
//结束回合
int end_huihe();
//开始游戏
void start_game(USER* Our, USER* enemy);//点击开始游戏
//结束游戏
void game_over();//结束游戏
typedef int STATUS;
STATUS connect_local(); //告诉我是什么连接（服务端或者客户端）
STATUS get_server_ip(char ip[]);//告诉我ip
STATUS out_clink(); //从客户端界面返回到主界面


