//����8.3�����㷨:�ж�����ͼG�Ƿ���ͨ
#include "graph.cpp"
int visited[MAXV];					//ȫ������
void DFS(AdjGraph *G,int v)			//������ȱ����㷨
{	ArcNode *p;
	visited[v]=1;					//���ѷ��ʱ��
	printf("%d  ",v);				//��������ʶ���ı��
	p=G->adjlist[v].firstarc;		//pָ�򶥵�v�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	if (visited[p->adjvex]==0)	//��p->adjvex����δ����,�ݹ������
			DFS(G,p->adjvex);
		p=p->nextarc;				//pָ�򶥵�v����һ���ڽӵ�
	}
}

bool Connect(AdjGraph *G)	//�ж�����ͼG����ͨ��
{	int i;
	bool flag=true;
	for (i=0;i<G->n;i++)	//visited�����ó�ֵ
		visited[i]=0;
	DFS(G,0);				//����ǰ�����DSF�㷨,�Ӷ���0��ʼ������ȱ���
	for (i=0;i<G->n;i++)
		if (visited[i]==0)
		{	flag=false;
			break;
		}
	return flag;
}

int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},
			{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	int n=5, e=8;
	CreateAdj(G,A,n,e);			//�������̡̳���ͼ8.1(a)���ڽӱ�
	printf("ͼG���ڽӱ�:\n");
	DispAdj(G);					//����ڽӱ�G
	printf("\nͼG%s��ͨ��\n",(Connect(G)?"��":"����"));
	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}
