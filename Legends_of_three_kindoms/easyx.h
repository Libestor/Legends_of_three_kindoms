#pragma once
#pragma once
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
typedef int STATUS;
STATUS connect_local(); //��������ʲô���ӣ�����˻��߿ͻ��ˣ�
STATUS get_server_ip(char ip[]);//������ip
STATUS out_clink(); //�ӿͻ��˽��淵�ص�������


