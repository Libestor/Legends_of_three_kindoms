#pragma once
#include <malloc.h>
#include<stdlib.h>
typedef struct WARLORD//�佫
{
	int PH;//����ֵ����
	int PH_current;//ʵʱ����ֵ
	int sha_num;//��ɱ������
	int (* skills)(WARLORD* A, WARLORD* B);
};
enum clolr {
	rad_peach, //����
	black_peach, // ����
	square, //����
	plum //÷��
};
struct CARDS
{
	int color;//1������ 2������ 3������ 4��÷��
	int points;
	int (* skill)(WARLORD* A, WARLORD* B);
};
WARLORD* zhangfei();//�ŷɵĳ�ʼ��
WARLORD* dianwei();//��Τ�ĳ�ʼ��
int dianwei_skill(WARLORD* A, WARLORD* B);
CARDS* kill();//���廨ɫ�������
int kill_skill(WARLORD* A, WARLORD* B);//ɱ�Ĺ���
CARDS* shan();//�������Ļ�ɫ�͵���
int shan_skill(WARLORD* A, WARLORD* B);//���Ĺ���
CARDS* tao();//�����ҵĻ�ɫ�͵���
int tao_skill(WARLORD* A, WARLORD* B);//�ҵĹ���
WARLORD* search_wujiang();//�����ȡ�佫
CARDS* search_pai();//�����ȡ����