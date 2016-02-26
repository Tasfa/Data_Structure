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

//实现Locate函数的算法
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

//实现Length函数的算法
int Length(LinkList &L)
{
	return L->data;
}

int main()
{
	LinkList L;
	int n;
	int num, loc;

	cout << "输入要创建的单链表的结点个数：";
	cin >> n;

	cout << "输入单链表的各个结点的值：(从表尾到表头)" << endl;
	CreateList_L(L, n);
	
	cout << "该单链表的元素为：" << endl;
	LinkList p = L->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	cout << "输入你要查找的数：";
	cin >> num;

	//测试Locate函数
	loc = Locate(L, num);
	if(loc)
		cout << "该数在单链表中的位序为：" << loc << endl;
	else
		cout << "该单链表中不存在这个数" << endl;

	//测试Length函数
	cout << "该单链表的长度为：" << Length(L) << endl;

	return 0;
}