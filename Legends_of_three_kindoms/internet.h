#pragma once
#include"main.h"
typedef int STATUS; //״̬��Ϣ
void AI(USER* people, USER* ai); //AI
int AI_kill_skill(USER* A, USER* B, int cur);//�˻�ɱ�Ĺ���
int AI_tao_skill(USER* A, USER* B, int cur);//�˻��ҵĹ���
int AI_juedou_skill(USER* A, USER* B, int cur);//�˻���������Ĺ���
int AI_nanmanruqin_skill(USER* A, USER* B, int cur);//�˻������������ֵĹ���
int AI_wanjianqifa_skill(USER* A, USER* B, int cur);//�˻���������뷢�Ĺ���
int AI_guohechaiqiao_skill(USER* A, USER* B, int cur);//�˻�������Ӳ��ŵĹ���