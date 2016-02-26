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

 int main()
 {
	 SqStack L;
	 InitStack(L);
     char Seat_category[100];
	 cout<<"请输入列车座位种类（H：硬座 S：软座）：";
     cout<<endl;
	 cin>>Seat_category;

	//Handle the Seat_category
    int i=0 ,j=0;
	for(i=j=0;Seat_category[i];i++)
	{
		if(Seat_category[i]=='H')
		{
			Push(L,Seat_category[i]);
			
		}
		else
		{
			Seat_category[j]=Seat_category[i];
			j++;
		}
	}
	 for(;Seat_category[j];j++)
	 
            Pop(L,Seat_category[j]);
		

	 cout<<"车厢调度后输出如下：\n";
	 cout<<Seat_category<<endl;
	
	 return 0;
 }