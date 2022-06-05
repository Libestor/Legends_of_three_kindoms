#pragma once
#include <malloc.h>
#include<stdlib.h>
enum all_warloads {
	ZhangFei=1,
	DianWei,
};
enum all_cards {
	Sha=1,
	Shan,
	Tao,
	juedou
};
typedef struct WARLORD//�佫
{
	int name;
	int PH;//����ֵ����
	int PH_current;//ʵʱ����ֵ
	int sha_num;//��ɱ������
	int (* skills)(WARLORD* A, WARLORD* B);
};
enum clolr {
	rad_peach=1, //����
	black_peach, // ����
	square, //����
	plum //÷��
};
typedef struct CARDS
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
WARLORD* mustzhangfei();//�����ȡ�ŷ�
WARLORD* mustdianwei();//�����ȡ��Τ
CARDS* getcards(int i);//���ݴ������ݶ��򷵻ؿ���
CARDS* juedou();//����������Ƶĵ����ͻ�ɫ
int juedou_skill(WARLORD* A, WARLORD* B);//��������Ĺ���
CARDS* nanmanruqin();//�����������ֵĵ����ͻ�ɫ
int nanmanruqin_skill(WARLORD* A, WARLORD* B);//�����������ֵĹ���
CARDS* wanjianqifa();//��������뷢�ĵ����ͻ�ɫ
int wanjianqifa_skill(WARLORD* A, WARLORD* B);//��������뷢�Ĺ���
