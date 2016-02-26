   #include <iostream>
    using namespace std;
   typedef struct node {
           char data;
          struct node *lchild;
          struct node *rchild;
          }BiNode2,*BiTree2;
   typedef struct node1{
          BiTree2 data[30];     //默认30个元素 ，这里需要一个辅助堆栈！！！
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
      	st->data[++st->top]=T;     //栈顶指针始终指向堆栈最上面可用的一个元素，因此入栈时候，先要将指针加1,然后再执行入栈操作！
      else cout<<"已满"<<endl;
  }
  BiTree2 pop(Stack *st)
  {
       if (!isempty(st)) return st->data[st->top--];
  }
  BiTree2 gettop(Stack *st)
  {
         if (!isempty(st)) return st->data[st->top];  //出栈时，先取出栈顶指针指向的元素，然后再将指针减1，使其指向栈中下一个可用元素！
  }
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
 int main()
{
     
     BiNode2 *T;
	 cout<<"请先序输入二叉树（#表示空树）："<<endl;
     createTree(T);
     cout<<endl;
    
     cout<<"先序遍历: ";preOrderNoRe(T);cout<<endl;
    
     cout<<"后序遍历: ";postOrderNoRe(T);cout<<endl; 
     system("pause");
    return 0;
}
