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
	cout<<"�Ӵ���ɾ�������봮t��ͬ���Ӵ�"<<endl;
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
		

		if(Sone.ch[i]==Stwo.ch[0])
			{
				StrDelete(Sone,i,Stwo.length);
				}
		
		//��Ϊ��ɾ����ԭ���Ĵ��ĳ��Ⱦ͸ı��ˣ�����Ҫ����֮ǰ��һλ�Ƿ�Ϊ��ͬ
	}
	cout<<"ɾ�������������£�";
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

	return 0;
}