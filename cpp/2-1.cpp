#include<iostream>

using namespace std;

typedef char ElemType;//节点数据类型字符型 

typedef struct BitNode
{
	ElemType  data;
	struct BitNode  *lch,*rch;
} BN,*BPtr;

void Create(BPtr &p,int Depth)
{//创建二叉树
	char ch;
	for(int i=0;i<Depth;i++)
		cout<<" ";//深度为多少就在前面放多少空格用来清晰显示 
	cin>>ch;
	if (ch=='#') //如果输入为# 
		p=NULL;//数据为空 
	else 
	{
		p=(BPtr)new BN;//分配空间 
		if(p==NULL) //分配失败情况 
			exit(-1);
		p->data=ch;//记录值  
		Create(p->lch,Depth+1);//创建结点的左孩子 
		Create(p->rch,Depth+1);//创建结点的右孩子 
	}
}

void Preorder(BPtr p,int Depth)
{//先序遍历二叉树 
    if(p) 
	{//如果该节点不为空 
		for(int i=0;i<Depth;i++)
			cout<<"  ";//深度为多少就在前面放多少空格用来清晰显示
		cout<<p->data<<endl; //输出该节点 
		Preorder(p->lch,Depth+1);//遍历它的左孩子 
		Preorder(p->rch,Depth+1);//遍历它的右孩子 
	}
}

void Inorder(BPtr p,int Depth)
{//中序遍历二叉树 
    if(p) 
	{//如果该节点不为空 
		Inorder(p->lch,Depth+1);//遍历它的左孩子 
		for(int i=0;i<Depth;i++)
			cout<<"  ";//深度为多少就在前面放多少空格用来清晰显示
		cout<<p->data<<endl; //输出该节点
		Inorder(p->rch,Depth+1);//遍历它的右孩子 
	}
}

void Postorder(BPtr p,int Depth)
{//后序遍历二叉树 
    if(p) 
	{//如果该节点不为空 
		Postorder(p->lch,Depth+1);//遍历它的左孩子 
		Postorder(p->rch,Depth+1);//遍历它的右孩子 
		for(int i=0;i<Depth;i++)
			cout<<"  ";//深度为多少就在前面放多少空格用来清晰显示
		cout<<p->data<<endl; //输出该节点
	}
} 

int main(void)
{
	BPtr p;//指针
	cout<<"使用先序遍历建立二叉树，请输入节点信息，以#为空:"<<endl<<endl; 
	Create(p,0);//初始深度0 
	
	cout<<"先序遍历结果:"<<endl<<endl;
	Preorder(p,0);//初始深度0 
	cout<<endl;
	
	cout<<"中序遍历结果:"<<endl<<endl;
	Inorder(p,0);//初始深度0 
	cout<<endl;
	
	cout<<"后序遍历结果:"<<endl<<endl;
	Postorder(p,0);//初始深度0 
	cout<<endl;
	
	return 0;
 } 
