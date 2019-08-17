//����8.8�����㷨:���һ������ͼ��ͨ��ĳ����������л�·
#include "graph.cpp"
int visited[MAXV];					//ȫ�ֱ���
void DFSPath(AdjGraph *G,int u,int v,int path[],int d)
{	//d��ʾpath�е�·�����ȣ���ʼΪ-1
	int w,i;
	ArcNode *p;
	visited[u]=1;
	d++; path[d]=u;
	p=G->adjlist[u].firstarc;		//pָ�򶥵�u�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	w=p->adjvex;				//wΪ����u���ڽӵ�
		if (w==v && d>0)			//�ҵ�һ����·�����֮
		{	printf("  ");
			for (i=0;i<=d;i++)
				printf("%d ",path[i]);
			printf("%d \n",v);
		}
		if (visited[w]==0)			//��wδ����,��ݹ����֮
			DFSPath(G,w,v,path,d);
		p=p->nextarc;				//��u����һ���ڽӵ�
	}
	visited[u]=0;					//�ָ�������ʹ�ö��������ʹ��
}
void FindCyclePath(AdjGraph *G,int k)	//�����������k�����л�·
{	int path[MAXV];
	DFSPath(G,k,k,path,-1);
}

int main()
{ 
	int n=5, e=7;
	int A[MAXV][MAXV]={
		{0,1,1,0,0},{0,0,1,0,0},{0,0,0,1,1},
		{0,0,0,0,1},{1,0,0,0,0}};	

	AdjGraph *G;
	CreateAdj(G,A,n,e);			////����ͼ8.19���ڽӱ�
	for (int i=0;i<n;i++) 		//visited�����ó�ֵ
		visited[i]=0;
	printf("ͼG:\n");DispAdj(G);//����ڽӱ�
	int k=0;
	printf("ͼG�о�������%d�����л�·:\n",k);
	FindCyclePath(G,k);
	printf("\n");
	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}
