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

//ʵ���������������ӵ��㷨����ʱ�临�Ӷ�Ϊmin(m, n)��mΪA����nΪB��
void Union(LinkList ha, LinkList hb, LinkList &hc)
{
	hc = (LinkList)malloc(sizeof(LNode));
	LinkList p;
	if(ha->data <= hb->data)
	{
		hc->data = ha->data + hb->data;
		hc->next = ha->next;
		p = hc;
		while(p->next)
			p = p->next;
		p->next = hb->next;
	}
	else
	{
		hc->data = ha->data + hb->data;
		hc->next = hb->next;
		p = hc;
		while(p->next)
			p = p->next;
		p->next = ha->next;
	}
}

int main()
{
	LinkList ha, hb, hc;
	int m, n;

	cout << "�ֱ�����A���B������������ĳ��ȣ�";
	cin >> m >> n;

	cout << "����A���Ԫ�أ��ӱ�β����ͷ��" << endl;
	CreateList_L(ha, m);
	cout << "����B���Ԫ�أ��ӱ�β����ͷ��" << endl;
	CreateList_L(hb, n);
	
	cout << "A���Ԫ��Ϊ��" << endl;
	LinkList p;
	p = ha->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	cout << "B���Ԫ��Ϊ��" << endl;
	p = hb->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	Union(ha, hb, hc);

	cout << "��A���B��ϲ����C��Ԫ��Ϊ��" << endl;
	p = hc->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	cout << "C��ĳ���Ϊ��" << hc->data << endl;

	return 0;
}