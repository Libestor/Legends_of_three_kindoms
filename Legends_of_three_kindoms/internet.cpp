#define TIME 500
#include"internet.h"
#include"skills_cards.h"
#include"LinkList.h"
#include"easyx.h"
;
; int AI_kill_skill(USER* A, USER* B)
{
	int cur;
	cur = search(B->shoupai, Sha);
	DeletList(B->shoupai, cur);
	attacked(A, B, Sha);
	int a;
	printf("进入到杀的寻找");
	a = search(A->shoupai, Shan);
	if (a == 0)
	{
		A->wj->PH_current--;
	}
	else
	{
		DeletList(A->shoupai, a);
		attack(A, B, Shan);
	}
	return 0;
}
int AI_tao_skill(USER* A, USER* B)
{
	int cur;
	cur = search(B->shoupai, Tao);
	DeletList(B->shoupai, cur);
	B->wj->PH_current++;
	attacked(A, B, Tao);
	return 0;
}
int AI_juedou_skill(USER* A, USER* B)//
{
	int cur;
	int x;
	cur = search(B->shoupai, JueDou);
	DeletList(B->shoupai, cur);
	attacked(A, B, JueDou);
	x = search(A->shoupai, WuXieKeJi);
	if (x)
	{
		DeletList(A->shoupai, x);
		attack(A, B, WuXieKeJi);
		return 0;
	}
	for (;;)
	{
		int a;
		int b;
		a = search(A->shoupai, Sha);
		if (a == 0)
		{
			A->wj->PH_current--;
			return 0;
		}
		DeletList(A->shoupai, a);
		attack(A, B, Sha);
		b = search(B->shoupai, Sha);
		if (b == 0)
		{
			B->wj->PH_current--;
			return 0;
		}
		DeletList(B->shoupai, b);
		attacked(A, B, Sha);
	}
}
int AI_nanmanruqin_skill(USER* A, USER* B)
{
	int a;
	int x;
	int cur;
	cur = search(B->shoupai, NanManRuQin);
	DeletList(B->shoupai, cur);
	attacked(A, B, NanManRuQin);
	x = search(A->shoupai, WuXieKeJi);
	if (x)
	{
		if (!DeletList(B->shoupai, x))
		{
			printf("AI南蛮入侵无懈可击失败");
		}
		attack(A, B, WuXieKeJi);
		return 0;
	}
	a = search(A->shoupai, Sha);
	if (a == 0)
	{
		A->wj->PH_current--;
		return 0;
	}
	else if (a)
	{
		DeletList(A->shoupai, a);
		attack(A, B, Sha);
	}
	return 0;
}
int AI_wanjianqifa_skill(USER* A, USER* B)
{
	int b;
	int x;
	int cur;
	cur = search(B->shoupai, WanJianQiFa);
	DeletList(B->shoupai, cur);
	attacked(A, B, WanJianQiFa);
	x = search(A->shoupai, WuXieKeJi);
	if (x)
	{
		DeletList(A->shoupai, x);
		attack(A, B, WuXieKeJi);
		return 0;
	}
	b = search(A->shoupai, Shan);
	if (b == 0)
	{
		A->wj->PH_current--;
		return 0;
	}
	else if (b)
	{
		DeletList(A->shoupai, b);
		attack(A, B, Shan);
	}
	return 0;
}
int AI_guohechaiqiao_skill(USER* A, USER* B)
{
	int x;
	int temp;
	int cur;
	cur = search(B->shoupai, GuoHeChaiQiao);
	DeletList(B->shoupai, cur);
	attacked(A, B, GuoHeChaiQiao);
	x = search(A->shoupai, WuXieKeJi);
	if (x)
	{
		DeletList(A->shoupai, x);
		attack(A, B, WuXieKeJi);
		return 0;
	}
	temp = A->shoupai->next->data->name;
	DeletList(A->shoupai, search(A->shoupai, temp));
	attack(A, B, temp);
	return 0;
}
int AI(USER* people, USER* ai)
{
	int num = ai->shoupai->length;
	BEG:
	if (ai->shoupai->length >=1)
	{
		Node* p = ai->shoupai->next; //此处已经是第一张牌
		if (p->data->name == NanManRuQin)
		{
			AI_nanmanruqin_skill(people, ai); goto BEG;
		}
		if (p->data->name == WanJianQiFa)
		{
			AI_wanjianqifa_skill(people, ai); goto BEG;
		}
		if (p->data->name == GuoHeChaiQiao)
		{
			AI_guohechaiqiao_skill(people, ai); goto BEG;
		}
		if (p->data->name == Tao)
		{
			if (ai->wj->PH_current < 4)
				AI_tao_skill(people, ai); goto BEG;
		}
		if (p->data->name == JueDou)
		{
			AI_juedou_skill(people, ai); goto BEG;
		}
		if (p->data->name == Sha)
		{
			AI_kill_skill(people, ai); goto BEG;
		}
		for (int i =2;i<=ai->shoupai->length;i++)
		{
			
			p = p->next;
			if (p->data->name == NanManRuQin)
			{
				AI_nanmanruqin_skill(people, ai); 
				if (people->wj->PH_current == 0) {
					return 1;
				}
				else if (people->wj->PH_current == 0)
				{
					return 2;
				}
				goto BEG;
			}
			if (p->data->name == WanJianQiFa)
			{
				AI_wanjianqifa_skill(people, ai); 
				if (people->wj->PH_current == 0) {
					return 1;
				}
				else if (people->wj->PH_current == 0)
				{
					return 2;
				}goto BEG;
			}
			if (p->data->name == GuoHeChaiQiao)
			{
				AI_guohechaiqiao_skill(people, ai); 
				if (people->wj->PH_current == 0) {
					return 1;
				}
				else if (people->wj->PH_current == 0)
				{
					return 2;
				}goto BEG;
			}
			if (p->data->name == Tao)
			{
				if (ai->wj->PH_current < 4)
					AI_tao_skill(people, ai); 
				if (people->wj->PH_current == 0) {
					return 1;
				}
				else if (people->wj->PH_current == 0)
				{
					return 2;
				}goto BEG;
			}
			if (p->data->name == JueDou)
			{
				AI_juedou_skill(people, ai);
				if (people->wj->PH_current == 0) {
					return 1;
				}
				else if (people->wj->PH_current == 0)
				{
					return 2;
				}goto BEG;
			}
			if (p->data->name == Sha)
			{
				AI_kill_skill(people, ai);
				if (people->wj->PH_current == 0) {
					return 1;
				}
				else if (people->wj->PH_current == 0)
				{
					return 2;
				}goto BEG;
			}
			
	}
	
			
	}
		Sleep(TIME);
	//} //现在就经获得牌了
	if (ai->shoupai->length > ai->wj->PH_current)//弃牌
	{
		Node* q = ai->shoupai->next;
		while (ai->shoupai->length - ai->wj->PH_current > 0)
		{
			DeletList(ai->shoupai, 1);
		}
		Sleep(TIME);
	}
	return 666;
} 