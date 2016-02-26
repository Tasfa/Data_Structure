#include<iostream>
#include<time.h>
using namespace std;

//ʵ��һ����
#define M 4
#define N 4
#define P 4
//ʵ��������
#define STACK_INIT_SIZE  100
#define STACKINCREMENT   10
//ʵ�������
#define N2 4 
#define MaxSize 100
//ʵ��������
#define MAXH 4
#define MAXL 4
#define MAX MAXH+MAXL
//ʵ��ű���
#define  maxsize  1024   
# define n1 100  

//ʵ�������
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;
//ʵ��������
typedef struct
{
	char *base;
	char *top;
	int stacksize;
}SqStack;
//ʵ���Ķ���
typedef struct {
	char *ch;
	int length;
}HString;
//ʵ���嶨��
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
//ʵ���߶���
typedef struct BiTNode{
   char data;
   struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
//ʵ��˶���
 typedef struct node {
           char data;
          struct node *lchild;
          struct node *rchild;
          }BiNode2,*BiTree2;
 typedef struct node1{
          BiTree2 data[30];     //Ĭ��30��Ԫ�� ��������Ҫһ��������ջ������
          int top;
         }Stack;
//ʵ��Ŷ���
typedef struct { //�ڽӾ�����������  
	char vexs[n1];  
    float arcs[n1][n1];   
	int num;      
}GRAPH;
typedef  struct {  //������������
	int data[maxsize];  
	int front,rear;    
}SEQQUEUE;



//ʵ��һ������������ˣ�
void Matrix_Multiply()
{
	clock_t start,finish;
      double totaltime;
      start=clock();
	  
    //���������
 int a[M][N];   
 int b[N][P];  
 cout<<"������" << M<<"*"<<M<<"����A��"<<endl;
   for(int i=0;i<M;i++)
     for(int j=0;j<N;j++)
       cin>>a[i][j];
   cout<<"������" << M<<"*"<<M<<"����B��"<<endl;
   for(int a=0;a<N;a++)
     for(int y=0;y<P;y++)
       cin>>b[a][y];
    //��������������
 int c[M][P];   
 int i,j,k;   
 for(i=0;i<M;i++)    
  for(j=0;j<P;j++)     
   c[i][j]=0;    
 for(i=0;i<M;i++)    
  for(j=0;j<P;j++)     
   for(k=0;k<N;k++)      
    c[i][j]+=a[i][k]*b[k][j];  
 //�����������������
 cout<<"����A B��˽���ǣ�"<<endl;   
 for(i=0;i<M;i++)
 {   
   for(j=0;j<P;j++)       
   cout<<c[i][j]<<" ";     
   cout<<endl;    
 }  
   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   cout<<"�˳��������ʱ��Ϊ"<<totaltime<<"�룡"<<endl;
}

//ʵ�������(2.13 2.14 2.15)
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

	cout << "����Ҫ�����ĵ�����Ľ�������";
	cin >> n;

	cout << "���뵥����ĸ�������ֵ(����)��(�ӱ�β����ͷ)" << endl;
	CreateList_L(L, n);
	
	cout << "�õ������Ԫ��Ϊ��" << endl;
	LinkList p = L->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	cout << "������Ҫ���ҵ�����";
	cin >> num;

	//����Locate����
	loc = Locate(L, num);
	if(loc)
		cout << "�����ڵ������е�λ��Ϊ��" << loc << endl;
	else
		cout << "�õ������в����������" << endl;

	//����Length����
	cout << "�õ�����ĳ���Ϊ��" << Length(L) << endl;
}

void Linear_List_2()
{
	LinkList ha, hb, hc;
	int m, n;

	cout << "�ֱ�����A���B������������ĳ��ȣ�";
	cin >> m >> n;

	cout << "����A���Ԫ�أ��ӱ�β����ͷ��" << endl;
	CreateList_L(ha, m);
	cout << "����B���Ԫ�أ��ӱ�β����ͷ��" << endl;
	CreateList_L(hb, n);
	
	cout << "A���Ԫ��Ϊ��" << endl;
	LinkList p;
	p = ha->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	cout << "B���Ԫ��Ϊ��" << endl;
	p = hb->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	Union(ha, hb, hc);

	cout << "��A���B��ϲ����C��Ԫ��Ϊ��" << endl;
	p = hc->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	cout << "C��ĳ���Ϊ��" << hc->data << endl;
}

//ʵ����������3.16 3.18��
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
	 cout<<"�������г���λ���ࣨH��Ӳ�� S����������";
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
		

	 cout<<"������Ⱥ�������£�\n";
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
	cout<<"���������ű��ʽ��ֻʹ�á�()���͡�[]���� :"<<endl;
	cin>>brackets;
	SqStack L;
	InitStack(L);
	if(brackets[0]==')'||brackets[0]==']')
	{cout<<"�������˴���ı��ʽ�� ";return 0;}
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
				else {cout<<"�����ű��ʽ�޷��ɹ���ԣ�"<<endl;break;}
			else
				if(Gettop(L,brackets[i])=='[')
				{
					Pop(L,brackets[i]);
					
				}
				else {cout<<"�����ű��ʽ�޷��ɹ���ԣ�"<<endl;break;}
			}
			
		}
	if(L.top==L.base) 
		cout<<"�����ű��ʽ�ɹ���ԣ�"<<endl;
	return 0;
}

//ʵ���ĺ�����4.13 4.16��

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
	cout<<"�Ӵ�Str_One��ɾ�������봮Str_Two��ͬ���Ӵ�"<<endl;
	cout<<"������Str_One�ĳ���:"<<endl;
	cin>>Sone.length;
	Sone.ch=(char*)malloc((Sone.length+1)*sizeof(char));
	cout<<"������Str_One��Ԫ�أ��������룩:"<<endl;
	cin>>Sone.ch;

	cout<<"������Str_Two�ĳ���:"<<endl;
	cin>>Stwo.length;
	Stwo.ch=(char*)malloc((Stwo.length+1)*sizeof(char));
	cout<<"������Str_Two��Ԫ�أ��������룩:"<<endl;
	cin>>Stwo.ch;

	for(int i=0;i<Sone.length;i++)
	{
		if(Sone.ch[i]==Stwo.ch[0])
			{
				StrDelete(Sone,i,Stwo.length);
				}
		
	}
	cout<<"ɾ������Ϊ��"<<endl;
	cout<<Sone.ch<<endl;
		cout<<endl;
	cout<<"ʵ�ִ��Ļ�������StrCompare��S��T��"<<endl;
	cout<<"������Str_Three�ĳ���:"<<endl;
	cin>>Sthree.length;
	Sthree.ch=(char*)malloc((Sthree.length+1)*sizeof(char));
	cout<<"������Str_Three��Ԫ�أ��������룩:"<<endl;
	cin>>Sthree.ch;

	cout<<"������Str_Four�ĳ���:"<<endl;
	cin>>Sfour.length;
	Sfour.ch=(char*)malloc((Sfour.length+1)*sizeof(char));
	cout<<"������Str_Four��Ԫ�أ��������룩:"<<endl;
	cin>>Sfour.ch;
	cout<<"�ȽϽ�����£�"<<endl;
	int returnvalue=StrCompare(Sthree,Sfour);
	if(returnvalue<0||returnvalue>0) cout<<"Str_Three is different form Str_Four!"<<endl;
	if(returnvalue==0) cout<<"Str_Three is the same as Str_Four!"<<endl;

}

//ʵ���庯������Ԫ��ת�ã�
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
 cout<<"����  "<<"����  "<<"Ԫ������"<<endl;
 cout<<" "<<t.rows<<"      "<<t.cols<<"       "<<t.nums<<endl;
 cout<<"-----------------------"<<endl;
 cout<<"��������  "<<"��������  "<<"Ԫ��"<<endl;
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
	cout<<"������"<<N2<<"*"<<N2<<"��ϡ�����:\n";
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
 cout<<"a����Ԫ��Ϊ��"<<endl; 
 DispMat(tsa);
 cout<<"aת�ú����Ԫ��Ϊ��"<<endl;
 TranMat(tsc,tsa);
 DispMat(tsa);
 cout<<"aת�ú�Ľ������Ϊ��"<<endl;
 TranMat(tsa, tsc);
 DispNN(tsa);
}

//ʵ����������׼�ԽǾ������һά���飩
void Quasi_Diagonal_Matrix()
{
	int Mat[MAXH][MAXL];
	int B[MAX];
	cout<<"������һ��4*4׼�ԽǾ���ķ�0Ԫ�� "<<endl;

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
			cout<<"��׼�ԽǾ���������ʾ��"<<endl;
			for(int i=0;i<MAXH;i++)
			{
			 for(int j=0;j<MAXL;j++)
			 {
				 cout<<Mat[i][j];
			 }
			 cout<<endl;
			}

			cout<<"�þ������һ��һά�������£�"<<endl;
			for(int k=0;k<MAX;k++)
				cout<<B[k]<<" ";
}

//ʵ���ߺ���������������������ʽ��
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

int Visit(char ch)//���ʸ��ڵ�
{
 cout<<ch;
 return 0;
}

int InOrderTraverse(BiTree T,int (*Visit)(char d))//�������
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
    cout<<"�������������������#�����������";
	cout<<endl;
    T =  CreatBiTree();
    cout<<"�����������Ϊ:";
	cout<<endl;
    InOrderTraverse(T,Visit);
}
//ʵ��˺�����ջ�����򼰺�������ķǵݹ��㷨��
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
      	st->data[++st->top]=T;     //ջ��ָ��ʼ��ָ���ջ��������õ�һ��Ԫ�أ������ջʱ����Ҫ��ָ���1,Ȼ����ִ����ջ������
      else cout<<"����"<<endl;
  }

  BiTree2 pop(Stack *st)
  {
       if (!isempty(st)) return st->data[st->top--];
return 0;  }

  BiTree2 gettop(Stack *st)
  {
         if (!isempty(st)) return st->data[st->top];  //��ջʱ����ȡ��ջ��ָ��ָ���Ԫ�أ�Ȼ���ٽ�ָ���1��ʹ��ָ��ջ����һ������Ԫ�أ�
return 0;  }

  void preOrderNoRe(BiTree2 T)          // ǰ�����
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

  void postOrderNoRe(BiTree2 T)          //�������
  {
       BiTree2 p;
      Stack *st;
      initstack(st);
      p=T;
      int Tag[20];      //ջ�����ڱ�ʶ����0�����ң�1������ 
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
                             Tag[st->top]=1;   //���ñ���������Ѿ����� 
                            p=gettop(st);
                            p=p->rchild;
           }
           else break;
     }
 }

  void Inn_Ergodic()
  {
	   
     BiNode2 *T;
	 cout<<"�����������������#��ʾ��������"<<endl;
     createTree(T);
     cout<<endl;
    
     cout<<"�������: ";preOrderNoRe(T);cout<<endl;
    
     cout<<"�������: ";postOrderNoRe(T);cout<<endl; 
     //system("pause");
  }

//ʵ��ź�����ͼ�Ĺ�ȼ��������������
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
     
} 

void GraphDFS(GRAPH  g)//������ȱ���ͼg���ܷ��ʵĸ������� 
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
	cout<<"���롮1������ִ�иó������롮0���������ó���";
	cin >>Exit;
	while(Exit!=0)
	{
	int Exp_Num;
	cout<<endl;
	cout<<"����������Ҫ�鿴��ʵ�飨ʵ��1-9��[0��ʾ�˳�����]��"<<endl;
	cin>>Exp_Num;
	switch(Exp_Num){
	case 1:
	 cout<<"ʵ��1��������ˣ���\n\n"<<endl;
	     Matrix_Multiply();
	 cout<<endl;
	 break;
	case 2:
	 cout<<"ʵ��2�����Ա��������\n\n"<<endl;
	     Linear_List_1();
	     Linear_List_2();
	 cout<<endl;
	 break;
	case 3:
	 cout<<"ʵ��3.16��������ȣ���\n\n"<<endl;
	     Carriage_Dispatch();
	 cout<<endl;
	 cout<<"ʵ��3.18��������ԣ���\n\n"<<endl;
	     Bracket_Match();
     cout<<endl;
	 break;
	case 4:
	 cout<<"ʵ��4������ɾ�����Ƚϣ���\n\n"<<endl;
	     String_Operate();
	 cout<<endl;
	 break;
	case 5:
	 cout<<"ʵ��5����Ԫ��ת�ã���\n\n"<<endl;
	     Triple_Transpose();
	 cout<<endl;
	 break;
	case 6:
	 cout<<"ʵ��6��׼�ԽǾ������һά���飩��\n\n"<<endl;
	     Quasi_Diagonal_Matrix();
	 cout<<endl;
	 cout<<endl;
	 break;
	case 7:
	 cout<<"ʵ��7�����������ʽ�������\n\n"<<endl;
	     Binary_Tree_Output();
	 cout<<endl;
	 cout<<endl;
    break;
	case 8:
	 cout<<"ʵ��8��ջ�����򼰺�������ķǵݹ��㷨����\n\n"<<endl;
	     Inn_Ergodic();
	 cout<<endl;
	 break;
	case 9:
	 cout<<"ʵ��9��ͼ�Ĺ�ȼ����������������\n\n"<<endl;
	    Graph_DFS_and_BFS();
		break;
	case 0: Exit=0;
		cout<<"�ɹ��˳�����";break;
	}
	}
	 return 0;
}