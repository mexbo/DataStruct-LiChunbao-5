//����8.2����Ӧ���㷨���ڽӾ�����ڽӱ���໥ת��
#include "graph.cpp"
void MatToList(MatGraph g,AdjGraph *&G)		//���ڽӾ���gת�����ڽӱ�G
{	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	for (i=0;i<g.n;i++)				//���ڽӱ�������ͷ����ָ�����ó�ֵ
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<g.n;i++)				//����ڽӾ�����ÿ��Ԫ��
		for (j=g.n-1;j>=0;j--)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF)	//����һ����
			{	p=(ArcNode *)malloc(sizeof(ArcNode));	//����һ���߽��p
				p->adjvex=j; p->weight= g.edges[i][j];
				p->nextarc=G->adjlist[i].firstarc;		//����ͷ�巨������p
				G->adjlist[i].firstarc=p;
			}
	G->n=g.n;G->e=g.e;
}
void ListToMat(AdjGraph *G,MatGraph &g) //���ڽӱ�Gת�����ڽӾ���g
{	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)			//ɨ�����еĵ�����
	{	p=G->adjlist[i].firstarc;	//pָ���i����������׽��
		while (p!=NULL)				//ɨ���i��������
		{	g.edges[i][p->adjvex]=p->weight;
			p=p->nextarc;
		}
	}
	g.n=G->n;g.e=G->e;
}

int main()
{
	MatGraph g;
	AdjGraph *G;
	int A[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},
			{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	int n=5, e=8;
	CreateMat(g,A,n,e);			//�������̡̳���ͼ8.1(a)���ڽӾ���
	printf("ͼG���ڽӾ���:\n");
	DispMat(g);					//����ڽӾ���g
	printf("��gת��Ϊ�ڽӱ�G\n");
	MatToList(g,G);				//����ڽӱ�G
	printf("ͼG���ڽӱ�:\n");
	DispAdj(G);
	DestroyAdj(G);				//�����ڽӱ�
	CreateAdj(G,A,n,e);			//�������̡̳���ͼ8.1(a)���ڽӱ�
	printf("ͼG���ڽӱ�:\n");
	DispAdj(G);					//����ڽӱ�G
	printf("��Gת��Ϊ�ڽӾ���g\n");
	ListToMat(G,g);
	DispMat(g);					//����ڽӾ���g
	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}
