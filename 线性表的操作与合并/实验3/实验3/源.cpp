#include<iostream>
using namespace std;
#define MAXSIZE 5
typedef struct{
 int data;
 int cur;
}SLinkList[MAXSIZE];
int LocateElem(SLinkList S,int e)
{
 int i=S[0].cur;
 while(i&&S[i].data!=e) i=S[i].cur;
 return i;
}
int Length(SLinkList S)
{
 int j=0;
 for(int i=0;i<MAXSIZE;++i)
   j=S[i].cur;
 return j;
}
int main()
{
SLinkList L;
cout<<"Please enter SLinkList L";
cout<<endl;
for(int i=0;i<MAXSIZE;++i)
{
 cin>>L[i].data;
 L[i].cur=i+1;
}
cout<<"Please enter the elem!";
cout<<endl;
int X; cin>>X;
int I=LocateElem(L,X);
cout<<"The elem`s position is:";
cout<<endl;
cout<<I;
cout<<endl;
cout<<"The SLinkList L`s length is: ";
cout<<endl;
int A= Length(L);
cout<<A;
return 0;
}
