
#pragma once
#pragma once
#include"skills_cards.h"
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
void BGM();
//��Ч���ú���
void music(const char text[]);
//ͼƬ���ú���
void picture(int x, int y,char text[]);
//���λ���жϣ�����ƺ�ȷ�ϣ�
int mousepick(ExMessage msg);
//���˵�����ж�
int zhucaidan();
//���ƺ����ƶ�������
void picture_move(int x, int y, const char text[]);
//��ť
void button(int x, int y, int w, int h, const char text[]);
//���ڱ���
void change();
///////////////////////////////////////////////////////////���Ӻ���
//�佫ͼƬ����
void wujiang_picture(USER* Our, USER* enemy);
//����ɱ������Ч����
void shashantao_music(int cur);
//����ɱ����ͼƬ����
void shashantao(int x, int y, int cur);
//�з����Ʊ���
void enemy_cards(int x, int y);
//״̬����
void state(USER* Our, USER* enemy);//����˫��״̬
//��������
int attack(USER* Our, USER* enemy, int card);//����˫��״̬��ѡ��Ҫ������,�����Ʒ�����Ļ��
//����������
void attacked(USER* Our, USER* enemy,  int enemy_card_id); //����˫��״̬������enemy_card_id�ŵ���Ļ�м�
//���պ���
int get_card(USER* Our, USER* enemy);//�����û���������ƣ�������
//��������
void competition(USER* Our, USER* enemy, int card, int enemy_card_i); //����˫��״̬�����ҷ���card�Ʒŵ��м�������id��Ҳ�ŵ��м�
//����
void wrong();//���������˳�
//���ƽ׶�
void in_card();
//���ƽ׶κ���
void out_card();
//���ܳ��ƺ���
void wrong_card();//��ʾ���ܳ���
//�����غ�
int end_huihe(USER* people,USER* ai);
//��ʼ��Ϸ
int start_game(USER* Our, USER* enemy);//�����ʼ��Ϸ
int start_game1(USER* Our, USER* enemy);//�����ʼ��Ϸ
//������Ϸ
void game_over();//������Ϸ
typedef int STATUS;
STATUS connect_local(); //��������ʲô���ӣ�����˻��߿ͻ��ˣ�
STATUS get_server_ip(char ip[]);//������ip
STATUS out_clink(); //�ӿͻ��˽��淵�ص�������


