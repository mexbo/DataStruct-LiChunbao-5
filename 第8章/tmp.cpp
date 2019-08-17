
#include "graph.cpp"
int visited[MAXV];					//ȫ�ֱ���
void hasCycle(AdjGraph *G,int v,bool &has)
//�жϴӶ���v�����ܷ��ҵ���
{
	ArcNode *p;
	int w;
	visited[v]=1;				//���ѷ��ʱ��
	p=G->adjlist[v].firstarc;	//pָ�򶥵�v�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	w=p->adjvex;
		if (visited[w]==0)		//������wδ���ʣ��ݹ������
			hasCycle(G,w,has);
		else					//���ҵ����ѷ��ʹ��Ķ���˵���л�·
			has=true;
		p=p->nextarc;			//����һ���ڽӵ�
	}
	visited[v]=0;
}
bool Cycle(AdjGraph *G)         //�ж�����ͼG���Ƿ���ڻ�
{
	bool has=false;
	for (int i=0;i<G->n;i++)
	{
		hasCycle(G,i,has);
		if (has) return true;
	}
	return false;
}
int main()
{ 
/*	int n=7, e=12;
	int A[MAXV][MAXV]={
		{0,  2,  5,  3,  INF,INF,INF},
		{INF,0,  2,  INF,INF,8,  INF},
		{INF,INF,0,  1,  3,  5,  INF},
		{INF,INF,INF,0,  5,  INF,INF},
		{INF,INF,INF,INF,0,  3,  9},
		{INF,INF,INF,INF,INF,0,  5},
		{INF,INF,INF,INF,INF,INF,0}
	};	
*/

	int n=4, e=4;
	int A[MAXV][MAXV]={
		{0,  1,  1,INF},
		{INF, 0, INF,INF},
		{INF,1,    0,1},
		{INF,INF,INF,0}

	};	

	AdjGraph *G;
	CreateAdj(G,A,n,e);			////����ͼ8.19���ڽӱ�
	for (int i=0;i<n;i++) 		//visited�����ó�ֵ
		visited[i]=0;
	printf("ͼG:\n");DispAdj(G);//����ڽӱ�
	bool has=false;
	printf("has=%d\n",Cycle(G));
	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}
