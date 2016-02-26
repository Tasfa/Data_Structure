#include<iostream>
using namespace std;
#define MAXSIZE 5
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

int LocateElem(LinkList *S,int e)
{
	int j=0;
	for(int i=0;i<MAXSIZE;i++)
	{
		if(e==S[i]->data)
	    return j;
		else j++;
	}
	return 0;
}

int main()
{
	LinkList *s;
    cout<<"Please enter the elem ";
	cout<<endl;
	for(int i=0;i<MAXSIZE;i++)
		cin>>s[i]->data;
	
	cout<<"Please enter the elem you want to find:";
	cout<<endl;
	int E;cin>>E;
	int I;cin>>I;
    I=LocateElem(s,E);
	cout<<I;
	return 0;
}