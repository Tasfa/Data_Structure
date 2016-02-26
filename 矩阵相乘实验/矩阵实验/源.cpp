#include<iostream>
#include<time.h>
using namespace std;
#define M 4
#define N 4
#define P 4
int main()
{    
	 clock_t start,finish;
   double totaltime;
   start=clock();
    //矩阵的输入
 int a[M][N];   
 int b[N][P];  
   for(int i=0;i<M;i++)
     for(int j=0;j<N;j++)
       cin>>a[i][j];
   for(int a=0;a<N;a++)
     for(int y=0;y<P;y++)
       cin>>b[a][y];
    //矩阵的相乘主运算
 int c[M][P];   
 int i,j,k;   
 for(i=0;i<M;i++)    
  for(j=0;j<P;j++)     
   c[i][j]=0;    
 for(i=0;i<M;i++)    
  for(j=0;j<P;j++)     
   for(k=0;k<N;k++)      
    c[i][j]+=a[i][k]*b[k][j];  
 //矩阵相乘运算输出结果
 cout<<"矩阵相乘结果是："<<endl;   
 for(i=0;i<M;i++)
 {   
  for(j=0;j<P;j++)       
   cout<<c[i][j]<<" ";     
  cout<<endl;    
 }  
  finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<"\n此程序的运行时间为"<<totaltime<<"秒！"<<endl;
 return 0;   
}