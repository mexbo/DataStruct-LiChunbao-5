//����8.7�����㷨:���ͼG�дӶ���u��v�ĳ���Ϊl�����м�·��
#include "graph.cpp"
int visited[MAXV];
void PathAll(AdjGraph *G,int u,int v,int l,int path[],int d)
{	//d��ʾpath�е�·�����ȣ���ʼΪ-1
	int w,i; 	ArcNode *p;
	visited[u]=1;
	d++; path[d]=u;				//·������d��1������u���뵽·����
	if (u==v && d==l)			//���һ��·��
	{	printf("  ");
		for (i=0;i<=d;i++)
			printf("%d ",path[i]);
		printf("\n");
	}
	p=G->adjlist[u].firstarc;	//pָ�򶥵�u�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	w=p->adjvex;			//wΪu���ڽӵ�
		if (visited[w]==0)		//���ö���δ��Ƿ���,��ݹ����֮
			PathAll(G,w,v,l,path,d);
		p=p->nextarc;			//pָ�򶥵�u����һ���ڽӵ�
	}
	visited[u]=0;				//�ָ�������ʹ�ö��������ʹ��
}
int main()
{ 
	int path[MAXV];
	int u=1,v=4,l=3;
	int n=5, e=8;
	int A[MAXV][MAXV]={
		{0,1,0,1,1},
		{1,0,1,1,0},
		{0,1,0,1,1},
		{1,1,1,0,1},
		{1,0,1,1,0}};
	AdjGraph *G;
	CreateAdj(G,A,n,e);			//����ͼ8.1(a)���ڽӱ�
	for (int i=0;i<n;i++) 		//visited�����ó�ֵ
		visited[i]=0;
	printf("ͼG:\n");DispAdj(G);//����ڽӱ�
	printf("�Ӷ���%d��%d�����г���Ϊ%d·��:\n",u,v,l);
	PathAll(G,u,v,l,path,-1);
	printf("\n");
	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}
