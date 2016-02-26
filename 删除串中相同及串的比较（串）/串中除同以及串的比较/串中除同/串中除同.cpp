#include<iostream>

using namespace std;

typedef struct {
	char *ch;
	int length;
}HString;


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
int main()
{
	HString Sone,Stwo;
	HString Sthree,Sfour;
	cout<<"从串中删除所有与串t相同的子串"<<endl;
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
		

		if(Sone.ch[i]==Stwo.ch[0])
			{
				StrDelete(Sone,i,Stwo.length);
				}
		
		//因为你删除后原来的串的长度就改变了，必须要检验之前的一位是否为相同
	}
	cout<<"删除后输出结果如下：";
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

	return 0;
}