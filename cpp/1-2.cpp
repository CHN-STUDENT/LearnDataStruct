#include<iostream>
#include<stack>//使用栈 
using namespace std;
/*******************************
* 
*时间复杂度 O(n)
*郭治洪 201616070320
*根据3-1栈的实现（数制转换）.txt实现
*2017.10.24 
*使用C++ STL Stack 
*
*******************************/

int main(void)
{
   int N,e;
   stack <int> num;
   cout<< "输入一个十进制数字:";
   cin >> N;
   while (N)
   {
	   	num.push(N%8); 
	    N=N/8;
   }
   cout<<"得到的八进制数为:"<<endl;
   while (!num.empty())
   {
   		
	    cout<<num.top();
	    num.pop();
   }  
   cout<<endl;
	return 0;
}
