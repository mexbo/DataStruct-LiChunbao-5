//����8.10�����㷨:�󲻴�Ȩ������ͨͼG�о��붥��v����Զ��һ������
#include "graph.cpp"

int Maxdist(AdjGraph *G,int v)
{	ArcNode *p;
	int Qu[MAXV];					//���ζ���
	int front=0,rear=0;				//���е�ͷ��βָ��
	int visited[MAXV];				//���ʱ������
	int i,j,k;
	for (i=0;i<G->n;i++)			//��ʼ�����ʱ�־����
		visited[i]=0;
	rear++;Qu[rear]=v;				//����v����
	visited[v]=1;					//���v�ѷ���
	while (rear!=front) 
	{	front=(front+1)%MAXV;
		k=Qu[front];				//����k����
		p=G->adjlist[k].firstarc;	//�ҵ�һ���ڽӵ�
		while (p!=NULL)				//����δ���ʹ����ڽӵ����
		{	j=p->adjvex;			//�ڽӵ�Ϊ����j
			if (visited[j]==0)		//��jδ���ʹ�
			{	visited[j]=1;
				rear=(rear+1)%MAXV;Qu[rear]=j; //����
			}
			p=p->nextarc;			//����һ���ڽӵ�
		}
	}
	return k;
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
	int v=0,k;
	k=Maxdist(G,v);
	printf("ͼG�о��붥��%d����Զ�Ķ�����%d\n",v,k);
	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}