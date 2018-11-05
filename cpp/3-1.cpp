#include<iostream> 
#define max 10
using namespace std;
typedef int Keytype;
typedef int Status;
typedef struct ElemType
{
	Keytype key;
}ElemType;

typedef struct
{
   ElemType elem[max];
   int length;
}SStable;


Status Search_Bin(SStable st,Keytype k)
{ 
	int low,high,mid;
	low=1; 
	high=st.length;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(st.elem[mid].key==k)  
			return mid;
		if(st.elem[mid].key>k) 
			high=mid-1;
		else 
			low=mid+1;
	}
	return 0;
}

void Init_Bin(SStable &st)
{
	cout<<"请输入关键字序列元素数目:"<<endl; 
	cin>>st.length;
	for(int i=1;i<=st.length;i++)
	{
		cout<<"请输入第"<<i<<"元素的值：";
		cin>>st.elem[i].key; 
	} 
}

int main(void)
{
	SStable st;
	Init_Bin(st); 
	cout<<"请输入要查找的值：";
	Keytype k,i;
	cin>>k;
	i=Search_Bin(st,k);
	if(i==0)
		cout<<"查找失败!"<<endl;
	else
		cout<<"查找成功,给定值的位序为："<<i<<endl;
}
