#include <iostream>
#include <list>

using namespace std;

struct LNode
{
	int value;
	struct LNode *next;
};

void CreateList(LNode *&L,int a[],int len)
{
	LNode *p, *r;
	L = new LNode();
	p = L->next;
	r = L;
	for (int i = 0; i < len; i++)
	{
		p = new LNode();
		p->value = a[i];
		r->next = p;
		r = p;
	}
	r->next = nullptr;
}

void Disp(LNode *L)
{
	if (L == nullptr)
		return;
	LNode *p = L->next;
	while (p)
	{
		cout << p->value<<" ";
		p = p->next;
	}
}

void ReserveList(LNode *&L)
{
	if (L == nullptr)
		return;
	LNode *pre, *cur, *ne;
	pre = nullptr;
	cur = L->next;
	L->next = nullptr;
	while (cur)
	{
		ne = cur->next;
		cur->next = pre;
		pre = cur;
		cur = ne;
	}
	L->next = pre;
}

int main()
{
	LNode *L=nullptr;
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(a) / sizeof(int);
	CreateList(L, a, n);
	Disp(L);
	cout << endl;
	ReserveList(L);
	Disp(L);
	return 0;
}