#include<stdio.h>
#include<easyx.h>
// ����ͼ�ο�ͷ�ļ�
#include <graphics.h>
//������ý���豸�ӿ�ͷ�ļ�
#include<mmsystem.h>  
#include<windows.h>
//ʹ��_getch() 
#include <conio.h>
//���ؾ�̬��
#pragma comment(lib,"winmm.lib")
//�������ֺ���
void BGM()
{
	//������
	mciSendString("open ./BGM.mp3 alias BGM", 0, 0, 0);
	//��������
	mciSendString("play BGM repeat", 0, 0, 0);
	if (0)
	{
		mciSendString("close BGM", 0, 0, 0);
	}
}
//��Ч���ú���
void music(char text[])
{
	//��������
	//if()
	//������
	mciSendString("open ./%c.mp3 alias BGM ", text, 0, 0);
	//��������
	mciSendString("play BGM", 0, 0, 0);
}
//ͼƬ���ú���
void picture(int x, int y, const char text[])
{
	//���ͼƬ
	//����һ��(����)����
	IMAGE img;
	//��ȡͼƬ 
	loadimage(&img, text);
	//����ͼƬ
	putimage(x, y, &img);
}
//���λ���жϣ�����ƺ�ȷ�ϣ�
int mousepick(ExMessage msg)
{
	while (true)
	{
		//���±�y��551��773����x�᳤163��y�᳤222
		for (int i = 0, int a = 1; i <= 815; i = i + 164, a++)
		{
			//��������һ���Ƶ������򷵻�1���ڶ������򷵻�2...
			if (msg.x >= i && msg.x <= (i + 163) && msg.y >= 551 && msg.y <= 773)
				return a;
		}

	}
}
//���˵�����ж�
int zhucaidan()
{
	ExMessage msg;
	while (true)
	{
		//˫�����ͼ
		BeginBatchDraw();
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				//�ж������λ��
				//��������
				if (msg.x >= 555 && msg.x <= 725 && msg.y >= 246 && msg.y <= 316)
				{
					//������������䰴ť�����ӡ111
					printf("111\n");
				}
				//���뷿��
				if (msg.x >= 555 && msg.x <= 725 && msg.y >= 346 && msg.y <= 416)
				{
					//�������ڣ���ʾ�û�����
					int isok = MessageBox(NULL, "��������Ҫ���ӵ�IP��ַ��", "����", MB_OKCANCEL);
					// �����ַ����������������û�����
					char IP[20];
					InputBox(IP, 10, "��������Ҫ���ӵ�IP��ַ��");
				}
				//�˳�
				if (msg.x >= 555 && msg.x <= 725 && msg.y >= 446 && msg.y <= 516)
				{
					//������˳�
					int isok = MessageBox(NULL, "��ȷ��Ҫ�˳���", "���棡", MB_OKCANCEL);
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
//���ƺ����ƶ�������
void picture_move(int x, int y, const char text[])
{
	//ѭ���ƶ�ͼƬ//
	for (; y >= 541; y--)
	{
		picture(x, y, text);
	}
}
//��ť
void button(int x, int y, int w, int h, const char text[])
{
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);
	//�����ɫ
	setfillcolor(BROWN);
	//Բ�ǰ�ť
	fillroundrect(x, y, x + w, y + h, 20, 20);
	//����
	settextstyle(30, 0, "����");
	//�ı�����
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	//���
	outtextxy(tx, ty, text);

}
//���ڱ���
void change()
{
	//��ȡ���ھ��
	HWND hnd = GetHWnd();
	//���ô��ڱ���
	SetWindowText(hnd, "����ɱ");
}

///////////////////////////////////////////////////////////////////���Ӻ���
//ɱ��Ч
void sha_music()
{
	if(sha)
	music(sha);
}
//����Ч
void shan_music()
{
	if (shan)
	music(shan);
}
//����Ч
void tao_music()
{
	if (tao)
	music(tao);
}
//�غϽ��� ��Ļغ� ���ֵĻغ�
void state()
{
	//��ӡ����
	for (int i = 0,int x=0; i < ������; i++,x=x+164)
	{
		//����text
		picture(x, 551, text);
	}
	//Ѫ��Ϊ��ʱѭ������
	/// </summary>
	for (int i = 0; PH_current=0; i++)
	{
		//�ж���˭�Ļغ�
		//�ҵĻغ�
		if (i % 2 == 0)
		{
			button(285, 546, 150, 35, "����");
			button(725, 546, 150, 35, "ȡ��");

		}
		//���ֵĻغ�
		if (i % 2 == 1)
		{
			//��ӡ���ֵĻغ�
		}
	}
}
//���ƺ��� ����˫��״̬��ѡ��Ҫ������
int attack(int card)
{
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE))
	{
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			//�ж������λ��,���Ƶ�λ��
			for (int card = 1, int x = 0; x < = 164 * ������; card++, x = x + 164)
			{
				if (msg.x >= x && msg.x <= x + 164 && msg.y >= 551 && msg.y <= 773)
				{
					return card;
				}
			}
		}
//������ʱ ����˫��״̬������enemy_card_id�ŵ���Ļ�м�
void attacked(int enemy_card_id)
{
	picture(555, 246, enemy_card_id);
}
//��������
void competition()
{

}
//��ʼҳ��
int yemian()
{
	//����һ�����ڣ�ȷ�����ڴ�С
	initgraph(1280, 773, EW_SHOWCONSOLE);
	change();
	//����ͼ
	picture(0, 0, "./BGP.jpg");
	//��������
	BGM();
	//�������䰴ť
	button(555, 246, 170, 70, "��������");
	//���뷿�䰴ť
	button(555, 346, 170, 70, "���뷿��");
	//�˳���ť
	button(555, 446, 170, 70, "�˳�");
	//��꿪ʼ
	ExMessage msg;
	while (true)
	{
		//˫�����ͼ
		BeginBatchDraw();
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				//�ж������λ��
				//��������
				if (msg.x >= 555 && msg.x <= 725 && msg.y >= 246 && msg.y <= 316)
				{
					//������������䰴ť�����ӡ111
					printf("111\n");
				}
				//���뷿��
				if (msg.x >= 555 && msg.x <= 725 && msg.y >= 346 && msg.y <= 416)
				{
					//�������ڣ���ʾ�û�����
					int isok = MessageBox(NULL, "�����ն�������Ҫ���ӵ�IP��ַ��", "����", MB_OKCANCEL);
					//char IP[]=getchar();
				}
				//�˳�
				if (msg.x >= 555 && msg.x <= 725 && msg.y >= 446 && msg.y <= 516)
				{
					//������˳�
					int isok = MessageBox(NULL, "��ȷ��Ҫ�˳���", "���棡", MB_OKCANCEL);
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
	//�رմ���
	closegraph();

	return 0;
}