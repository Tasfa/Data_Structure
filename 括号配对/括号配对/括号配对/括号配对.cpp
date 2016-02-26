#include<iostream>

#define STACK_INIT_SIZE  100
#define STACKINCREMENT   10

using namespace std;

typedef struct
{
	char *base;
	char *top;
	int stacksize;
}SqStack;

int InitStack(SqStack &S)
{
	S.base=(char*)malloc(STACK_INIT_SIZE*sizeof(char));
	if(!S.base)
		exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return 0;
} 

int Push(SqStack &S,char e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(char*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(char));
		if(!S.base)
			exit(OVERFLOW);
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return 0;
}

int Pop(SqStack &S,char &e)
{
	if(S.top==S.base)
		return 1;
	e=*--S.top;
	return 0;
}
char Gettop(SqStack S,char e)
{
	if(S.top==S.base) return 1;
	e= *(S.top-1);
	return e;
}
int main()
{
	char brackets[100];
	cout<<"���������ű��ʽ��ֻʹ�á�()���͡�[]���� :"<<endl;
	cin>>brackets;
	SqStack L;
	InitStack(L);
	if(brackets[0]==')'||brackets[0]==']')
	{cout<<"�������˴���ı��ʽ�� ";return 0;}
	for(int i=0;brackets[i];i++)
	{
		if(brackets[i]=='('||brackets[i]=='[')
			Push(L,brackets[i]);
		else 
		{
			if(brackets[i]==')')
				if(Gettop(L,brackets[i])=='(')
				{
					Pop(L,brackets[i]);
                
		     	}
				else {cout<<"�����ű��ʽ�޷��ɹ���ԣ�"<<endl;break;}
			else
				if(Gettop(L,brackets[i])=='[')
				{
					Pop(L,brackets[i]);
					
				}
				else {cout<<"�����ű��ʽ�޷��ɹ���ԣ�"<<endl;break;}
			}
			
		}
	if(L.top==L.base) 
		cout<<"�����ű��ʽ�ɹ���ԣ�"<<endl;
	return 0;
}