//����8.5�����㷨:���ͼG�дӶ���u��v��һ����·��
#include "graph.cpp"
int visited[MAXV];					//ȫ������
void FindaPath(AdjGraph *G,int u,int v,int path[],int d)
{	//d��ʾpath�е�·�����ȣ���ʼΪ-1
	int w,i;	ArcNode *p;
	visited[u]=1;
	d++; path[d]=u;			//·������d��1������u���뵽·����
	if (u==v)					//�ҵ�һ��·�������������
	{	for (i=0;i<=d;i++)
			printf("%d ",path[i]);
		printf("\n");
		return; 
	}
	p=G->adjlist[u].firstarc;	//pָ�򶥵�u�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	w=p->adjvex;			//�ڽӵ�ı��Ϊw
		if (visited[w]==0)
			FindaPath(G,w,v,path,d);
		p=p->nextarc;			//pָ�򶥵�u����һ���ڽӵ�
	}
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
	int u=0, v=3;
	int path[MAXV];
	printf("\nͼG�ж���%d������%d��һ����·��Ϊ:",u,v);
	FindaPath(G,u,v,path,-1);
	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}
