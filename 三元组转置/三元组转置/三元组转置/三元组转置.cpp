#include<iostream>

#define MAXSIZE 12500
using namespace std;
typedef struct
{
	int i,j;
	int e;
}Triple;
typedef struct
{
	Triple data[MAXSIZE+1];
	int mu,nu,tu;
}TSMatrix;

int TransposeSMatrix(TSMatrix M,TSMatrix &T)
{
	T.mu=M.nu;T.nu=M.mu;T.tu=M.tu;
	if(T.tu)
	{
		int q=1;
		for(int col=1;col<=M.nu;++col)
			for(int p=1;p<=M.tu;++p)
				if(M.data[p].j==col)
				{
					T.data[q].i=M.data[p].j;
					T.data[q].j=M.data[p].i;
					T.data[q].e=M.data[p].e;
					++q;
				}
	}
	return 0;
}
int main()
{
	TSMatrix TS1,TS2;
	cout<<"请输入TS1的行数、列数、非零个数:"<<endl;
	cin>>TS1.mu;
	cin>>TS1.nu;
	cin>>TS1.tu;
	int x;int i=1;
	cout<<"请输入TS1的非零元素及其坐标(i,j):"<<endl;
	while(cin>>x)
	{	TS1.data[i].e=x;
	cin>>TS1.data[i].i;
	cin>>TS1.data[i].j;
		++i;
	}

	TransposeSMatrix(TS1,TS2);
	for(int t=1;t<=TS2.tu;++t)
	for(int m=1,int n=1;m<=TS2.mu||n<=TS2.nu;++m,++n)
		

		
	
			if(TS2.data[t].i==m&&TS2.data[t].j==n)
             cout<<TS2.data[t].e;
			
		
			
		
		
	return 0;
}
