#pragma once
#include"main.h"
typedef int STATUS; //状态信息
void AI(USER* people, USER* ai); //AI
int AI_kill_skill(USER* A, USER* B, int cur);//人机杀的功能
int AI_tao_skill(USER* A, USER* B, int cur);//人机桃的功能
int AI_juedou_skill(USER* A, USER* B, int cur);//人机定义决斗的功能
int AI_nanmanruqin_skill(USER* A, USER* B, int cur);//人机定义南蛮入侵的功能
int AI_wanjianqifa_skill(USER* A, USER* B, int cur);//人机定义万箭齐发的功能
int AI_guohechaiqiao_skill(USER* A, USER* B, int cur);//人机定义过河拆桥的功能