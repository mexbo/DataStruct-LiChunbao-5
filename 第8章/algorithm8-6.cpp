//����8.6�����㷨:���ͼG�дӶ���u��v�����м�·��
#include "graph.cpp"
int visited[MAXV];					//ȫ������
void FindAllPath(AdjGraph *G,int u,int v,int path[],int d)
{	//d��ʾpath�е�·�����ȣ���ʼΪ-1
	int w,i; 	ArcNode *p;
	d++; path[d]=u;					//·������d��1������u���뵽·����
	visited[u]=1;					//���ѷ��ʱ��
	if (u==v && d>=0)				//�ҵ�һ��·�������
	{	for (i=0;i<=d;i++)
			printf("%2d",path[i]);
		printf("\n");
	}
	p=G->adjlist[u].firstarc;		//pָ�򶥵�u�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	w=p->adjvex;				//wΪ����u���ڽӵ�
		if (visited[w]==0)			//��w����δ����,�ݹ������
			FindAllPath(G,w,v,path,d);
		p=p->nextarc;				//pָ�򶥵�u����һ���ڽӵ�
	}
	visited[u]=0;					//�ָ�����,ʹ�ö��������ʹ��
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
	printf("\nͼG�ж���%d������%d�����м�·��:\n",u,v);
	FindAllPath(G,u,v,path,-1);
	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}
