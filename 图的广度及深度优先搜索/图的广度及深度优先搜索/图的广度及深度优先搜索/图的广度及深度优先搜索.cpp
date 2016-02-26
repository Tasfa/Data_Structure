#include <iostream> 
using namespace std;
#define  maxsize  1024   
# define n 100  

//typedef  int  datatype; 
//typedef char VEXTYPE; 
//typedef float ADJTYPE; 

typedef struct {   
	char vexs[n];  
    float arcs[n][n];   
	int num;      
}GRAPH;
//�ڽӾ����������� 


typedef  struct {  
	int data[maxsize];  
	int front,rear;    
}SEQQUEUE;
//������������
void GraphInit(GRAPH  *L)//�ÿ�ͼ 
     
{  L->num=0;  }  
int GraphVexs(GRAPH  *L)
//������ 
	{   return(L->num); } 

void GraphCreate(GRAPH  *L)//����ͼ
	{ 
		int i; 
		GraphInit(L);   
        cout<<"�����붥����Ŀ��"; 
	    cin>>L->num;
	    cout<<"��������������Ϣ(һ�����뵥������)��"; 
	    cout<<endl;
	for(i=0;i<L->num;i++)  
	{ 
		fflush(stdin);   
		cin>>L->vexs[i];
	} 
	cout<<"ͼ�Ѿ�������ϣ�"; 
    } 

	void GraphOut(GRAPH  L)//ͼ�����
	{
		int i;  
	cout<<"\nͼ�Ķ�����ĿΪ��"<<L.num;  
	cout<<"\nͼ�ĸ��������ϢΪ:"<<endl; 
	for(i=0;i<L.num;i++)   
		cout<<L.vexs[i]<<"   "; 
	} 

	void DFS(GRAPH  g,int qidian,int mark[])
		//�ӵ�qidian�������������ȱ���ͼg���ܷ��ʵĸ������� 
	{ 
		int v1; 
		mark[qidian]=1;  
		printf("%c   ",g.vexs[qidian]); 
	    for(v1=0;v1<g.num;v1++) 
		{  
			if(g.arcs[qidian][v1]!=0&&mark[v1]==0)   
				DFS(g,v1,mark); 
		} 
     
}  void GraphDFS(GRAPH  g)//������ȱ���ͼg���ܷ��ʵĸ������� 
	{ 
		int qidian,v,v1,mark[maxsize];
		printf("\n������ȱ�����"); 
		printf("\n��������������±꣺"); 
		scanf("%d",&qidian); 
   for(v=0;v<g.num;v++) 
   {   mark[v]=0;   } 
   for(v=qidian;v<g.num+qidian;v++) 
   {   v1=v%g.num;   if(mark[v1]==0)   
   DFS(g,v1,mark);   }  } 

void QueueInit(SEQQUEUE *sq)//�����ն���
{  
	sq->front=0;    sq->rear=0;
} 

int QueueIsEmpty(SEQQUEUE sq)//�ж϶����Ƿ�Ϊ�� 
{   
	if (sq.rear==sq.front)        return(1);  
	else   return(0);
}  

int QueueFront(SEQQUEUE sq,int *e)//�����ͷԪ�� 
{  if (QueueIsEmpty(sq))    
{      printf("queue is empty!\n");
return 0;}  
else   { *e=sq.data[(sq.front)];
return 1;} }  

int QueueIn (SEQQUEUE *sq,int x)//��Ԫ��x���β 
{  
	if(sq->front==(sq->rear+1)%maxsize)  
	{     printf("queue is full!\n");    
	return 0; 
    
 } 
	else 
	{      sq->data[sq->rear]=x; 
	sq->rear=(sq->rear+1)%maxsize;  
	return(1);   }  } 

int QueueOut(SEQQUEUE *sq)//ɾ������Ԫ�� 
{  
	if(QueueIsEmpty(*sq)) 
	{     printf("queue is empty!\n"); 
	return 0;   } 
else  {           sq->front=(sq->front+1)%maxsize;  
return  1;      } }  

void BFS(GRAPH g,int v,int mark[])//��v����������ȱ���ͼg���ܷ��ʵĸ�������
{   
	int v1,v2;  
        SEQQUEUE q; 
        QueueInit(&q); 
        QueueIn(&q,v); 
        mark[v]=1;  
      printf("%c   ",g.vexs[v]); 
 while(QueueIsEmpty(q)==0)  
  { 
	 QueueFront(q,&v1);  
	 QueueOut(&q);  
      for(v2=0;v2<g.num;v2++)   
       {  
	if(g.arcs[v1][v2]!=0&&mark[v2]==0){     
	  QueueIn(&q,v2);    
	  mark[v2]=1;  
      printf("%c   ",g.vexs[v2]);     }   
	    } 
    
  } 
}

void GraphBFS(GRAPH  g)//�����������ͼg���ܷ��ʵĸ������� 
{ 
	int qidian,v,v1,mark[maxsize];
	cout<<endl;
    cout<<"������ȱ�����";
    cout<<"\n��������������±꣺"; 
    scanf("%d",&qidian); 
    for(v=0;v<g.num;v++) 
{ 
	mark[v]=0; 
	}  
    for(v=qidian;v<g.num+qidian;v++) 
    {    v1=v%g.num;  
	     if(mark[v1]==0)   
		BFS(g,v1,mark);   } 
}

 void main()//������
 {  
	 GRAPH tu; 
	 GraphCreate(&tu); 
	 GraphOut(tu); 
	 GraphDFS(tu); 
	 GraphBFS(tu); 
	 printf("\n"); 
 }