#include<iostream>

using namespace std;
#define MAXH 4
#define MAXL 4
#define MAX MAXH+MAXL
int main()
{
	int M[MAXH][MAXL];
	int B[MAX];
	cout<<"������һ��4*4׼�ԽǾ���ķ�0Ԫ�� "<<endl;

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
			cout<<"��׼�ԽǾ���������ʾ��"<<endl;
			for(int i=0;i<MAXH;i++)
			{
			 for(int j=0;j<MAXL;j++)
			 {
				 cout<<M[i][j];
			 }
			 cout<<endl;
			}

			cout<<"�þ������һ��һά�������£�"<<endl;
			for(int k=0;k<MAX;k++)
				cout<<B[k]<<" ";
			return 0;
}