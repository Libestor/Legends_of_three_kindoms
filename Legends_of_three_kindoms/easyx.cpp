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
	mciSendString("open ./BGM.mp3 alias BGM", 0, 0, 0);
	//播放音乐
	mciSendString("play BGM repeat", 0, 0, 0);
	if (0)
	{
		mciSendString("close BGM", 0, 0, 0);
	}
}
//音效调用函数
void music(const char text[])
{
	//触发条件
	//if()
	//打开音乐
	mciSendString("open ./%c.mp3 alias BGM ",text, 0, 0);
	//播放音乐
	mciSendString("play BGM", 0, 0, 0);
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
int zhucaidan()
{
	ExMessage msg;
	while (true)
	{
		//双缓冲绘图
		Sleep(1);
		//BeginBatchDraw();
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				//判断鼠标点击位置
				//创建房间
				if (msg.x >= 555 && msg.x <= 725 && msg.y >= 246 && msg.y <= 316)
				{
					//若点击创建房间按钮，则打印111
					printf("111\n");
				}
				//进入房间
				if (msg.x >= 555 && msg.x <= 725 && msg.y >= 346 && msg.y <= 416)
				{
					//弹出窗口，提示用户操作
					int isok = MessageBox(NULL, "请输入你要连接的IP地址：", "连接", MB_OKCANCEL);
					// 定义字符串缓冲区并接收用户输入
					char IP[20];
					InputBox(IP, 10, "请输入你要连接的IP地址：");
				}
				//退出
				if (msg.x >= 555 && msg.x <= 725 && msg.y >= 446 && msg.y <= 516)
				{
					//若点击退出
					int isok = MessageBox(NULL, "您确定要退出吗？", "警告！", MB_OKCANCEL);
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
}
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

//调用杀闪桃音效函数
void shashantao_music(Node* p)
{
	switch (p->data->name)
	{
	case 1:
		music("杀");
		break;
	case 2:
		music("闪");
		break;
	case 3:
		music("桃");
		break;
	case 4:
		music("决斗");
		break;
	case 5:
		music("万箭齐发");
		break;
	case 6:
		music("南蛮入侵");
		break;
	case 7:
		music("无懈可击");
		break;
	case 8:
		music("过河拆桥");
		break;
	}
}
//调用杀闪桃图片函数
void shashantao(int x, int y, Node* p)
{
	 switch (p->data->name)
	{
	case 1:
		picture(x, y, "杀.png");
		break;
	case 2:
		picture(x, y, "闪.png");
		break;
	case 3:
		picture(x, y, "桃.png");
		break;
	case 4:
		picture(x, y, "决斗.png");
		break;
	case 5:
		picture(x, y, "万箭齐发.png");
		break;
	case 6:
		picture(x, y, "南蛮入侵.png");
		break;
	case 7:
		picture(x, y, "无懈可击.png");
		break;
	case 8:
		picture(x, y, "过河拆桥.png");
		break;
	}
}
//血量绘制函数
void blood(int x, int y, USER* p)
{
	switch (p->wj->PH_current)
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
	picture(0, 0, "./BGP.jpg");
	button(1100, 450, 170, 70, "结束回合");
	//打印自己手牌
	Node* p = Our->shoupai->next;
	shashantao(0, 551,p);//
	int i, x;
	for (i = 1,x=164, p = p->next; i < (Our->shoupai->length); i++, x = x + 164)
	{
		//牌名text
		shashantao(x, 551,p);//
		Sleep(1000);
	}
	////////////////////////////////////////////////
	//打印对方手牌
	Node* q = enemy->shoupai->next;
	enemy_cards(0, 0);//
	for (int i = 1, x = 1117; i < (enemy->shoupai->length); i++, x = x - 164, q = q->next)
	{
		//牌名text
		enemy_cards(x, 0);//
		Sleep(1000);
	}
	////血量为零时循环结束
	///// </summary>
	//for (int i = 0; PH_current=0; i++)
	//{
	//	//判断是谁的回合
	//	//我的回合
	//	if (i % 2 == 0)
	//	{
	//		button(285, 546, 150, 35, "出牌");
	//		button(725, 546, 150, 35, "取消");

	//	}
	//	//对手的回合
	//	if (i % 2 == 1)
	//	{
	//		//打印对手的回合
	//	}
	//}
}
//绘制双方状态，选择要出的牌,并把牌放在屏幕上
int attack(USER* Our,USER* enemy,int card)
{
	Node* p = Our->shoupai->next;
	state(Our,enemy);
	shashantao(1117, 329, p);
	picture(1200, 329, "我方");
	shashantao_music(p);
	state(Our, enemy);
}
//接受用户所点击的牌，并返回
int get_card(USER* Our, USER* enemy)
{
	//结束回合按钮
	state(Our, enemy);
	button(1100, 450, 170, 70, "结束回合");
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
					if (msg.x >= 1100 && msg.x <= 1100+170 && msg.y >= 450 && msg.y <= 450+70)
					{
						//button(1100, 450, 170, 70, "结束回合");
						Sleep(1000);
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
	Node* p = Our->shoupai->next;
	state(Our, enemy);
	shashantao(560, 275, p);
	picture(20, 275, "敌方");
	shashantao_music(p);
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
	int isok = MessageBox(NULL, "发生错误了", "错误", MB_OKCANCEL);
	if (isok == IDOK)
	{
		closegraph();
	}
}
//初始页面，返回1表示开始游戏，返回0表示结束游戏
int start_game(USER* Our, USER* enemy)
{
	//创建一个窗口，确定窗口大小
	initgraph(1280, 773);
	change();
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
int end_huihe()
{
	//结束回合按钮
	//button(555, 346, 170, 70, "结束回合");
	ExMessage msg;
	while (true)
	{
		//双缓冲绘图
		BeginBatchDraw();
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				//判断鼠标点击位置
				//开始游戏
				if (msg.x >= 555 && msg.x <= 725 && msg.y >= 346 && msg.y <= 416)
				{
					return -1;
				}
				break;
			default:
				break;
			}
			EndBatchDraw();
		}

	}
}
//开始游戏
void start_game1(USER* Our, USER* enemy)
{
	//开始游戏按钮
	button(555, 346, 170, 70, "开始游戏");
	//鼠标开始
	ExMessage msg;
	while (true)
	{
		//双缓冲绘图
		BeginBatchDraw();
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				//判断鼠标点击位置
				//开始游戏
				if (msg.x >= 555 && msg.x <= 725 && msg.y >= 346 && msg.y <= 416)
				{
					state(Our, enemy);
				}
				break;
			default:
				break;
			}
			EndBatchDraw();
		}
		getchar();
		//关闭窗口
		closegraph();
		
	}
	
}
//结束游戏
void game_over()
{
	HWND hnd = GetHWnd();
	int isok = MessageBox(hnd, "你赢了", "游戏结束", MB_OKCANCEL);
	if (isok == IDOK)
	{
		closegraph();
	}
}