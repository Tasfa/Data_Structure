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

//实现两个单链表连接的算法，其时间复杂度为min(m, n)，m为A表长，n为B表长
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

	cout << "分别输入A表和B表两个单链表的长度：";
	cin >> m >> n;

	cout << "输入A表的元素（从表尾到表头）" << endl;
	CreateList_L(ha, m);
	cout << "输入B表的元素（从表尾到表头）" << endl;
	CreateList_L(hb, n);
	
	cout << "A表的元素为：" << endl;
	LinkList p;
	p = ha->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	cout << "B表的元素为：" << endl;
	p = hb->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	Union(ha, hb, hc);

	cout << "将A表和B表合并后的C表元素为：" << endl;
	p = hc->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	cout << "C表的长度为：" << hc->data << endl;

	return 0;
}