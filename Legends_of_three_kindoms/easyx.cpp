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
#include"skills_cards.h"
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
void music(const char text[])
{
	//��������
	//if()
	//������
	mciSendString("open ./%c.mp3 alias BGM ",text, 0, 0);
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
		for (int i = 0, a = 1; i <= 815; i = i + 164, a++)
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
		Sleep(1);
		//BeginBatchDraw();
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
		//EndBatchDraw();
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

//����ɱ������Ч����
void shashantao_music(Node* p)
{
	switch (p->data->name)
	{
	case 1:
		music("ɱ");
		break;
	case 2:
		music("��");
		break;
	case 3:
		music("��");
		break;
	case 4:
		music("����");
		break;
	case 5:
		music("����뷢");
		break;
	case 6:
		music("��������");
		break;
	case 7:
		music("��и�ɻ�");
		break;
	case 8:
		music("���Ӳ���");
		break;
	}
}
//����ɱ����ͼƬ����
void shashantao(int x, int y, Node* p)
{
	 switch (p->data->name)
	{
	case 1:
		picture(x, y, "ɱ.png");
		break;
	case 2:
		picture(x, y, "��.png");
		break;
	case 3:
		picture(x, y, "��.png");
		break;
	case 4:
		picture(x, y, "����.png");
		break;
	case 5:
		picture(x, y, "����뷢.png");
		break;
	case 6:
		picture(x, y, "��������.png");
		break;
	case 7:
		picture(x, y, "��и�ɻ�.png");
		break;
	case 8:
		picture(x, y, "���Ӳ���.png");
		break;
	}
}
//Ѫ�����ƺ���
void blood(int x, int y, USER* p)
{
	switch (p->wj->PH_current)
	{
	case 1:
		picture(x, y, "һѪ.png");
		break;
	case 2:
		picture(x, y, "��Ѫ.png");
		break;
	case 3:
		picture(x, y, "��Ѫ.png");
		break;
	case 4:
		picture(x, y, "��Ѫ.png");
		break;
	}
}
//�з����Ʊ���
void enemy_cards(int x, int y)
{
	picture(x, y, "����.png");
}
//����˫��״̬
void state(USER* Our, USER* enemy)
{	
	cleardevice();
	picture(0, 0, "./BGP.jpg");
	button(1100, 450, 170, 70, "�����غ�");
	//��ӡ�Լ�����
	Node* p = Our->shoupai->next;
	shashantao(0, 551,p);//
	int i, x;
	for (i = 1,x=164, p = p->next; i < (Our->shoupai->length); i++, x = x + 164)
	{
		//����text
		shashantao(x, 551,p);//
		Sleep(1000);
	}
	////////////////////////////////////////////////
	//��ӡ�Է�����
	Node* q = enemy->shoupai->next;
	enemy_cards(0, 0);//
	for (int i = 1, x = 1117; i < (enemy->shoupai->length); i++, x = x - 164, q = q->next)
	{
		//����text
		enemy_cards(x, 0);//
		Sleep(1000);
	}
	////Ѫ��Ϊ��ʱѭ������
	///// </summary>
	//for (int i = 0; PH_current=0; i++)
	//{
	//	//�ж���˭�Ļغ�
	//	//�ҵĻغ�
	//	if (i % 2 == 0)
	//	{
	//		button(285, 546, 150, 35, "����");
	//		button(725, 546, 150, 35, "ȡ��");

	//	}
	//	//���ֵĻغ�
	//	if (i % 2 == 1)
	//	{
	//		//��ӡ���ֵĻغ�
	//	}
	//}
}
//����˫��״̬��ѡ��Ҫ������,�����Ʒ�����Ļ��
int attack(USER* Our,USER* enemy,int card)
{
	Node* p = Our->shoupai->next;
	state(Our,enemy);
	shashantao(1117, 329, p);
	picture(1200, 329, "�ҷ�");
	shashantao_music(p);
	state(Our, enemy);
}
//�����û���������ƣ�������
int get_card(USER* Our, USER* enemy)
{
	//�����غϰ�ť
	state(Our, enemy);
	button(1100, 450, 170, 70, "�����غ�");
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				//�ж������λ��,���Ƶ�λ��
				for (int x = 0, card = 1; x <= 164 * (Our->shoupai->length); card++, x = x + 164)
				{
					if (msg.x >= 1100 && msg.x <= 1100+170 && msg.y >= 450 && msg.y <= 450+70)
					{
						//button(1100, 450, 170, 70, "�����غ�");
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
//������ʱ ����˫��״̬������enemy_card_id�ŵ���Ļ�м�
void attacked(USER* Our, USER* enemy, int enemy_card_id)
{
	Node* p = Our->shoupai->next;
	state(Our, enemy);
	shashantao(560, 275, p);
	picture(20, 275, "�з�");
	shashantao_music(p);
	state(Our, enemy);
}
//��������
void competition(USER* Our, USER* enemy, int card, int enemy_card_id)
{
	attack(Our,enemy, card);
	attacked(Our, enemy, enemy_card_id);
}
//���������ڣ����ȷ����رմ���
void wrong()
{
	int isok = MessageBox(NULL, "����������", "����", MB_OKCANCEL);
	if (isok == IDOK)
	{
		closegraph();
	}
}
//��ʼҳ�棬����1��ʾ��ʼ��Ϸ������0��ʾ������Ϸ
int start_game(USER* Our, USER* enemy)
{
	//����һ�����ڣ�ȷ�����ڴ�С
	initgraph(1280, 773);
	change();
	//����ͼ
	picture(0, 0, "./BGP.jpg");
	//��������
	BGM();
	
	//��ʼ
	button(555, 346, 170, 70, "��ʼ��Ϸ");
	//�˳���ť
	button(555, 446, 170, 70, "�˳�");
	//��꿪ʼ
	ExMessage msg;
	while (true)
	{
		//˫�����ͼ
		//BeginBatchDraw();
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				//�ж������λ��
				////��������
				//if (msg.x >= 555 && msg.x <= 725 && msg.y >= 246 && msg.y <= 316)
				//{
				//	//������������䰴ť�����ӡ111
				//	printf("111\n");
				//}
				//���뷿��
				//��ʼ��Ϸ
				if (msg.x >= 555 && msg.x <= 725 && msg.y >= 346 && msg.y <= 416)
				{
					//��ʾ��ʼ��Ϸ
					return 1;
				}
				//�˳�
				if (msg.x >= 555 && msg.x <= 725 && msg.y >= 446 && msg.y <= 516)
				{
					//������˳�
					HWND hnd = GetHWnd();
					int isok = MessageBox(hnd, "��ȷ��Ҫ�˳���", "���棡", MB_OKCANCEL);
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
	//�رմ���
	closegraph();

	return 0;
}
//�����غ�
int end_huihe()
{
	//�����غϰ�ť
	//button(555, 346, 170, 70, "�����غ�");
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
				//��ʼ��Ϸ
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
//��ʼ��Ϸ
void start_game1(USER* Our, USER* enemy)
{
	//��ʼ��Ϸ��ť
	button(555, 346, 170, 70, "��ʼ��Ϸ");
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
				//��ʼ��Ϸ
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
		//�رմ���
		closegraph();
		
	}
	
}
//������Ϸ
void game_over()
{
	HWND hnd = GetHWnd();
	int isok = MessageBox(hnd, "��Ӯ��", "��Ϸ����", MB_OKCANCEL);
	if (isok == IDOK)
	{
		closegraph();
	}
}