//������ȱ����㷨
#include "graph.cpp"
int visited[MAXV]={0};
void DFS(AdjGraph *G,int v)  
{
	ArcNode *p;
	visited[v]=1;                   //���ѷ��ʱ��
	printf("%d  ",v); 				//��������ʶ���ı��
	p=G->adjlist[v].firstarc;      	//pָ�򶥵�v�ĵ�һ�����Ļ�ͷ���
	while (p!=NULL) 
	{
		if (visited[p->adjvex]==0)	//��p->adjvex����δ����,�ݹ������
			DFS(G,p->adjvex);    
		p=p->nextarc;              	//pָ�򶥵�v����һ�����Ļ�ͷ���
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
	printf("�����������(�ݹ�):");DFS(G,2);printf("\n");
	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}
