#include"skills_cards.h"
#include"easyx.h"
#include""
WARLORD *zhangfei()//�ŷɵĳ�ʼ��
{
	WARLORD* zhangfei;
	zhangfei = (WARLORD*)malloc(sizeof(WARLORD));
	zhangfei->PH = 4;
	zhangfei->PH_current = 4;
	zhangfei->sha_num = 999;
	zhangfei->name = ZhangFei;
	return zhangfei;
}
WARLORD* dianwei()//��Τ�ĳ�ʼ��
{
	WARLORD* dianwei;
	dianwei = (WARLORD*)malloc(sizeof(WARLORD));
	dianwei->PH = 4;
	dianwei->PH_current = 4;
	dianwei->sha_num = 1;
	dianwei->name = DianWei;
	dianwei->skills = dianwei_skill;
	return dianwei;
}
int dianwei_skill(WARLORD* A, WARLORD* B)//��Τ���ܵĳ�ʼ��
{
	A->PH_current--;
	B->PH_current--;
	return 0;
}
CARDS* wuxiekeji()//������и�ɻ��Ļ�ɫ�͵���
{
	CARDS* wuxiekeji;
	wuxiekeji = (CARDS*)malloc(sizeof(CARDS));
	//srand((unsigned)time(NULL));
	wuxiekeji->color = rand() % 4+1;
	wuxiekeji->points = rand() % 13+1;
	wuxiekeji->name = WuXieKeJi;
	return wuxiekeji;
}
CARDS* kill()//����ɱ�Ļ�ɫ�͵���
{
	CARDS* kill;
	kill = (CARDS*)malloc(sizeof(CARDS));
	//srand((unsigned)time(NULL));
	kill->color = rand() % 4+1;
	kill->points = rand() % 13+1;//A 2 3 4 5 6 7 8 9 10 J Q K
	kill->skill = kill_skill;
	kill->name = Sha;
	return kill;
}
int kill_skill(USER* A, USER* B, int cur)//ɱ�Ĺ���
{
	delatenodelocate(A->shoupai, Sha);
	attack(A,B,Sha);
	int a;
	a = delatenodelocate(B->shoupai, Shan);
	if (a == 0)
	{
		B->wj->PH_current--;
	}
	else if (a == 1)
	{
		attacked(A, B, Sha);
	}
	return 0;
}
CARDS* shan()//�������Ļ�ɫ�͵���
{
	CARDS* shan;
	shan = (CARDS*)malloc(sizeof(CARDS));
	//srand((unsigned)time(NULL));
	shan->color = rand() % 4+1;
	shan->points = rand() % 13+1;
	shan->skill = shan_skill;
	shan->name = Shan;
	return shan;
}
int shan_skill(USER* A, USER* B, int cur)//���Ĺ���
{
	return 1;
}
CARDS* tao()//�����ҵĻ�ɫ�͵���
{
	CARDS* tao;
	tao = (CARDS*)malloc(sizeof(CARDS));
	//srand((unsigned)time(NULL));
	tao->color = rand() % 4+1;
	tao->points = rand() % 13+1;
	tao->skill = tao_skill;
	tao->name = Tao;
	return tao;
}
int tao_skill(USER* A, USER* B, int cur)//�ҵĹ���
{
	delatenodelocate(A->shoupai, Tao);
	attack(A, B, Tao);
	A->wj->PH_current++;
	return 0;
}
WARLORD* search_wujiang()//�����ȡ�佫
{
	int n;
	//srand((unsigned)time(NULL));
	n = rand() % 2+1;//1���ŷ� 2����Τ
	if (n == 1)
	{
		return zhangfei();
	}
	else if (n == 2)
	{
		return dianwei();
	}
	else return NULL;
}
CARDS* search_pai()//�����ȡ����
{
	int n;
	//srand((unsigned)time(NULL));
	n = rand() % 8+1;//1��ɱ 2���� 3���� 4:���� 5:����뷢 6���������� 7����и�ɻ� 8�����Ӳ���
	if (n == 1)
	{
		return kill();
	}
	else if (n == 2)
	{
		return shan();
	}
	else if (n == 3)
	{
		return tao();
	}
	else if (n == 4)
	{
		return juedou();
	}
	else if (n == 5)
	{
		return wanjianqifa();
	}
	else if (n == 6)
	{
		return nanmanruqin();
	}
	else if (n == 7)
	{
		return wuxiekeji();
	}
	else if (n == 8)
	{
		return guohechaiqiao();
	}
	else return NULL;
	
}
WARLORD* mustzhangfei()//���򷵻��ŷ�
{
	return zhangfei();
}
WARLORD* mustdianwei()//���򷵻ص�Τ
{
	return dianwei();
}
CARDS* mustkill()//���򷵻�ɱ
{
	return kill();
}
CARDS* mustshan()//���򷵻���
{
	return shan();
}
CARDS* musttao()//���򷵻���
{
	return tao();
}
CARDS* getcards(int i)
{
	if (i == Sha)
	{
		return kill();
	}
	else if (i == Shan)
	{
		return shan();
	}
	else if (i == Tao)
	{
		return tao();
	}
}
CARDS* juedou()//��������ĵ����ͻ�ɫ
{
	CARDS* juedou;
	juedou = (CARDS*)malloc(sizeof(CARDS));
	//srand((unsigned)time(NULL));
	juedou->color = rand() % 4+1;
	juedou->points = rand() % 13+1;
	juedou->skill = juedou_skill;
	juedou->name = JueDou;
	return juedou;
}
int juedou_skill(USER* A, USER* B,int cur)//��������Ĺ���
{
	int x;
	delatenodelocate(A->shoupai, JueDou);
	attack(A, B, JueDou);
	x = delatenodelocate(B->shoupai, WuXieKeJi);
	if (x == 1)
	{
		attacked(A, B, WuXieKeJi);
		return 0;
	}
	for (;;)
	{
		int a;
		int b;
		a = delatenodelocate(B->shoupai, Sha);
		if (a == 0)
		{
			B->wj->PH_current--;
			return 0;
		}
		attacked(A, B, Sha);
		b = delatenodelocate(A->shoupai, Sha);
		if (b == 0)
		{
			A->wj->PH_current--;
			return 0;
		}
		attack(A, B, Sha);
	}
}
CARDS* nanmanruqin()//�����������ֵĵ����ͻ�ɫ
{
	CARDS* nanmanruqin;
	nanmanruqin = (CARDS*)malloc(sizeof(CARDS));
	//srand((unsigned)time(NULL));
	nanmanruqin->color = rand() % 4+1;
	nanmanruqin->points = rand() % 13+1;
	nanmanruqin->skill = nanmanruqin_skill;
	nanmanruqin->name = NanManRuQin;
	return nanmanruqin;
}
int nanmanruqin_skill(USER* A, USER* B, int cur)//�����������ֵĹ���
{
	int a;
	int x;
	delatenodelocate(A->shoupai, NanManRuQin);
	attack(A, B, NanManRuQin);
	x = delatenodelocate(B->shoupai, WuXieKeJi);
	if (x == 1)
	{
		attacked(A, B, WuXieKeJi);
		return 0;
	}
	a = delatenodelocate(B->shoupai, Sha);
	if (a == 0)
	{
		B->wj->PH_current--;
	}
	else if (a == 1)
	{
		attacked(A, B, Sha);
	}
	return 0;
}
CARDS* wanjianqifa()//��������뷢�ĵ����ͻ�ɫ
{
	CARDS* wanjianqifa;
	wanjianqifa = (CARDS*)malloc(sizeof(CARDS));
	//srand((unsigned)time(NULL));
	wanjianqifa->color = rand() % 4+1;
	wanjianqifa->points = rand() % 13+1;
	wanjianqifa->skill = wanjianqifa_skill;
	wanjianqifa->name = WanJianQiFa;
	return wanjianqifa;
}
int wanjianqifa_skill(USER* A, USER* B, int cur)//��������뷢�Ĺ���
{
	int b;
	int x;
	delatenodelocate(A->shoupai, WanJianQiFa);
	attack(A, B, WanJianQiFa);
	x = delatenodelocate(B->shoupai, WuXieKeJi);
	if (x == 1)
	{
		attacked(A, B, WuXieKeJi);
		return 0;
	}
	b = delatenodelocate(B->shoupai, Shan);
	if (b == 0)
	{
		B->wj->PH_current--;
	}
	else if (b == 1)
	{
		attacked(A, B, Shan);
	}
	return 0;
}
int delatenodelocate(Head* head,int n)//ָ��ɾ������ڵ�
{
	Node* p = head->next;
	Node* pr = p;
	if (p->data->name == n )
	{
		head->next = p->next;
		free(p);
		head->length--;
		return 1;
	}
	p = p->next;
	pr = p;
	for (; p->data->name != n;)
	{
		pr = p;
		if (p->next == NULL)
		{
			return 0;
		}
		p = p->next;
	}
	pr->next = p->next;
	free(p);
	p = NULL;
	head->length--;
	return 1;
}//ָ��λ��ɾ���ڵ�
CARDS* guohechaiqiao()//������Ӳ��ŵĻ�ɫ�͵���
{
	CARDS* guohechaiqiao;
	guohechaiqiao = (CARDS*)malloc(sizeof(CARDS));
	//srand((unsigned)time(NULL));
	guohechaiqiao->color = rand() % 4+1;
	guohechaiqiao->points = rand() % 13+1;
	guohechaiqiao->name = GuoHeChaiQiao;
	guohechaiqiao->skill = guohechaiqiao_skill;
	return guohechaiqiao;
}
int guohechaiqiao_skill(USER* A, USER* B, int cur)//������Ӳ��ŵĹ���
{
	int x;
	int temp;
	delatenodelocate(A->shoupai, GuoHeChaiQiao);
	attack(A, B, GuoHeChaiQiao);
	x = delatenodelocate(B->shoupai, WuXieKeJi);
	if (x == 1)
	{
		attacked(A, B, WuXieKeJi);
		return 0;
	}
	temp = B->shoupai->next->data->name;
	free(B->shoupai->next);
	attacked(A, B, temp);
	return 0;
}
