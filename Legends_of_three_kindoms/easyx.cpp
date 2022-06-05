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
		for (int i = 0, int a = 1; i <= 815; i = i + 164, a++)
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
//杀音效
void sha_music()
{
	if(sha)
	music(sha);
}
//闪音效
void shan_music()
{
	if (shan)
	music(shan);
}
//桃音效
void tao_music()
{
	if (tao)
	music(tao);
}
//回合界面 你的回合 对手的回合
void state()
{
	//打印手牌
	for (int i = 0,int x=0; i < 手牌数; i++,x=x+164)
	{
		//牌名text
		picture(x, 551, text);
	}
	//血量为零时循环结束
	/// </summary>
	for (int i = 0; PH_current=0; i++)
	{
		//判断是谁的回合
		//我的回合
		if (i % 2 == 0)
		{
			button(285, 546, 150, 35, "出牌");
			button(725, 546, 150, 35, "取消");

		}
		//对手的回合
		if (i % 2 == 1)
		{
			//打印对手的回合
		}
	}
}
//出牌函数 绘制双方状态，选择要出的牌
int attack(int card)
{
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE))
	{
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			//判断鼠标点击位置,即牌的位置
			for (int card = 1, int x = 0; x < = 164 * 手牌数; card++, x = x + 164)
			{
				if (msg.x >= x && msg.x <= x + 164 && msg.y >= 551 && msg.y <= 773)
				{
					return card;
				}
			}
		}
//被攻击时 绘制双方状态，并把enemy_card_id放到屏幕中间
void attacked(int enemy_card_id)
{
	picture(555, 246, enemy_card_id);
}
//竞争函数
void competition()
{

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