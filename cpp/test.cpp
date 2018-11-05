//二叉排序树建树、插入、删除。
#include<iostream>//#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef int keytype;
typedef int ElemType; 

typedef struct BitNode
{
	ElemType  data;
	struct BitNode  *lch,*rch;
} BitNode,*BiTree;

Status searchBST(BiTree T,keytype k, BiTree f, BiTree &p);
Status insertBST(BiTree &T, ElemType e);
void initBST(BiTree &T);
void inorder(BiTree T);//中序遍历
Status DeleteBST(BiTree &T,keytype key);
Status Delete(BiTree &p);

int main()
{
	BiTree T=NULL;
	keytype d;
	cout<<"初始化一棵二叉排序树\n";
	initBST(T);
	cout<<endl;
	cout<<"中序遍历结果：";
    inorder(T);
	cout<<endl;
	cout<<"中序遍历结果：";
	inorder(T);

}

void initBST(BiTree &T)
{
	
	keytype k;
	int i,j;
	cout<<"输入待插入的关键字的总个数：";
	cin>>j;
	for(i=1;i<=j;i++)
	{
	   cout<<"输入第"<<i<<"个关键字：";
	   cin>>k;
       if(insertBST(T,k)) 
			cout<<"关键字"<<k<<"不在二叉排序树中，插入成功\n";
	   else 
	   		cout<<"关键字"<<k<<"已经在二叉排序树中，插入失败\n";
	}
}

Status searchBST(BiTree T,keytype k, BiTree f, BiTree &p)
//在t所指的二叉排序树中递归查找其关键字等于k的数据元素
//若成功，则p指向该结点，返回true；否则p指向查找路径上访
//问的最后一个结点，并返回false；f指t的双亲，初值为null
{ 
	if(T==NULL) 
	{
		p=f; 
		return FALSE;
	}
	if(k==T->data) 
	{
		p=T;
		return TRUE;
	}
	else if(k<T->data)  
		return searchBST(T->lch,k,T,p);
	else  
		return searchBST(T->rch,k,T,p);
}

Status insertBST(BiTree &T, ElemType e)
{  
	BiTree p,s;
	if (searchBST(T,e,NULL,p)==TRUE) 
		return FALSE;
    s=(BiTree) malloc(sizeof(BitNode));
    s->data=e; 
	s->lch=NULL; 
	s->rch=NULL;
    if(!p)
		T=s;//被插入结点为根结点
	else if(e < p->data ) p->lch=s;
		else p->rch=s;
    return TRUE;
}

void inorder(BiTree T)
{  
	if(T) 
	{ 	
		inorder(T->lch);
		cout<<T->data;
		inorder(T->rch);
    }
   cout<<endl;
}


Status DeleteBST(BiTree &T,keytype key)
{

	if(!T) 
		return FALSE;
	else
	{
		if (key==T->data) 
			return Delete(T);
		else if (key<T->data) 
			return DeleteBST(T->lch,key);
		else 
			return DeleteBST(T->rch,key);
	}
}

Status Delete(BiTree &p)
{
	BiTree q,s;   
    if (!p->rch)
	{
    	q=p;
		p=p->lch;
		free(q);
	}
	else if (!p->lch)
	{
        q=p;
		p=p->rch;
		free(q);
	}
   else
   {
    	q=p;
		s=p->lch;
    	while(s->rch)
		{
			q=s;
			s=s->rch;
		}
	    p->data=s->data;
	    if(q!=p) 
			q->rch=s->lch;
    	else 
			q->lch=s->lch;
	    delete s;
   };
   return TRUE;
}

