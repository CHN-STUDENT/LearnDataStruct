#include<iostream>//#include<stdio.h>
#include<iomanip>//格式控制头文件
//#include<stdlib.h>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;


#define Maxsize 100; // 假设非零元个数的最大值为100
typedef struct
{
	int i,j;
	ElemType e;
}Triple;

typedef struct
{
   Triple data[20];
   // 非零元三元组表，data[0] 未用
   int mu;
	int nu;
	int tu;// 矩阵的行数、列数和非零元的个数
} TSMatrix;

TSMatrix M,T;
Status TransPoseSMatrix(TSMatrix M, TSMatrix &T);
Status FastTransSMatrix(TSMatrix M, TSMatrix &T);
void InitMatrix(TSMatrix &M);
void PrintMatrix(TSMatrix M);

int main(void)
{	
	cout<<"建立稀疏矩阵M\n";
    InitMatrix(M);
	PrintMatrix(M);
    cout<<endl;

	cout<<"压缩转置算法结果为：";
    TransPoseSMatrix(M, T);
    PrintMatrix(T);
	cout<<endl;

	cout<<"快速转置算法结果为：";
    FastTransSMatrix(M,T);
    PrintMatrix(T);
	cout<<endl;

	return 0;
 }


Status TransPoseSMatrix(TSMatrix M, TSMatrix &T)
{//mu行，nu列，tu非零元 
//时间复杂度O(nu*tu) 
	int q,p,col;
	T.mu=M.nu;  T.nu=M.mu;  T.tu=M.tu;//新矩阵与老矩阵行列值刚好相反 
   if (T.tu) //如果可以储存 
   { 
	   q=1;//q是序号          
	   for(col=1; col<=M.nu; col++) 
	     { //由col作为新矩阵行变量，从1开始找，到老矩阵的列值  
		 	for(p=1; p<=M.tu; p++) 
	        {//由p作为计数变量，赋值所有的值 
				if (M.data[p].j==col)
	            {//如果当前的列值为循环col的值，执行为新矩阵赋值，这样保证列值也按顺序存储 
					T.data[q].i=M.data[p].j;  
					T.data[q].j=M.data[p].i;
	                T.data[q].e=M.data[p].e;  
					q++;
	            }
	        }
	    }
   }
    return OK;
};//压缩转置算法


Status FastTransSMatrix(TSMatrix M, TSMatrix &T)
{//mu行，nu列，tu非零元 
//采用三元组顺序表存储表示，求稀疏矩阵M的转置矩阵T
  
	int col,t;
	int num[10],cpot[10];
	int p,q;
	T.mu=M.nu; T.nu=M.mu; T.tu=M.tu;
	if (T.tu)
	{//如果可以赋值 
   		for (col=1; col<=M.nu; ++col) 
		   	num[col]=0;
		//求M中每一列非零元个数，形成num表
  		for (t=1; t<=M.tu; ++t) 
		  	++num[M.data[t].j];
   		//求M中第col列中第一个非零元在T.data中的序号
   		cpot[1]=1;
   		for(col=2; col<=M.nu; ++col)
      		cpot[col]=cpot[col-1]+num[col-1];
		for(p=1; p<M.tu; ++p)
		{//q为p元素转置以后的下标
     		col=M.data[p].j; 
			q=cpot[col];
	     	T.data[q].i=M.data[p].j;       
	     	T.data[q].j=M.data[p].i;
	     	T.data[q].e=M.data[p].e;
	     	++cpot[col]; //第col列下一个元素在T中的位置
   		}//for
	}//if
	return OK;
}//FastTransposeSMatrix快速压缩转置算法



void InitMatrix(TSMatrix &M)
{
   int m,n,t;
   int x,y,z;
    int s;

	cout<<"输入矩阵M的总行数、总列数、总非零元个数："<<endl;
    cin>>m>>n>>t;
	cout<<endl;
	M.mu=m; M.nu=n; M.tu=t;
    for(s=1;s<=t;s++)
	{
	   cout<<"输入第"<<s<<"个非零元的行数、列数、值\n";
	   cin>>x>>y>>z;
		M.data[s].i=x;
	    M.data[s].j=y;
		M.data[s].e=z;
	}
}



void PrintMatrix(TSMatrix M)
{//输出矩阵 
   int s;
   cout<<"矩阵的总行数、总列数、总非零元个数为："<<setw(6)<<M.mu<<setw(6)<<M.nu<<setw(6)<<M.tu<<endl;
   cout<<"矩阵三元组表为：\n";
   for (s=1;s<=M.tu;s++)
   {
      cout<<"["<<s<<"]"<<setw(6)<<M.data[s].i<<setw(6)<< M.data[s].j<<setw(6)<<M.data[s].e<<endl;
   
   }
   
}
