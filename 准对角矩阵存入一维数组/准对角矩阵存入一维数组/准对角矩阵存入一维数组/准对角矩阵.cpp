#include<iostream>

using namespace std;
#define MAXH 4
#define MAXL 4
#define MAX MAXH+MAXL
int main()
{
	int M[MAXH][MAXL];
	int B[MAX];
	cout<<"请输入一个4*4准对角矩阵的非0元： "<<endl;

	for(int i=0;i<MAXH;i++)
			for(int j=0;j<MAXL;j++)
			{
				if(i%2==0)
				{
					if(i==j||i==(j-1))
					{
					cin>>M[i][j];
				    int k=i+j-(i%2);
				    B[k]=M[i][j];
					}
					else M[i][j]=0;
				}
				else
					if(i==j||j==(i-1))
				{
					cin>>M[i][j];
					 int k=i+j+(i%2);
				    B[k]=M[i][j];
				}
				else M[i][j]=0;
			}
			cout<<"该准对角矩阵如下所示："<<endl;
			for(int i=0;i<MAXH;i++)
			{
			 for(int j=0;j<MAXL;j++)
			 {
				 cout<<M[i][j];
			 }
			 cout<<endl;
			}

			cout<<"该矩阵存入一个一维数组如下："<<endl;
			for(int k=0;k<MAX;k++)
				cout<<B[k]<<" ";
			return 0;
}