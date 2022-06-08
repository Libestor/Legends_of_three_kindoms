#include"internet.h"
#include"skills_cards.h"
#include"LinkList.h"
int AI_kill_skill(USER* A, USER* B, int cur)
{
	DeletList(A->shoupai, cur);
	attacked(A, B, Sha);
	int a;
	a = search(B->shoupai, Shan);
	if (a == 0)
	{
		B->wj->PH_current--;
	}
	else
	{
		DeletList(B->shoupai, a);
		attack(A, B, Sha);
	}
	return 0;
}
int AI_tao_skill(USER* A, USER* B, int cur)
{
	DeletList(A->shoupai, cur);
	A->wj->PH_current++;
	attacked(A, B, Tao);
	return 0;
}
int AI_juedou_skill(USER* A, USER* B, int cur)
{
	int x;
	DeletList(A->shoupai, cur);
	attacked(A, B, JueDou);
	x = search(B->shoupai, WuXieKeJi);
	if (x)
	{
		DeletList(B->shoupai, x);
		attack(A, B, WuXieKeJi);
		return 0;
	}
	for (;;)
	{
		int a;
		int b;
		a = search(B->shoupai, Sha);
		if (a == 0)
		{
			B->wj->PH_current--;
			return 0;
		}
		DeletList(B->shoupai, a);
		attack(A, B, Sha);
		b = search(A->shoupai, Sha);
		if (b == 0)
		{
			A->wj->PH_current--;
			return 0;
		}
		DeletList(A->shoupai, b);
		attacked(A, B, Sha);
	}
}
int AI_nanmanruqin_skill(USER* A, USER* B, int cur)
{
	int a;
	int x;
	DeletList(A->shoupai, cur);
	attacked(A, B, NanManRuQin);
	x = search(B->shoupai, WuXieKeJi);
	if (x)
	{
		DeletList(B->shoupai, x);
		attack(A, B, WuXieKeJi);
		return 0;
	}
	a = search(B->shoupai, Sha);
	if (a == 0)
	{
		B->wj->PH_current--;
	}
	else if (a)
	{
		DeletList(B->shoupai, a);
		attack(A, B, Sha);
	}
	return 0;
}
int AI_wanjianqifa_skill(USER* A, USER* B, int cur)
{
	int b;
	int x;
	DeletList(A->shoupai, cur);
	attacked(A, B, WanJianQiFa);
	x = search(B->shoupai, WuXieKeJi);
	if (x)
	{
		DeletList(B->shoupai, x);
		attack(A, B, WuXieKeJi);
		return 0;
	}
	b = search(B->shoupai, Shan);
	if (b == 0)
	{
		B->wj->PH_current--;
	}
	else if (b)
	{
		DeletList(B->shoupai, b);
		attack(A, B, Shan);
	}
	return 0;
}
int AI_guohechaiqiao_skill(USER* A, USER* B, int cur)
{
	int x;
	int temp;
	DeletList(A->shoupai, cur);
	attacked(A, B, GuoHeChaiQiao);
	x = search(B->shoupai, WuXieKeJi);
	if (x)
	{
		DeletList(B->shoupai, x);
		attack(A, B, WuXieKeJi);
		return 0;
	}
	temp = B->shoupai->next->data->name;
	DeletList(B->shoupai, search(B->shoupai, temp));
	attack(A, B, temp);
	return 0;
}
void AI(USER* people, USER* ai)
{
	int num = ai->shoupai->length;
	Node* p = ai->shoupai->next; //此处已经是第一张牌
	if (p->data->name == NanManRuQin)
	{
		AI_nanmanruqin_skill(people, ai, 1);
	}
	if (p->data->name == WanJianQiFa)
	{
		AI_wanjianqifa_skill(people, ai, 1);
	}
	if (p->data->name == GuoHeChaiQiao)
	{
		AI_guohechaiqiao_skill(people, ai, 1);
	}
	if (p->data->name == Tao)
	{
		if (ai->wj->PH_current < 4)
			AI_tao_skill(people, ai, 1);
	}
	if (p->data->name == JueDou)
	{
		AI_juedou_skill(people, ai, 1);
	}
	if (p->data->name == Sha)
	{
		AI_kill_skill(people, ai, 1);
	}
	for (int i = 2; i < num; i++)//出牌
	{
		p = p->next;
		if (p->data->name == NanManRuQin)
		{
			AI_nanmanruqin_skill(people, ai, 1);
		}
		if (p->data->name == WanJianQiFa)
		{
			AI_wanjianqifa_skill(people, ai, 1);
		}
		if (p->data->name == GuoHeChaiQiao)
		{
			AI_guohechaiqiao_skill(people, ai, 1);
		}
		if (p->data->name == Tao)
		{
			if (ai->wj->PH_current < 4)
				AI_tao_skill(people, ai, 1);
		}
		if (p->data->name == JueDou)
		{
			AI_juedou_skill(people, ai, 1);
		}
		if (p->data->name == Sha)
		{
			AI_kill_skill(people, ai, 1);
		}
		Sleep(100);
	} //现在就经获得牌了
	if (ai->shoupai->length > ai->wj->PH_current)//弃牌
	{
		Node* q = ai->shoupai->next;
		int n = ai->shoupai->length;
		int m = ai->wj->PH_current;
		int a, i;
		a = n - m;
		while (ai->shoupai->length - ai->wj->PH_current > 0)
		{
			DeletList(ai->shoupai, 1);
		}
		/*for (i = 0; i < a; i++)
		{
			if ((Shan != p->data->name || Tao != p->data->name) && p->next != NULL)
			{
				q = p;
				p = p->next;
			}
			if (Shan == p->data->name || Tao == p->data->name)
			{
				if (p == ai->shoupai->next)
				{
					ai->shoupai->next = p->next;
				}
				else
				{
					q->next = p->next;
				}
				free(p);
			}*/
		//}

	}
	Sleep(100);
}