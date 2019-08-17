//Dijkstra�㷨
#include "graph.cpp"
void Dispath(MatGraph g,int dist[],int path[],int S[],int v)
//����Ӷ���v�������������·��
{	int i,j,k;
	int apath[MAXV],d;					//���һ�����·��(����)���䶥�����
	for (i=0;i<g.n;i++)					//ѭ������Ӷ���v��i��·��
		if (S[i]==1 && i!=v)
		{	printf("  �Ӷ���%d������%d��·������Ϊ:%d\t·��Ϊ:",v,i,dist[i]);
			d=0; apath[d]=i;			//���·���ϵ��յ�
			k=path[i];
			if (k==-1)					//û��·�������
				printf("��·��\n");
			else						//����·��ʱ�����·��
			{	while (k!=v)
				{	d++; apath[d]=k;
					k=path[k];
				}
				d++; apath[d]=v;		//���·���ϵ����
				printf("%d",apath[d]);	//��������
				for (j=d-1;j>=0;j--)	//�������������
					printf(",%d",apath[j]);
				printf("\n");
			}
		}
}

void Dijkstra(MatGraph g,int v)	//Dijkstra�㷨
{	int dist[MAXV],path[MAXV];
	int S[MAXV];				//S[i]=1��ʾ����i��S��, S[i]=0��ʾ����i��U��
	int Mindis,i,j,u;
	for (i=0;i<g.n;i++)
	{	dist[i]=g.edges[v][i];	//�����ʼ��
		S[i]=0;					//S[]�ÿ�
		if (g.edges[v][i]<INF)	//·����ʼ��
			path[i]=v;			//����v������i�б�ʱ���ö���i��ǰһ������Ϊv
		else
			path[i]=-1;			//����v������iû��ʱ���ö���i��ǰһ������Ϊ-1
	}
	S[v]=1;path[v]=0;			//Դ����v����S��
	for (i=0;i<g.n-1;i++)		//ѭ��ֱ�����ж�������·�������
	{	Mindis=INF;				//Mindis����󳤶ȳ�ֵ
		for (j=0;j<g.n;j++)		//ѡȡ����S�У���U�У��Ҿ�����С���·�����ȵĶ���u
			if (S[j]==0 && dist[j]<Mindis) 
			{	u=j;
				Mindis=dist[j];
			}
		S[u]=1;					//����u����S��
		for (j=0;j<g.n;j++)		//�޸Ĳ���S�У���U�У��Ķ�������·��
			if (S[j]==0)
				if (g.edges[u][j]<INF && dist[u]+g.edges[u][j]<dist[j])
				{	dist[j]=dist[u]+g.edges[u][j];
					path[j]=u;
				}
	}
	Dispath(g,dist,path,S,v);	//������·��
}

int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={
		{0,4,6,6,INF,INF,INF},
		{INF,0,1,INF,7,INF,INF},
		{INF,INF,0,INF,6,4,INF},
		{INF,INF,2,0,INF,5,INF},
		{INF,INF,INF,INF,0,INF,6},
		{INF,INF,INF,INF,1,0,8},
		{INF,INF,INF,INF,INF,INF,0}};
	int n=7, e=12;
	CreateMat(g,A,n,e);			//�������̡̳���ͼ8.35���ڽӾ���
	printf("ͼG���ڽӾ���:\n");
	DispMat(g);					//����ڽӾ���
	int v=0;
	printf("��%d������������·������:\n",v);
	Dijkstra(g,v);
	return 1;
}