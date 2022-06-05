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
void music(char text[])
{
	//触发条件
	//if()
	//打开音乐
	mciSendString("open ./%c.mp3 alias BGM ", text, 0, 0);
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
		BeginBatchDraw();
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
		EndBatchDraw();
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
////杀音效
void sha_music()
{
	//if(Sha)
	//music(sha);
}
////闪音效
void shan_music()
{
	//if (Shan)
	//music(shan);
}
////桃音效
void tao_music()
{
	//if (Tao)
	//music(tao);
}
//回合界面 你的回合 对手的回合
void state(USER* Our,USER* enemy)
{	
	Node* p = Our->shoupai->next;
	picture(0, 551, p->data.name);
	//打印自己手牌
	for (int i = 1,int x=164; i < (Our->shoupai->length); i++, x = x + 164,p=p->next)
	{
		//牌名text
		picture(x, 551, p->data->name);
	}
	Node* p = enemy->shoupai->next;
	picture(0, 0, p->data->name);
	////////////////////////////////////////////////
	//打印对方手牌
	for (int i = 1, x = 1117; i < (enemy->shoupai->length); i++, x = x - 164, p = p->next)
	{
		//牌名text
		picture(x, 0, p->data->name);
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
//出牌函数 绘制双方状态，选择要出的牌
int attack(USER* Our, USER* enemy, int card)
{
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE))
	{
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			//判断鼠标点击位置,即牌的位置
			BEGIN:
			for (int x = 0, card = 1; x <= 164 * (Our->shoupai->length); card++, x = x + 164)
			{
				if (msg.x >= x && msg.x <= x + 164 && msg.y >= 551 && msg.y <= 773)
				{
					Node* p = Our->shoupai->next; //此处已经是第一张牌
					for (int i = 2; i <= card; i++)
					{
						p = p->next;
						picture(1117,329,p->data->name);
						for (int i = 2;i<= (Our->shoupai->length); i++)
						{
							if (i = card)
							{
								i--;
								continue;
							}
							else
							{
								state(Our, enemy);
							}
						}
					} //现在就经获得牌了
					if (p->data->name == shan && p->data->name == "WXKJ")                         //可修改
					{
						goto BEGIN;
					}
					if (card == 0)
					{
						break;
					}
					return card;
				}
			}
		}
	}
}
//被攻击时 绘制双方状态，并把enemy_card_id放到屏幕中间
void attacked(USER* Our, USER* enemy, int enemy_card_id)
{
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
//初始页面
int yemian()
{
	//创建一个窗口，确定窗口大小
	initgraph(1280, 773, EW_SHOWCONSOLE);
	change();
	//背景图
	picture(0, 0, "./BGP.jpg");
	//背景音乐
	BGM();
	//创建房间按钮
	button(555, 246, 170, 70, "创建房间");
	//进入房间按钮
	button(555, 346, 170, 70, "进入房间");
	//退出按钮
	button(555, 446, 170, 70, "退出");
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
					int isok = MessageBox(NULL, "请在终端输入你要连接的IP地址：", "连接", MB_OKCANCEL);
					//char IP[]=getchar();
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
		EndBatchDraw();
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
	button(555, 346, 170, 70, "结束回合");
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
					return 1;
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
void start_game(USER* Our, USER* enemy)
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
	int isok = MessageBox(NULL, "你赢了", "游戏结束", MB_OKCANCEL);
	if (isok == IDOK)
	{
		closegraph();
	}
}