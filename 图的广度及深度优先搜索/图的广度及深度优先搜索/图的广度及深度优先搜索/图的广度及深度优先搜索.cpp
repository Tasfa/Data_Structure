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
//邻接矩阵数据类型 


typedef  struct {  
	int data[maxsize];  
	int front,rear;    
}SEQQUEUE;
//队列数据类型
void GraphInit(GRAPH  *L)//置空图 
     
{  L->num=0;  }  
int GraphVexs(GRAPH  *L)
//求结点数 
	{   return(L->num); } 

void GraphCreate(GRAPH  *L)//创建图
	{ 
		int i; 
		GraphInit(L);   
        cout<<"请输入顶点数目："; 
	    cin>>L->num;
	    cout<<"请输入各顶点的信息(一行输入单个符号)："; 
	    cout<<endl;
	for(i=0;i<L->num;i++)  
	{ 
		fflush(stdin);   
		cin>>L->vexs[i];
	} 
	cout<<"图已经创建完毕！"; 
    } 

	void GraphOut(GRAPH  L)//图的输出
	{
		int i;  
	cout<<"\n图的顶点数目为："<<L.num;  
	cout<<"\n图的各顶点的信息为:"<<endl; 
	for(i=0;i<L.num;i++)   
		cout<<L.vexs[i]<<"   "; 
	} 

	void DFS(GRAPH  g,int qidian,int mark[])
		//从第qidian个点出发深度优先遍历图g中能访问的各个顶点 
	{ 
		int v1; 
		mark[qidian]=1;  
		printf("%c   ",g.vexs[qidian]); 
	    for(v1=0;v1<g.num;v1++) 
		{  
			if(g.arcs[qidian][v1]!=0&&mark[v1]==0)   
				DFS(g,v1,mark); 
		} 
     
}  void GraphDFS(GRAPH  g)//深度优先遍历图g中能访问的各个顶点 
	{ 
		int qidian,v,v1,mark[maxsize];
		printf("\n深度优先遍历："); 
		printf("\n请输入遍历起点的下标："); 
		scanf("%d",&qidian); 
   for(v=0;v<g.num;v++) 
   {   mark[v]=0;   } 
   for(v=qidian;v<g.num+qidian;v++) 
   {   v1=v%g.num;   if(mark[v1]==0)   
   DFS(g,v1,mark);   }  } 

void QueueInit(SEQQUEUE *sq)//建立空队列
{  
	sq->front=0;    sq->rear=0;
} 

int QueueIsEmpty(SEQQUEUE sq)//判断队列是否为空 
{   
	if (sq.rear==sq.front)        return(1);  
	else   return(0);
}  

int QueueFront(SEQQUEUE sq,int *e)//保存队头元素 
{  if (QueueIsEmpty(sq))    
{      printf("queue is empty!\n");
return 0;}  
else   { *e=sq.data[(sq.front)];
return 1;} }  

int QueueIn (SEQQUEUE *sq,int x)//把元素x入队尾 
{  
	if(sq->front==(sq->rear+1)%maxsize)  
	{     printf("queue is full!\n");    
	return 0; 
    
 } 
	else 
	{      sq->data[sq->rear]=x; 
	sq->rear=(sq->rear+1)%maxsize;  
	return(1);   }  } 

int QueueOut(SEQQUEUE *sq)//删除队首元素 
{  
	if(QueueIsEmpty(*sq)) 
	{     printf("queue is empty!\n"); 
	return 0;   } 
else  {           sq->front=(sq->front+1)%maxsize;  
return  1;      } }  

void BFS(GRAPH g,int v,int mark[])//从v出发广度优先遍历图g中能访问的各个顶点
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

void GraphBFS(GRAPH  g)//深度优先周游图g中能访问的各个顶点 
{ 
	int qidian,v,v1,mark[maxsize];
	cout<<endl;
    cout<<"广度优先遍历：";
    cout<<"\n请输入遍历起点的下标："; 
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

 void main()//主函数
 {  
	 GRAPH tu; 
	 GraphCreate(&tu); 
	 GraphOut(tu); 
	 GraphDFS(tu); 
	 GraphBFS(tu); 
	 printf("\n"); 
 }