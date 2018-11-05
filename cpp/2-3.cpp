#include<iostream>
#include<queue>
#define MAX 10

/*参考算法导论P342,P344,P345*/ 
/*使用C++ STL容器queue*/ 
using namespace std;

typedef int VertexType;//定点数据类型：整形 
typedef int WeightType;//定义权值类型：整形
typedef int QElemType;//定义队列类型：整形 
 
int visited[MAX];//全局变量。visited[i]=0(v未被访问过)、visited[i]= 1(v已被访问过)
 
typedef struct SqQueue{
   QElemType * base;//初始化的动态分配存储空间
   int front; //头指针，若队列不空，指向队列头元素
   int rear;  //尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQueue; 
 
typedef struct ArcNode
{
	int adjvex;//该边所指向顶点的位置
	WeightType weight;//权值 
	struct ArcNode *nextarc;//指向下一条边的指针
}ArcNode;

typedef struct VNode
{
	VertexType data;//顶点信息
	ArcNode *firstarc;//指向第一条依附于该顶点的边
}VNode;

typedef struct DIGraph
{
	VNode vertices[MAX];//顶点个数 
	int vexnum,arcnum;//图的当前顶点数和边数
}ALGraph;

void ShowUDG(DIGraph G)
{
	int i;
    ArcNode *p;
	cout<<"该图的邻接表为：\n";
	for(i=1;i<=G.vexnum;i++)
	{
		cout<<G.vertices[i].data;//输出这个结点的值 
		p=G.vertices[i].firstarc;//取这个结点邻接链表的地址 
		while(p)
		{//不为空就输出并且进入下一个邻接链表 
		    cout<<" -> | "<<p->adjvex<<" | Weight:"<<p->weight<<" | ";
			p=p->nextarc;
		}
		cout<<endl;
	}
	cout<<endl;
 } 

void CreatUDG(DIGraph &G)
{
	ArcNode *p;
	cout<<"图的总顶点数=";
	cin>>G.vexnum;
	cout<<endl;
	cout<<"图的总边数=";
	cin>>G.arcnum;
	cout<<endl;
	for(int i=1;i<=G.vexnum;i++)
	{
		cout<<"请输入顶点"<<i<<"的值=";
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;
	} 
	for(int i,j,w,k=1;k<=G.arcnum;k++)
	{
		cout<<"输入第"<<k<<"条边信息:(注意，单向边->)\n起始点=";
		cin>>i;
		cout<<"终点="; 
		cin>>j;
		cout<<"权值="; 
		cin>>w;
		cout<<endl;
		p=(ArcNode*) new ArcNode;//将边(i,j) 前插入第 i条链
		p->adjvex=j;
		p->weight=w; 
		p->nextarc=G.vertices[i].firstarc;//备份上个结点指针地址 
		G.vertices[i].firstarc=p;//头插法插入 
	}
} 

void BFS(DIGraph G)
{
	//假设我们把第一个结点当作根结点 
	cout<<"图的广度优先遍历算法结果:"<<endl;
	for(int v=1;v<=G.vexnum;v++)  
		visited[v]=0;//设置所有结点均未被访问 
	queue<QElemType> Q;//声明队列 
	for(int i=1;i<=G.vexnum;i++)
	{//对所有结点遍历防止遗漏 
		if(visited[i]==0)
		{//如果该节点的没有被访问，设置成根元素 
			visited[i]=1;//根元素设置被访问
			Q.push(G.vertices[i].data);//根结点入队
			cout<<G.vertices[i].data;//输出根结点数据 
			while(!Q.empty()) 
			{//如果队列非空 
				ArcNode *p;
				p=G.vertices[Q.front()].firstarc;//取它邻接链表地址 
				while(p!=NULL)
				{//邻接链表不为空就访问 
					if(visited[p->adjvex]==0)
					{//邻接链表的值没有被访问 
						cout<<" "<<p->adjvex<<" ";//输出 
						visited[p->adjvex]=1;//标记被访问
						Q.push(p->adjvex);//结点入队 	 
					}
					p=p->nextarc;//进入下一个邻接链表
				}
				Q.pop();//结点出队 
			}
		}
	}
}  

int main(void)
{
	DIGraph G;
	CreatUDG(G);
	ShowUDG(G); 
	BFS(G);
	return 0;
 } 
