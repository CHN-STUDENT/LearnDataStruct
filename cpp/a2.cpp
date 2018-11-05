#include<iostream>
#include <iomanip>
/*******************************
* 
*时间复杂度 O(n)
*郭治洪 201616070320
*根据2-1有序表的合并，数组实现.txt实现
*2017.10.24 
* 
*******************************/
//#include<stdlib.h>
using namespace std;

#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INFEASIBLE -1
#define Stack_Init_Size 20

//typedef int Status;//定义状态 
#define List_Init_Size 20;
#define Listincrement 10;
typedef int ElemType;
typedef struct Sqlist
{
	ElemType *elem;//其实是整数型数组指针 
	int length;//有效数据长度 
	int listsize;//表的大小 
}Sqlist;

int* InitList_Sq(Sqlist &L)
{//初始化空线性表
	L.elem =  new int[20 * sizeof(int)]; //分配20个整数型数组，并且把指针给表L的elem 
	if(!L.elem) 
	{ cout <<"不能分配内存"<<endl;
		exit(OVERFLOW); //exit(-2); 
	};
	L.length=0;//有效数据的长度 
	L.listsize=List_Init_Size;//表初始化大小 20 
	return L.elem;
}
void Mergelist_Sq(Sqlist LA,Sqlist LB,Sqlist &LC)
{//已知顺序表LA、LB，归并LA、LB得到顺序表LC
//时间复杂度O(n)
	int *pa,*pb,*pc,*pa_last,*pb_last,i;
	pa=LA.elem; pb=LB.elem;//pa为表LA的整数型数组地址，pb表LB的整数型数组地址 
	int *bak_pa=pa;int *bak_pb=pb; 
  LC.listsize=LC.length=LA.length+LB.length;//表LC的长度和有效数据的长度为表LA和表LC的和 
  pc=LC.elem=new int[LC.listsize * sizeof(ElemType)];//分配表LC的整数型数组能储存LA和LB中元素 
  if (!LC.elem) 
  {
	  cout <<"不能分配内存"<<endl;
      exit(OVERFLOW);
  };
  pa_last=LA.elem+LA.length-1; //定义表LA的整形数组截至 
  pb_last=LB.elem+LB.length-1;//定义表LB的整形数组截至 
  while(pa<pa_last)//此循环会让表LA到达末尾元素 
    pa++;
  while(pb<pb_last)//此循环会让表LA到达末尾元素 
  	pb++; 
//  cout<<*pa<<*pb<<endl;
  while(pa>=bak_pa&&pb>=bak_pb)
  {//此循环把小的元素放在LC前面 
  	 if (*pa <= *pb) //如果表LA的元素小于表LB的元素 
		*pc++ = *pa--;//赋值并且变成下一个元素 
	else 
		*pc++ = *pb--;
  }
  while (pa>=bak_pa) //不等于首个元素 
  		*pc++ = *pa--;
  while (pb>=bak_pb) 
  		*pc++ = *pb--;
	delete bak_pa,bak_pb;//删除为表LA和LB的分配空间
}


void InPut(Sqlist &L,int i)
{//线性表读入数据
  int j;
  int x;//x记录线性表的元素值，设为整型。 
  cout<<"输入当前线性表的数据值："<<endl;
  for (j=0;j<i;j++)
  {
    cin>>x;
	L.elem[j]=x; 
  }
  L.length=i;
} 

void OutPut(Sqlist L)
{//线性表输出数据
	if(L.length==0)
	{
		cout<<"空表!" ;
	} 
	else
	{
		int i; 
		for (i=0;i<L.length;i++)
	    cout <<setw(5)<<L.elem[i];//设置域宽5，及设置占五个元素 
	}
  cout<<endl;
 } 

int main(void)
{
	Sqlist LA; //声明第一个线性表LA 
	InitList_Sq(LA); //初始化LA 
	int n1; 
	while(1)
	{
		cout<<"请输入第一个线性表的元素数n(n<20):";
		cin>>n1;
		cout<<endl;
		if(n1>=20)
		{
			cout<<"输入失败,请重试"<<endl;
		}
		else
			break; 
	}
	InPut(LA,n1);//在LA中输入元素 
	Sqlist LB; //声明第二个线性表LB 
	InitList_Sq(LB); //初始化LB
	int n2;
	while(1)
	{
		cout<<"请输入第二个线性表的元素数n(n<20):";
		cin>>n2;
		cout<<endl;
		if(n2>=20)
		{
			cout<<"输入失败,请重试"<<endl;
		}
		else
			break; 
	}
	InPut(LB,n2); 
	Sqlist LC;
	int *bak_pc=InitList_Sq(LC);
	Mergelist_Sq(LA,LB,LC);
	OutPut(LC);
	delete bak_pc;
	return 0;
}
