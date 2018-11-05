#include<iostream> 

using namespace std;
typedef int ElemType;
typedef int KeyType;

typedef struct BitNode
{
	ElemType  data;
	struct BitNode *lch,*rch;//左右子树的地址 
}BN,*BPtr;

void Inorder_BST(BPtr p,int Depth)
{//中序遍历二叉树 
    if(p) 
	{//如果该节点不为空 
		Inorder_BST(p->lch,Depth+1);//遍历它的左孩子 
		for(int i=0;i<Depth;i++)
			cout<<"  ";//深度为多少就在前面放多少空格用来清晰显示
		cout<<p->data<<endl; //输出该节点
		Inorder_BST(p->rch,Depth+1);//遍历它的右孩子 
	}
}

bool Search_BST(BPtr T,KeyType K,BPtr F,BPtr &P)
{/*F为T的父节点，初始值NULL
如果查找到关键字存在不允许插入，找到可以插入的位置返回要插入元素的父结点*/ 
	if(T==NULL) 
	{//找到可以插入的结点位置，可以插入的情况 
		P=F; //通过参数返回它的地址 
		return false;//返回为假 
	}
	if(K==T->data) 
	{//如果该元素存在，不允许插入的情况 
		P=T;//通过参数返回它的地址 
		return true;//返回为真 
	}
	else if(K<T->data)  
		return Search_BST(T->lch,K,T,P);//如果关键字小于继续递归搜索左子树 
	else  
		return Search_BST(T->rch,K,T,P);//如果关键字大于继续递归搜索右子树 
}

bool Insert_BST(BPtr &p,ElemType k)
{
	BPtr t;
	if(Search_BST(p,k,NULL,t)) 
		return false;//如果使用搜索查到该节点已经存在,则不创建新节点
	BPtr s; 
	/*创建新节点*/ 
    s=(BPtr)new BN; 
    if(!s)
    	exit(-1);
    s->data=k; 
	s->lch=NULL; 
	s->rch=NULL;
	/*判断是否被插入结点为根结点*/ 
    if(!t)
		p=s;//被插入结点为根结点
	else if(k<t->data) 
		t->lch=s;//如果小于在父结点的左子树 
	else 
		t->rch=s;//如果大于在父结点的左子树
    return true;
}

void Create_BST(BPtr &p)
{
	KeyType k;
	int i,j;
	cout<<"输入待插入的关键字的总个数：";
	cin>>j;
	cout<<endl; 
	for(i=1;i<=j;i++)
	{
	   cout<<"输入第"<<i<<"个关键字：";
	   cin>>k;
	   cout<<endl;
       if(Insert_BST(p,k)) 
			cout<<"关键字"<<k<<"不在二叉排序树中，插入成功"<<endl;
	   else 
	   		cout<<"关键字"<<k<<"已经在二叉排序树中，插入失败"<<endl;
	}
 } 

bool Delete_BN(BPtr &p)
{
	BPtr q;   
	if(!(p->rch))
	{//删除结点左孩子不存在，右孩子存在 
		q=p;
		p=p->lch;//它的右孩子结点上提给它的父节点 
		delete q;
	}
	else if(!(p->lch))
	{//删除结点右孩子不存在，左孩子存在 
	    q=p;
		p=p->rch;//它的左孩子结点上提给它的父节点
		delete q;
	}
	else
	{//左右孩子都存在，用右子数的最小数据替代该节点的数据，并且递归删除那个结点	
		BPtr s; 
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
	}
	return true;
} 

bool Delete(BPtr &T,KeyType key)
{
	if(!T) //如果是空树 
		return (-1);//无法删除 
	else
	{//非空树 
		if(key==T->data)//结点等于要删除的值 
			return Delete_BN(T);//删除操作 
		else if (key<T->data) //小于的节点的值 
			return Delete(T->lch,key);//遍历左子树 
		else //大于结点的值 
			return Delete(T->rch,key);//遍历右子树 
	}
}

void Delete_BST(BPtr &p)
{
	KeyType d; 
	BPtr t; 
	cout<<"要删除一个关键字是：";
    cin>>d;
    cout<<endl;
    if(Search_BST(p,d,NULL,t)) 
    {//元素存在才删除 
		if(Delete(p,d)) 
		{
			cout<<"删除成功！"<<endl;
		}
	}
	else
		 cout<<"元素不存在无法删除！"<<endl;
}

int main(void)
{
	BPtr p=NULL;//令指针为空 
	Create_BST(p);
	cout<<endl;
	cout<<"创建二叉树中序遍历结果是："<<endl;
	Inorder_BST(p,0); 
	cout<<endl;
	Delete_BST(p);
	cout<<"删除节点后二叉树中序遍历结果是："<<endl;
	Inorder_BST(p,0); 
	cout<<endl;
}
