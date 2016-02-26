#include<iostream>
using namespace std;
#define LIST_INIT_SIZE 5
#define LISTINCREMENT 3
typedef struct{
 int *p;
 int length;
 int listsize;
}SqList;
void IntitList_Sq(SqList&l){
 l.p=(int*)malloc(LIST_INIT_SIZE*sizeof(int));
 if(!l.p)exit(OVERFLOW);
 l.length=0;
 l.listsize=LIST_INIT_SIZE;
}
int listinsert_Sq(SqList&l,int i,int e){
 if(i<1||i>l.length) return 1;
 if(l.length>=l.listsize){
  int* newbase=(int*)realloc(l.p,(l.listsize+LISTINCREMENT)*sizeof(int));
  if(!newbase)exit(OVERFLOW);
  l.p=newbase;
  l.listsize+=LISTINCREMENT;
 }
 int *q;q=&(l.p[i-1]);
 for(int *P=&(l.p[l.length-1]);P>=q;--P)
  *(P+1)=*P;
 *q=e;
 ++l.length;
 return 0;
}
void MergeList(SqList La,SqList Lb,SqList &Lc)
{
	int *pa=La.p;int *pb=Lb.p;
	Lc.listsize=Lc.length=La.length+Lb.length;
	int *pc=Lc.p=(int *)malloc(Lc.listsize*sizeof(int));
	if(!Lc.p)exit(OVERFLOW);
	int *Pa_past=La.p+La.length-1;
	int *Pb_past=Lb.p+Lb.length-1;
	while(pa<=Pa_past&&pb<=Pb_past)
	{
		if(*pa<=*pb)  *pc++=*pa++;
		else *pc++=*pb++;
	}
	while(pa<=Pa_past)  *pc++=*pa++;
	while(pb<=Pb_past)  *pc++=*pb++;
}
int main()
{
	cout<<"请输入你想要插入的元素（整型）："; 
	cout<<endl;
	int E; cin>>E;
	cout<<"Please enter your elem`s position!";
	cout<<endl;
    int I; cin>>I;
 SqList L,L2,L3;
 IntitList_Sq(L);IntitList_Sq(L2);IntitList_Sq(L3);
 cout<<"Please enter SqList L!";cout<<endl;
   L.length =0;
  for(int j=0;j<LISTINCREMENT;++j){
   cin>>L.p[j];
   ++L.length;
  }
  listinsert_Sq(L,I,E);
  cout<<"The output is as follow";cout<<endl;
  for(int a=0;a<L.length;++a){
   cout<<L.p[a];
  cout<<endl;
  }
  cout<<"Please enter SqList L2!";cout<<endl;
   L2.length =0;
  for(int j=0;j<LISTINCREMENT;++j){
   cin>>L2.p[j];
   ++L2.length;
  }
  MergeList(L,L2,L3);
  for(int b=0;b<L3.length;++b){
   cout<<L3.p[b];
  cout<<endl;
  }
 return 0;
}
