//Floyd�㷨
#include "graph.cpp"
void Dispath(MatGraph g,int A[][MAXV],int path[][MAXV])
{	int i,j,k,s;
	int apath[MAXV],d;		//���һ�����·���м䶥��(����)���䶥�����
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
		{	if (A[i][j]!=INF && i!=j)			//������i��j֮�����·��
			{	printf("  ��%d��%d��·��Ϊ:",i,j);
				k=path[i][j];
				d=0; apath[d]=j;				//·��������յ�
				while (k!=-1 && k!=i)			//·��������м��
				{	d++; apath[d]=k;
					k=path[i][k];
				}
				d++; apath[d]=i;				//·����������
				printf("%d",apath[d]);			//������
				for (s=d-1;s>=0;s--)			//���·���ϵ��м䶥��
					printf(",%d",apath[s]);
				printf("\t·������Ϊ:%d\n",A[i][j]);
			}
		}
}

void Floyd(MatGraph g)							//Floyd�㷨
{	int A[MAXV][MAXV],path[MAXV][MAXV];
	int i,j,k;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++) 
		{	A[i][j]=g.edges[i][j];
			if (i!=j && g.edges[i][j]<INF)
				path[i][j]=i;					//����i��j�б�ʱ
			else
				path[i][j]=-1;				//����i��jû�б�ʱ
		}
	for (k=0;k<g.n;k++)						//���ο������ж���
	{	for (i=0;i<g.n;i++)
			for (j=0;j<g.n;j++)
				if (A[i][j]>A[i][k]+A[k][j])
				{	A[i][j]=A[i][k]+A[k][j];	//�޸����·������
					path[i][j]=path[k][j];		//�޸����·��
				}
	}
	Dispath(g,A,path);							//������·��
}
/*
int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={
		{0,  5,INF,7},
		{INF,0,  4,2},
		{3,  3,  0,2},
		{INF,INF,1,0}};
	int n=4, e=8;
	CreateMat(g,A,n,e);			//�������̡̳���ͼ8.41���ڽӾ���
	printf("ͼG���ڽӾ���:\n");
	DispMat(g);					//����ڽӾ���
	printf("������Ե����·��:\n");
	Floyd(g);
	return 1;
}
*/
int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={
		{0,  6, INF,INF,2},
		{INF,0, INF,INF,INF},
		{INF,1, 0,  3,  INF},
		{2,  INF,INF,0, INF},
		{INF,3,  1,  3, 0}
	};
	int n=5, e=8;
	CreateMat(g,A,n,e);			//����ͼ���ڽӾ���
	printf("ͼG���ڽӾ���:\n");
	DispMat(g);					//����ڽӾ���
	printf("������Ե����·��:\n");
	Floyd(g);
	return 1;
}