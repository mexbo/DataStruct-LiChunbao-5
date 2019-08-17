//����8.4�����㷨:�ж�ͼG�дӶ���u��v�Ƿ���ڼ�·��
#include "graph.cpp"
int visited[MAXV];					//ȫ������
void ExistPath(AdjGraph *G,int u,int v,bool &has)
{	//has��ʾu��v�Ƿ���·��,��ֵΪfalse
	int w; ArcNode *p;
	visited[u]=1;					//���ѷ��ʱ��
	if (u==v)						//�ҵ���һ��·��
	{	has=true;					//��hasΪtrue������
		return;
	}
	p=G->adjlist[u].firstarc;		//pָ�򶥵�u�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	w=p->adjvex;				//wΪ����u���ڽӵ�
		if (visited[w]==0)			//��w����δ����,�ݹ������
			ExistPath(G,w,v,has);
		p=p->nextarc;				//pָ�򶥵�u����һ���ڽӵ�
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
	bool has=false;
	int u=0, v=3;
	ExistPath(G,u,v,has);
	printf("\nͼG�ж���%d������%d%s·��\n\n",u,v,(has?"��":"û��"));
	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}
