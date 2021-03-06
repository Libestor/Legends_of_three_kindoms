#define _CRT_SECURE_NO_WARNINGS
#define TIME_EASYX 1000
#define TIME_EASY 1000
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
#include"skills_cards.h"
//背景音乐函数
void BGM()
{
	//打开音乐

	mciSendString("open ./BGM.mp3 alias BGM ", 0, 0, 0);
	//播放音乐
	mciSendString("setaudio BGM volume to 500", 0, 0, 0);
	mciSendString("play BGM repeat ", 0, 0, 0);
	if (0)
	{
		//mciSendString("close BGM", 0, 0, 0);
	}
}
//音效调用函数
void music(const char text[])
{
	//触发条件
	//if()
	//打开音乐
	char a[50];
	char b[50];
	//sprintf(a,"open ./%s ",text);
	//printf("%s",a);
	//mciSendString(a,0, 0, 0);
	//播放音乐
	sprintf(b, "play ./%s", text);
	sprintf(a, "close ./%s", text);
	mciSendString(b, 0, 0, 0);
	//Sleep(1000);
	//mciSendString(a, 0, 0, 0);
}
//图片调用函数
void picture(int x, int y, const char text[])
{
	//输出图片
	//定义一个(变量)对象
	IMAGE img;
	//获取图片 
	
	loadimage(&img, text);
	//加载图片
	putimage(x, y, &img);
	//FlushBatchDraw();
}
//鼠标位置判断（点击牌和确认）
int mousepick(ExMessage msg)
{
	while (true)
	{
		//最下边y从551到773，牌x轴长163，y轴长222
		for (int i = 0, a = 1; i <= 815; i = i + 164, a++)
		{
			//如果点击第一张牌的区域，则返回1；第二张牌则返回2...
			if (msg.x >= i && msg.x <= (i + 163) && msg.y >= 551 && msg.y <= 773)
				 return a;
		}

	}
}
//主菜单点击判断

//出牌和弃牌动画函数
void picture_move(int x, int y, const char text[])
{
	//循环移动图片//
	for (; y >= 541; y--)
	{
		picture(x, y, text);
	}
}
//按钮
void button(int x, int y, int w, int h, const char text[])
{
	//设置背景模式
	setbkmode(TRANSPARENT);
	//填充颜色
	setfillcolor(BROWN);
	//圆角按钮
	fillroundrect(x, y, x + w, y + h, 20, 20);
	//字体
	settextstyle(30, 0, "宋体");
	//文本内容
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	//输出
	outtextxy(tx, ty, text);

}
//窗口标题
void change()
{
	//获取窗口句柄
	HWND hnd = GetHWnd();
	//设置窗口标题
	SetWindowText(hnd, "三国杀");
}
///////////////////////////////////////////////////////////////////复杂函数
//武将图片调用
void wujiang_picture(USER* Our, USER* enemy)
{
	switch (Our->wj->name)
	{
	case 1:
		picture(1117, 551, "张飞.png");
		break;
	case 2:
		picture(1117, 551, "典韦.png");
		break;
	}
	switch (enemy->wj->name)
	{
	case 1:
		picture(0, 0, "张飞.png");
		break;
	case 2:
		picture(0, 0, "典韦.png");
		break;
	}
}
//调用杀闪桃音效函数
void shashantao_music(int cur)
{
	switch (cur)
	{
	case Sha:
		music("杀.mp3");
		break;
	case Shan:
		music("闪.mp3");
		break;
	case Tao:
		music("桃.mp3");
		break;
	case JueDou:
		music("决斗.mp3");
		break;
	case WanJianQiFa:
		music("万箭齐发.mp3");
		break;
	case NanManRuQin:
		music("南蛮入侵.mp3");
		break;
	case WuXieKeJi:
		music("无懈可击.mp3");
		break;
	case GuoHeChaiQiao:
		music("过河拆桥.mp3");
		break;
	}
}
//调用杀闪桃图片函数
void shashantao(int x, int y, int cur)
{
	 switch (cur)
	{
	case Sha:
		picture(x, y, "杀.png");
		//shashantao_music(cur);
		break;
	case Shan:
		picture(x, y, "闪.png");
		//shashantao_music(cur);
		break;
	case Tao:
		picture(x, y, "桃.png");
		//shashantao_music(cur);
		break;
	case JueDou:
		picture(x, y, "决斗.png");
		//shashantao_music(cur);
		break;
	case WanJianQiFa:
		picture(x, y, "万箭齐发.png");
		//shashantao_music(cur);
		break;
	case NanManRuQin:
		picture(x, y, "南蛮入侵.png");
		//shashantao_music(cur);
		break;
	case WuXieKeJi:
		picture(x, y, "无懈可击.png");
		//shashantao_music(cur);
		break;
	case GuoHeChaiQiao:
		picture(x, y, "过河拆桥.png");
		//shashantao_music(cur);
		break;
	}
}
//血量绘制函数
void blood(int x, int y, int p)
{
	switch (p)
	{
	case 1:
		picture(x, y, "一血.png");
		break;
	case 2:
		picture(x, y, "二血.png");
		break;
	case 3:
		picture(x, y, "三血.png");
		break;
	case 4:
		picture(x, y, "四血.png");
		break;
	}
}
//敌方手牌背面
void enemy_cards(int x, int y)
{
	picture(x, y, "背面.png");
}
//绘制双方状态
void state(USER* Our, USER* enemy)
{	
	cleardevice();
	BeginBatchDraw();
	picture(0, 0, "./BGP.jpg");
	//button(1100, 400, 170, 70, "结束回合");
	//FlushBatchDraw();
	wujiang_picture(Our,enemy);
	//打印自己手牌和武将信息
	Node* p = Our->shoupai->next;
	//我方武将血量
	blood(1130,441, Our->wj->PH_current);
	//shashantao(0, 551,p);//
	int i, x=0;
	
	 while (p->next != NULL)
	{

		shashantao(x, 551, p->data->name);
		x += 164;
		p = p->next;
	}
	////////////////////////////////////////////////
	//打印对方手牌
	 //敌方武将血量
	 blood(0, 222, enemy->wj->PH_current);
	for (int i = 0, x = 1117; i < (enemy->shoupai->length); i++, x -= 164)
	{
		//牌名text
		enemy_cards(x, 0);//
		//Sleep(1000);
	}
	mciSendString("close ./杀.mp3", 0, 0, 0);
	mciSendString("close ./闪.mp3", 0, 0, 0);
	mciSendString("close ./桃.mp3", 0, 0, 0);
	mciSendString("close ./南蛮入侵.mp3", 0, 0, 0);
	mciSendString("close ./无懈可击.mp3", 0, 0, 0);
	mciSendString("close ./万箭齐发.mp3", 0, 0, 0);
	mciSendString("close ./决斗.mp3", 0, 0, 0);
	mciSendString("close ./过河拆桥.mp3", 0, 0, 0);
	EndBatchDraw();
}
//绘制双方状态，选择要出的牌,并把牌放在屏幕上
int attack(USER* Our, USER* enemy, int card)
{

	state(Our, enemy);
	shashantao(860, 329, card);
	shashantao_music(card);
	picture(1050, 250, "我方.jpg");
	//shashantao_music(p);
	Sleep(TIME_EASY * 2);
	state(Our, enemy);
	//free(p);
	
	return 0;
}
//接受用户所点击的牌，并返回
int get_card(USER* Our, USER* enemy)
{
	//结束回合按钮
	state(Our, enemy);
	picture(555, 483, "结束出牌.png");
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				//判断鼠标点击位置,即牌的位置
				for (int x = 0, card = 1; x <= 164 * (Our->shoupai->length); card++, x = x + 164)
				{
					if (msg.x >= 555 && msg.x <= 555+190 && msg.y >= 483 && msg.y <= 483+68)
					{
						Sleep(TIME_EASYX);
						return -1;
					}
					else if (msg.x >= 555 && msg.x <= 725 && msg.y >= 346 && msg.y <= 416)
					{
						return -1;
					}
					else if (msg.x >= 0 && msg.x <= 164 && msg.y >= 551 && msg.y <= 773)
					{
						return 1;
					}
					else if (msg.x >= 164 && msg.x <= 328 && msg.y >= 551 && msg.y <= 773)
					{
						return 2;
					}
					else if (msg.x >= 328 && msg.x <= 492 && msg.y >= 551 && msg.y <= 773)
					{
						return 3;
					}
					else if (msg.x >= 492 && msg.x <= 656 && msg.y >= 551 && msg.y <= 773)
					{
						return 4;
					}
					else if (msg.x >= 656 && msg.x <= 820 && msg.y >= 551 && msg.y <= 773)
					{
						return 5;
					}
					else if (msg.x >= 820 && msg.x <= 984 && msg.y >= 551 && msg.y <= 773)
					{
						return 6;
					}

				}
			}
		}
	}
}
//被攻击时 绘制双方状态，并把enemy_card_id放到屏幕中间
void attacked(USER* Our, USER* enemy, int enemy_card_id)
{
	//Node* p = (Node*)malloc(sizeof(Node));
	//p->data->name = enemy_card_id;
	state(Our, enemy);
	shashantao(300, 275, enemy_card_id);
	shashantao_music(enemy_card_id);
	picture(200, 250, "敌方.jpg");
	Sleep(1000);
	//shashantao_music(enemy_card_id);
	Sleep(2* TIME_EASYX);
	//free(p);
	state(Our, enemy);
}
//竞争函数
void competition(USER* Our, USER* enemy, int card, int enemy_card_id)
{
	attack(Our,enemy, card);
	attacked(Our, enemy, enemy_card_id);
}
//错误发生窗口，点击确定则关闭窗口
void wrong()
{
	int isok = MessageBox(NULL, "发生错误了", "错误",NULL);
	
}
//摸牌阶段
void in_card()
{
	HWND hnd = GetHWnd();
	int isok = MessageBox(hnd, "请摸牌", "你的摸牌阶段", NULL);
}
//出牌阶段函数
void out_card()
{
	HWND hnd = GetHWnd();
	int isok = MessageBox(hnd, "请出牌", "你的出牌阶段", NULL);
}
void abandon_card()
{
	HWND hnd = GetHWnd();
	int isok = MessageBox(hnd, "请弃牌", "你的弃牌阶段", NULL);
}
//不能出牌函数
void wrong_card()
{
	HWND hnd = GetHWnd();
	int isok = MessageBox(hnd, "你不能出这张牌", "错误", NULL);
}
//初始页面，返回1表示开始游戏，返回0表示结束游戏
int start_game(USER* Our, USER* enemy)
{
	//创建一个窗口，确定窗口大小
	initgraph(1280, 773);
	change();
	//sprintf(b, "play ./%s", text);
	mciSendString("open ./杀.mp3" , 0, 0, 0);
	mciSendString("open ./闪.mp3", 0, 0, 0);
	mciSendString("open ./桃.mp3", 0, 0, 0);
	mciSendString("open ./南蛮入侵.mp3", 0, 0, 0);
	mciSendString("open ./无懈可击.mp3", 0, 0, 0);
	mciSendString("open ./万箭齐发.mp3", 0, 0, 0);
	mciSendString("open ./决斗.mp3", 0, 0, 0);
	mciSendString("status ./决斗.mp3 status 10000", 0, 0, 0);
	mciSendString("open ./过河拆桥.mp3", 0, 0, 0);

	//背景图
	picture(0, 0, "./BGP.jpg");
	//背景音乐
	BGM();
	
	//开始
	button(555, 346, 170, 70, "开始游戏");
	//退出按钮
	button(555, 446, 170, 70, "退出");
	//鼠标开始
	ExMessage msg;
	while (true)
	{
		//双缓冲绘图
		//BeginBatchDraw();
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				//判断鼠标点击位置
				////创建房间
				//if (msg.x >= 555 && msg.x <= 725 && msg.y >= 246 && msg.y <= 316)
				//{
				//	//若点击创建房间按钮，则打印111
				//	printf("111\n");
				//}
				//进入房间
				//开始游戏
				if (msg.x >= 555 && msg.x <= 725 && msg.y >= 346 && msg.y <= 416)
				{
					//表示开始游戏
					return 1;
				}
				//退出
				if (msg.x >= 555 && msg.x <= 725 && msg.y >= 446 && msg.y <= 516)
				{
					//若点击退出
					HWND hnd = GetHWnd();
					int isok = MessageBox(hnd, "您确定要退出吗？", "警告！", MB_OKCANCEL);
					if (isok == IDOK)
					{
						closegraph();
					}
				}
				break;
			default:
				break;
			}
		}
		//EndBatchDraw();
	}
	getchar();
	//关闭窗口
	closegraph();

	return 0;
}
//结束回合
int end_huihe(USER *people , USER *ai)
{
	//结束回合按钮
	button(500, 400, 170, 70, "回合结束");
	state(people, ai);

	//button(600, 200, 170, 70, "回合结束");
	Sleep(TIME_EASY);
	state(people, ai);
	return 0;

}

//结束游戏
void game_over_ai()
{
	HWND hnd = GetHWnd();
	int isok = MessageBox(hnd, "你赢了", "游戏结束", MB_OKCANCEL);
	if (isok == IDOK)
	{
		closegraph();
	}
}
void game_over_people()
{
	HWND hnd = GetHWnd();
	int isok = MessageBox(hnd, "你输了", "游戏结束", MB_OKCANCEL);
	if (isok == IDOK)
	{
		closegraph();
	}
}
void killed() {
	mciSendString("open ./伤害.mp3 alias kill ", 0, 0, 0);
	//播放音乐
	mciSendString("play kill ", 0, 0, 0);
	Sleep(TIME_EASY);
	mciSendString("close kill ", 0, 0, 0);
}