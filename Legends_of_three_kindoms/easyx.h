
#pragma once
#pragma once
#include"skills_cards.h"
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
void music(const char text[]);
//图片调用函数
void picture(int x, int y,char text[]);
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
//武将图片调用
void wujiang_picture(USER* Our, USER* enemy);
//调用杀闪桃音效函数
void shashantao_music(int cur);
//调用杀闪桃图片函数
void shashantao(int x, int y, int cur);
//敌方手牌背面
void enemy_cards(int x, int y);
//状态函数
void state(USER* Our, USER* enemy);//绘制双方状态
//攻击函数
int attack(USER* Our, USER* enemy, int card);//绘制双方状态，选择要出的牌,并把牌放在屏幕上
//被攻击函数
void attacked(USER* Our, USER* enemy,  int enemy_card_id); //绘制双方状态，并把enemy_card_id放到屏幕中间
//接收函数
int get_card(USER* Our, USER* enemy);//接收用户所点击的牌，并返回
//竞争函数
void competition(USER* Our, USER* enemy, int card, int enemy_card_i); //绘制双方状态，把我方第card牌放到中件，对面id牌也放到中间
//报错
void wrong();//发生错误并退出
//摸牌阶段
void in_card();
//出牌阶段函数
void out_card();
//不能出牌函数
void wrong_card();//提示不能出牌
//结束回合
int end_huihe(USER* people,USER* ai);
//开始游戏
int start_game(USER* Our, USER* enemy);//点击开始游戏
int start_game1(USER* Our, USER* enemy);//点击开始游戏
//结束游戏
void game_over();//结束游戏
typedef int STATUS;
STATUS connect_local(); //告诉我是什么连接（服务端或者客户端）
STATUS get_server_ip(char ip[]);//告诉我ip
STATUS out_clink(); //从客户端界面返回到主界面


