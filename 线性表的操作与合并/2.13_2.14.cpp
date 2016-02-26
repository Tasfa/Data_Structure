#include <iostream>

using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;

void CreateList_L(LinkList &L, int n)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->data = 0;
	L->next = NULL; 
	for(int i = n; i > 0; -- i)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));
		cin >> p->data;
		p->next = L->next;
		L->next = p;
		L->data ++;
	}
}

//ʵ��Locate�������㷨
int Locate(LinkList& L, int x)
{
	LinkList p = L->next;
	int pos = 1;
	while(p && p->data != x)
	{
		p = p->next;
		pos ++;
	}
	if(!p)
		return 0;
	else
		return pos;
}

//ʵ��Length�������㷨
int Length(LinkList &L)
{
	return L->data;
}

int main()
{
	LinkList L;
	int n;
	int num, loc;

	cout << "����Ҫ�����ĵ�����Ľ�������";
	cin >> n;

	cout << "���뵥����ĸ�������ֵ��(�ӱ�β����ͷ)" << endl;
	CreateList_L(L, n);
	
	cout << "�õ������Ԫ��Ϊ��" << endl;
	LinkList p = L->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	cout << "������Ҫ���ҵ�����";
	cin >> num;

	//����Locate����
	loc = Locate(L, num);
	if(loc)
		cout << "�����ڵ������е�λ��Ϊ��" << loc << endl;
	else
		cout << "�õ������в����������" << endl;

	//����Length����
	cout << "�õ�����ĳ���Ϊ��" << Length(L) << endl;

	return 0;
}