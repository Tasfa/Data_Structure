#include<iostream>
#include<time.h>
using namespace std;

//实验一变量
#define M 4
#define N 4
#define P 4
//实验三变量
#define STACK_INIT_SIZE  100
#define STACKINCREMENT   10
//实验五变量
#define N2 4 
#define MaxSize 100
//实验六变量
#define MAXH 4
#define MAXL 4
#define MAX MAXH+MAXL
//实验九变量
#define  maxsize  1024   
# define n1 100  

//实验二定义
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;
//实验三定义
typedef struct
{
	char *base;
	char *top;
	int stacksize;
}SqStack;
//实验四定义
typedef struct {
	char *ch;
	int length;
}HString;
//实验五定义
typedef struct tupnode
{
 int r;
    int c;
 int d;
}TupNode;
typedef struct matrix
{
 TupNode data[MaxSize];
 int rows;
 int cols;
 int nums;
}TSMatrix;
//实验七定义
typedef struct BiTNode{
   char data;
   struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
//实验八定义
 typedef struct node {
           char data;
          struct node *lchild;
          struct node *rchild;
          }BiNode2,*BiTree2;
 typedef struct node1{
          BiTree2 data[30];     //默认30个元素 ，这里需要一个辅助堆栈！！！
          int top;
         }Stack;
//实验九定义
typedef struct { //邻接矩阵数据类型  
	char vexs[n1];  
    float arcs[n1][n1];   
	int num;      
}GRAPH;
typedef  struct {  //队列数据类型
	int data[maxsize];  
	int front,rear;    
}SEQQUEUE;



//实验一函数（矩阵相乘）
void Matrix_Multiply()
{
	clock_t start,finish;
      double totaltime;
      start=clock();
	  
    //矩阵的输入
 int a[M][N];   
 int b[N][P];  
 cout<<"请输入" << M<<"*"<<M<<"矩阵A："<<endl;
   for(int i=0;i<M;i++)
     for(int j=0;j<N;j++)
       cin>>a[i][j];
   cout<<"请输入" << M<<"*"<<M<<"矩阵B："<<endl;
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
 cout<<"矩阵A B相乘结果是："<<endl;   
 for(i=0;i<M;i++)
 {   
   for(j=0;j<P;j++)       
   cout<<c[i][j]<<" ";     
   cout<<endl;    
 }  
   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<"此程序的运行时间为"<<totaltime<<"秒！"<<endl;
}

//实验二函数(2.13 2.14 2.15)
void CreateList_L(LinkList &L, int n)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->data = 0;
	L->next = NULL; 
	for(int i = n; i > 0; -- i)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));
		cin >> p->data;
		p->next = L->next;
		L->next = p;
		L->data ++;
	}
}

int Locate(LinkList& L, int x)
{
	LinkList p = L->next;
	int pos = 1;
	while(p && p->data != x)
	{
		p = p->next;
		pos ++;
	}
	if(!p)
		return 0;
	else
		return pos;
}

int Length(LinkList &L)
{
	return L->data;
}

void Union(LinkList ha, LinkList hb, LinkList &hc)
{
	hc = (LinkList)malloc(sizeof(LNode));
	LinkList p;
	if(ha->data <= hb->data)
	{
		hc->data = ha->data + hb->data;
		hc->next = ha->next;
		p = hc;
		while(p->next)
			p = p->next;
		p->next = hb->next;
	}
	else
	{
		hc->data = ha->data + hb->data;
		hc->next = hb->next;
		p = hc;
		while(p->next)
			p = p->next;
		p->next = ha->next;
	}
}

void Linear_List_1()
{
	LinkList L;
	int n;
	int num, loc;

	cout << "输入要创建的单链表的结点个数：";
	cin >> n;

	cout << "输入单链表的各个结点的值(整型)：(从表尾到表头)" << endl;
	CreateList_L(L, n);
	
	cout << "该单链表的元素为：" << endl;
	LinkList p = L->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	cout << "输入你要查找的数：";
	cin >> num;

	//测试Locate函数
	loc = Locate(L, num);
	if(loc)
		cout << "该数在单链表中的位序为：" << loc << endl;
	else
		cout << "该单链表中不存在这个数" << endl;

	//测试Length函数
	cout << "该单链表的长度为：" << Length(L) << endl;
}

void Linear_List_2()
{
	LinkList ha, hb, hc;
	int m, n;

	cout << "分别输入A表和B表两个单链表的长度：";
	cin >> m >> n;

	cout << "输入A表的元素（从表尾到表头）" << endl;
	CreateList_L(ha, m);
	cout << "输入B表的元素（从表尾到表头）" << endl;
	CreateList_L(hb, n);
	
	cout << "A表的元素为：" << endl;
	LinkList p;
	p = ha->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	cout << "B表的元素为：" << endl;
	p = hb->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	Union(ha, hb, hc);

	cout << "将A表和B表合并后的C表元素为：" << endl;
	p = hc->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	cout << "C表的长度为：" << hc->data << endl;
}

//实验三函数（3.16 3.18）
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

void Carriage_Dispatch()
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
}

char Gettop(SqStack S,char e)
{
	if(S.top==S.base) return 1;
	e= *(S.top-1);
	return e;
}

int Bracket_Match()
{
	char brackets[100];
	cout<<"请输入括号表达式（只使用‘()’和‘[]’） :"<<endl;
	cin>>brackets;
	SqStack L;
	InitStack(L);
	if(brackets[0]==')'||brackets[0]==']')
	{cout<<"你输入了错误的表达式！ ";return 0;}
	for(int i=0;brackets[i];i++)
	{
		if(brackets[i]=='('||brackets[i]=='[')
			Push(L,brackets[i]);
		else 
		{
			if(brackets[i]==')')
				if(Gettop(L,brackets[i])=='(')
				{
					Pop(L,brackets[i]);
                
		     	}
				else {cout<<"该括号表达式无法成功配对！"<<endl;break;}
			else
				if(Gettop(L,brackets[i])=='[')
				{
					Pop(L,brackets[i]);
					
				}
				else {cout<<"该括号表达式无法成功配对！"<<endl;break;}
			}
			
		}
	if(L.top==L.base) 
		cout<<"该括号表达式成功配对！"<<endl;
	return 0;
}

//实验四函数（4.13 4.16）

int StrDelete(HString &S,int pos,int len)
{
	if(pos<0||len>S.length)  return 1;
	else
	{
		for(int i=pos+len;i<=S.length;i++)
			S.ch[i-len]=S.ch[i];

		  S.length-=len;
		 
	}
	return 0;
}

int StrCompare(HString S,HString T)
{
	for(int i=0;i<S.length&&i<T.length;++i)
		if(S.ch[i]!=T.ch[i])
			return S.ch[i]-T.ch[i];
	return S.length-T.length;


}

void String_Operate()
{
	HString Sone,Stwo;
	HString Sthree,Sfour;
	cout<<"从串Str_One中删除所有与串Str_Two相同的子串"<<endl;
	cout<<"请输入Str_One的长度:"<<endl;
	cin>>Sone.length;
	Sone.ch=(char*)malloc((Sone.length+1)*sizeof(char));
	cout<<"请输入Str_One的元素（连续输入）:"<<endl;
	cin>>Sone.ch;

	cout<<"请输入Str_Two的长度:"<<endl;
	cin>>Stwo.length;
	Stwo.ch=(char*)malloc((Stwo.length+1)*sizeof(char));
	cout<<"请输入Str_Two的元素（连续输入）:"<<endl;
	cin>>Stwo.ch;

	for(int i=0;i<Sone.length;i++)
	{
		if(Sone.ch[i]==Stwo.ch[0])
			{
				StrDelete(Sone,i,Stwo.length);
				}
		
	}
	cout<<"删除后结果为："<<endl;
	cout<<Sone.ch<<endl;
		cout<<endl;
	cout<<"实现串的基本操作StrCompare（S，T）"<<endl;
	cout<<"请输入Str_Three的长度:"<<endl;
	cin>>Sthree.length;
	Sthree.ch=(char*)malloc((Sthree.length+1)*sizeof(char));
	cout<<"请输入Str_Three的元素（连续输入）:"<<endl;
	cin>>Sthree.ch;

	cout<<"请输入Str_Four的长度:"<<endl;
	cin>>Sfour.length;
	Sfour.ch=(char*)malloc((Sfour.length+1)*sizeof(char));
	cout<<"请输入Str_Four的元素（连续输入）:"<<endl;
	cin>>Sfour.ch;
	cout<<"比较结果如下："<<endl;
	int returnvalue=StrCompare(Sthree,Sfour);
	if(returnvalue<0||returnvalue>0) cout<<"Str_Three is different form Str_Four!"<<endl;
	if(returnvalue==0) cout<<"Str_Three is the same as Str_Four!"<<endl;

}

//实验五函数（三元组转置）
void CreatMat(TSMatrix &t, int a[N2][N2])
{
 int i, j;
 t.rows=N2;
 t.cols=N2;
 t.nums = 0;
 for(i=0;i<N2;i++)
  for(j=0;j<N2;j++)
   if(a[i][j]!=0)
   {
    t.data[t.nums].r=i;
    t.data[t.nums].c=j;
    t.data[t.nums].d=a[i][j];
    t.nums++;
   }
}

void DispMat(TSMatrix t)
{
 int i;
 if(t.nums<=0)
  return;
 cout<<"行数  "<<"列数  "<<"元素总数"<<endl;
 cout<<" "<<t.rows<<"      "<<t.cols<<"       "<<t.nums<<endl;
 cout<<"-----------------------"<<endl;
 cout<<"所在行数  "<<"所在列数  "<<"元素"<<endl;
 for(i=0;i<t.nums;i++)
  cout<<"    "<<t.data[i].r<<"        "<<t.data[i].c<<"       "<<t.data[i].d<<endl;
}

void TranMat(TSMatrix tsa,TSMatrix &tsc)
{
 int p,q = 0,v;
 tsc.rows=tsa.cols;
 tsc.cols=tsa.rows;
 tsc.nums=tsa.nums;
 if(tsa.nums!=0)
 { 
  for(v=0;v<tsa.cols;v++)
   for(p=0;p<tsa.nums;p++)
    if(tsa.data[p].c==v)
    {
     tsc.data[q].r=tsa.data[p].c;
     tsc.data[q].c=tsa.data[p].r;
     tsc.data[q].d=tsa.data[p].d;
     q++;
    }
 }
}

void DispNN(TSMatrix t)
{
 int i,j,k,flag;
 for(i=0;i<t.rows;i++)
 {
  for(j=0;j<t.cols;j++)
  {
   flag=0;
   for(k=0;k<t.nums;k++)
    if((i==t.data[k].r)&&(j==t.data[k].c))
    {
     cout<<t.data[k].d<<' ';
     flag=1;
     break;
    }
       if(flag==0)
     cout<<"0"<<' ';
  }
  cout<<endl;
 }
}

void Triple_Transpose()
{
	cout<<"请输入"<<N2<<"*"<<N2<<"的稀疏矩阵:\n";
 int a[N2][N2];
 for(int i=0;i<N2;i++)
 {
	 for(int k=0;k<N2;k++)
	 {
		 cin>>a[i][k];
	 }
 }
 TSMatrix tsa,tsc;
 CreatMat(tsa,a);
 CreatMat(tsc, a);
 cout<<"a的三元组为："<<endl; 
 DispMat(tsa);
 cout<<"a转置后的三元组为："<<endl;
 TranMat(tsc,tsa);
 DispMat(tsa);
 cout<<"a转置后的结果矩阵为："<<endl;
 TranMat(tsa, tsc);
 DispNN(tsa);
}

//实验六函数（准对角矩阵存入一维数组）
void Quasi_Diagonal_Matrix()
{
	int Mat[MAXH][MAXL];
	int B[MAX];
	cout<<"请输入一个4*4准对角矩阵的非0元： "<<endl;

	for(int i=0;i<MAXH;i++)
			for(int j=0;j<MAXL;j++)
			{
				if(i%2==0)
				{
					if(i==j||i==(j-1))
					{
					cin>>Mat[i][j];
				    int k=i+j-(i%2);
				    B[k]=Mat[i][j];
					}
					else Mat[i][j]=0;
				}
				else
					if(i==j||j==(i-1))
				{
					cin>>Mat[i][j];
					 int k=i+j+(i%2);
				    B[k]=Mat[i][j];
				}
				else Mat[i][j]=0;
			}
			cout<<"该准对角矩阵如下所示："<<endl;
			for(int i=0;i<MAXH;i++)
			{
			 for(int j=0;j<MAXL;j++)
			 {
				 cout<<Mat[i][j];
			 }
			 cout<<endl;
			}

			cout<<"该矩阵存入一个一维数组如下："<<endl;
			for(int k=0;k<MAX;k++)
				cout<<B[k]<<" ";
}

//实验七函数（输出二叉树算术表达式）
 BiTree CreatBiTree() 
{ 
	
	BiTree T=NULL;
	T=(BiTree)malloc(sizeof(BiTNode));
   char ch;
   cin>>ch;
   if('#' == ch) T=NULL;
   else
   {
       T->data=ch;
       T->lchild=CreatBiTree();
       T->rchild=CreatBiTree();
	   return T;
   }
   return T;
}

int Visit(char ch)//访问根节点
{
 cout<<ch;
 return 0;
}

int InOrderTraverse(BiTree T,int (*Visit)(char d))//中序遍历
{
  if(T){
	  if(InOrderTraverse(T->lchild,Visit))Visit(T->data);
      if(Visit(T->data))Visit(T->data);
	  if(InOrderTraverse(T->rchild,Visit))Visit(T->data); 
	  return 0;
    return 1;
  }else return 0;
}

void Binary_Tree_Output()
{
	BiTree T=NULL;
    cout<<"请先序输入二叉树，‘#’代表空树：";
	cout<<endl;
    T =  CreatBiTree();
    cout<<"中序遍历序列为:";
	cout<<endl;
    InOrderTraverse(T,Visit);
}
//实验八函数（栈的先序及后序遍历的非递归算法）
void createTree(BiTree2 &T)   
  {
	  
      char ch;
      cin>>ch;
	  if (ch=='#') T=NULL;    
      else{
              T=(BiTree2)malloc(sizeof(BiNode2));
              T->data=ch;
              createTree(T->lchild);
              createTree(T->rchild);
            }
  }

  void initstack(Stack *&st)
 {
       st=(Stack *)malloc(sizeof(Stack));
       st->top=-1;
  }

  bool isempty(Stack *st)
  {
      return st->top==-1;
  }

  bool isfull(Stack *st)
  {
      return st->top==19;
  }

  void push(Stack *st,BiTree2 T)
  {
       if (!isfull(st))
      	st->data[++st->top]=T;     //栈顶指针始终指向堆栈最上面可用的一个元素，因此入栈时候，先要将指针加1,然后再执行入栈操作！
      else cout<<"已满"<<endl;
  }

  BiTree2 pop(Stack *st)
  {
       if (!isempty(st)) return st->data[st->top--];
return 0;  }

  BiTree2 gettop(Stack *st)
  {
         if (!isempty(st)) return st->data[st->top];  //出栈时，先取出栈顶指针指向的元素，然后再将指针减1，使其指向栈中下一个可用元素！
return 0;  }

  void preOrderNoRe(BiTree2 T)          // 前序遍历
  {
    Stack *st;
     initstack(st);
     BiTree2 p;
     p=T;
       while (p!=NULL||!isempty(st))
       {
             while (p!=NULL)
            {
                  cout<<p->data<<"  ";
                  push(st,p);
                  p=p->lchild;
             }
             if (!isempty(st))
           {
                        p=pop(st);
                        p=p->rchild;
            }
             
      }
  }

  void postOrderNoRe(BiTree2 T)          //后序遍历
  {
       BiTree2 p;
      Stack *st;
      initstack(st);
      p=T;
      int Tag[20];      //栈，用于标识从左（0）或右（1）返回 
      while (p!=NULL || !isempty(st))
      {
            while (p!=NULL)
            {
                  push(st,p);
                  Tag[st->top]=0;
                  p=p->lchild;
            }
           while (!isempty(st)&&Tag[st->top]==1)
            {
                  p=pop(st);
                  cout<<p->data<<"  ";
            }
            if (!isempty(st))
            {
                             Tag[st->top]=1;   //设置标记右子树已经访问 
                            p=gettop(st);
                            p=p->rchild;
           }
           else break;
     }
 }

  void Inn_Ergodic()
  {
	   
     BiNode2 *T;
	 cout<<"请先序输入二叉树（#表示空树）："<<endl;
     createTree(T);
     cout<<endl;
    
     cout<<"先序遍历: ";preOrderNoRe(T);cout<<endl;
    
     cout<<"后序遍历: ";postOrderNoRe(T);cout<<endl; 
     //system("pause");
  }

//实验九函数（图的广度及深度优先搜索）
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
     
} 

void GraphDFS(GRAPH  g)//深度优先遍历图g中能访问的各个顶点 
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

void Graph_DFS_and_BFS()
{
	GRAPH tu; 
	 GraphCreate(&tu); 
	 GraphOut(tu); 
	 GraphDFS(tu); 
	 GraphBFS(tu); 
	 printf("\n"); 
}


int main()
{    
	int Exit;
	cout<<"输入‘1’继续执行该程序，输入‘0’将结束该程序：";
	cin >>Exit;
	while(Exit!=0)
	{
	int Exp_Num;
	cout<<endl;
	cout<<"请输入您想要查看的实验（实验1-9）[0表示退出程序]："<<endl;
	cin>>Exp_Num;
	switch(Exp_Num){
	case 1:
	 cout<<"实验1（矩阵相乘）：\n\n"<<endl;
	     Matrix_Multiply();
	 cout<<endl;
	 break;
	case 2:
	 cout<<"实验2（线性表操作）：\n\n"<<endl;
	     Linear_List_1();
	     Linear_List_2();
	 cout<<endl;
	 break;
	case 3:
	 cout<<"实验3.16（车厢调度）：\n\n"<<endl;
	     Carriage_Dispatch();
	 cout<<endl;
	 cout<<"实验3.18（括号配对）：\n\n"<<endl;
	     Bracket_Match();
     cout<<endl;
	 break;
	case 4:
	 cout<<"实验4（串的删除及比较）：\n\n"<<endl;
	     String_Operate();
	 cout<<endl;
	 break;
	case 5:
	 cout<<"实验5（三元组转置）：\n\n"<<endl;
	     Triple_Transpose();
	 cout<<endl;
	 break;
	case 6:
	 cout<<"实验6（准对角矩阵存入一维数组）：\n\n"<<endl;
	     Quasi_Diagonal_Matrix();
	 cout<<endl;
	 cout<<endl;
	 break;
	case 7:
	 cout<<"实验7（二叉树表达式输出）：\n\n"<<endl;
	     Binary_Tree_Output();
	 cout<<endl;
	 cout<<endl;
    break;
	case 8:
	 cout<<"实验8（栈的先序及后序遍历的非递归算法）：\n\n"<<endl;
	     Inn_Ergodic();
	 cout<<endl;
	 break;
	case 9:
	 cout<<"实验9（图的广度及深度优先搜索）：\n\n"<<endl;
	    Graph_DFS_and_BFS();
		break;
	case 0: Exit=0;
		cout<<"成功退出程序！";break;
	}
	}
	 return 0;
}