   #include <iostream>
    using namespace std;
   typedef struct node {
           char data;
          struct node *lchild;
          struct node *rchild;
          }BiNode2,*BiTree2;
   typedef struct node1{
          BiTree2 data[30];     //Ĭ��30��Ԫ�� ��������Ҫһ��������ջ������
          int top;
         }Stack;
        
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
  }
  BiTree2 gettop(Stack *st)
  {
         if (!isempty(st)) return st->data[st->top];  //��ջʱ����ȡ��ջ��ָ��ָ���Ԫ�أ�Ȼ���ٽ�ָ���1��ʹ��ָ��ջ����һ������Ԫ�أ�
  }
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
 int main()
{
     
     BiNode2 *T;
	 cout<<"�����������������#��ʾ��������"<<endl;
     createTree(T);
     cout<<endl;
    
     cout<<"�������: ";preOrderNoRe(T);cout<<endl;
    
     cout<<"�������: ";postOrderNoRe(T);cout<<endl; 
     system("pause");
    return 0;
}
