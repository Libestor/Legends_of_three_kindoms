#pragma once
#pragma once
#include"main.h"
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
void music(char text[]);
//ͼƬ���ú���
void picture(int x, int y, const char text[]);
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
//ɱ��Ч
void sha_music();
//����Ч
void shan_music();
//����Ч
void tao_music();
//�غϽ��� ��Ļغ� ���ֵĻغ�
void state(USER *Our,USER *enemy); //���Ƶ�ǰ�����佫�͵з��佫   �ƶ��ǰ��մ������ҿ�ʼ���
//����ʱ
int attack(USER *Our,USER *enemy,int card);  // ����˫��״̬�����ѵ�card�Ʒŵ���Ļ�м�
//������ʱ
void attacked(USER* Our, USER* enemy,  int enemy_card_id); //����˫��״̬������enemy_card_id�ŵ���Ļ�м�
//��������
void competition(USER* Our, USER* enemy, int card, int enemy_card_i); //����˫��״̬�����ҷ���card�Ʒŵ��м�������id��Ҳ�ŵ��м�
//����
void wrong();//���������˳�
//�����غ�
int end_huihe();
//��ʼ��Ϸ
void start_game(USER* Our, USER* enemy);//�����ʼ��Ϸ
//������Ϸ
void game_over();//������Ϸ
typedef int STATUS;
STATUS connect_local(); //��������ʲô���ӣ�����˻��߿ͻ��ˣ�
STATUS get_server_ip(char ip[]);//������ip
STATUS out_clink(); //�ӿͻ��˽��淵�ص�������


