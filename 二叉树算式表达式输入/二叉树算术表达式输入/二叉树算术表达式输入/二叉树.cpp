#include<iostream>
using namespace std;

typedef struct BiTNode{
   char data;
   struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

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
void main()
{
    BiTree T=NULL;
    cout<<"请先序输入二叉树，‘#’代表空树：";
	cout<<endl;
    T =  CreatBiTree();
    cout<<"中序遍历序列为:";
	cout<<endl;
    InOrderTraverse(T,Visit);
}