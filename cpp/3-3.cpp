#include<iostream> 
#define max 10 
using namespace std;
int main(void)
{
	int num[max+1];
	cout<<"请输入元素个数:";
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<"请输入第 "<<i<<" 个元素："; 
		cin>>num[i];
		cout<<endl; 
	}
	for(int i=1;i<=n;i++)
	{
		int temp=num[i];//备份插入的元素
		int j=i-1;//插入元素的前一位 
		while(j>=1&&num[j]>temp)
		{ //如果不到第一位或当前位大于插入的元素 
			num[j+1]=num[j];//后移一位 
			j--;
		} 
		num[j+1]=temp;//插入元素 
	}
	for(int i=1;i<=n;i++)
		cout<<" "<<num[i]<<" ";
	cout<<endl;
	return 0; 
}
