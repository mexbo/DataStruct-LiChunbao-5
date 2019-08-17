//Prim�㷨
#include "graph.cpp"

void Prim(MatGraph g,int v)
{
	int lowcost[MAXV];			//����i�Ƿ���U��
	int min;
	int closest[MAXV],i,j,k;
	for (i=0;i<g.n;i++)          //��lowcost[]��closest[]�ó�ֵ
	{	
		lowcost[i]=g.edges[v][i];
		closest[i]=v;
	}
	for (i=1;i<g.n;i++)          //�ҳ�n-1������
	{
		min=INF;
		for (j=0;j<g.n;j++)       //��(V-U)���ҳ���U����Ķ���k
			if (lowcost[j]!=0 && lowcost[j]<min) 
			{
				min=lowcost[j];
				k=j;			//k��¼�������ı��
			}
		printf(" ��(%d,%d)ȨΪ:%d\n",closest[k],k,min);
		lowcost[k]=0;         	//���k�Ѿ�����U
		for (j=0;j<g.n;j++)   	//�޸�����lowcost��closest
			if (g.edges[k][j]!=0 && g.edges[k][j]<lowcost[j]) 
			{
				lowcost[j]=g.edges[k][j];
				closest[j]=k; 
			}
	}
}
int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={
		{0,28,INF,INF,INF,10,INF},
		{28,0,16,INF,INF,INF,14},
		{INF,16,0,12,INF,INF,INF},
		{INF,INF,12,0,22,INF,18},
		{INF,INF,INF,22,0,25,24},
		{10,INF,INF,INF,25,0,INF},
		{INF,14,INF,18,24,INF,0}};
	int n=7, e=9;
	CreateMat(g,A,n,e);			//�������̡̳���ͼ8.27���ڽӾ���
	printf("ͼG���ڽӾ���:\n");
	DispMat(g);					//����ڽӾ���
	int v=0;
	printf("Prim�㷨���(��ʼ��Ϊ%d)\n",v);
	Prim(g,v);
	return 1;
}
