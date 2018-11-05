#include<iostream>
#include <iomanip>
#include <vector>
/*******************************
* 
*时间复杂度 O(n)
*郭治洪 201616070320
*根据2-1有序表的合并，数组实现.txt实现
*2017.10.24 
*使用C++ STL Vector 
*
*******************************/
using namespace std;

void InPut(vector <int> &L)
{
	while(1)
	{//无限循环输入，并且以确认结束 
		char input;
		input=cin.get();
		if(input == '\n')
			break;
		int N=input-48;
		if(N>=0&&N<=9)
		{//保证为数字 
			L.push_back(N);//推入 
		}
	} 
}

void Mergelist(vector <int> &L1,vector <int> &L2,vector <int> &L3)
{//注意L.end()指针地址最后一个元素下个地址，如果判断到达末尾用!=或者< 
	vector<int>::const_iterator iterator1 = L1.begin();
	vector<int>::const_iterator iterator2 = L2.begin();
	while(iterator1!=L1.end()&&iterator2!=L2.end())
	{
		if(*iterator1!=*iterator2)
		{
			 L3.push_back(*iterator1);
			 iterator1++;
		}
		else
		{
			L3.push_back(*iterator2);
			iterator2++;
		}
	}
	while(iterator1!=L1.end())
	{
		 L3.push_back(*iterator1);
		 iterator1++;
	}
	while(iterator2!=L2.end())
	{
		 L3.push_back(*iterator2);
		 iterator2++;
	}
}

void OutPut(vector <int> &L)
{
	if(L.empty())
		cout<<"空表!" ;
	else
	{
		vector<int>::const_iterator iterator = L.begin();
	    for(;iterator != L.end();iterator++)
	    {
	       cout<<setw(5)<<*iterator;
	    }
	}	
	cout<<endl;
}

int main(void)
{
	int N;
	vector <int> L1; 
	cout<<"请输入第一个线性表的元素"<<endl;
	InPut(L1);
	vector <int> L2;
	cout<<"请输入第二个线性表的元素"<<endl;
	InPut(L2);
	vector <int> L3;
	Mergelist(L1,L2,L3);
	OutPut(L3);
	return 0;
 } 
