//����8.9�����㷨:�󲻴�Ȩ������ͨͼG�дӶ���u������v��һ�����·����
#include "graph.cpp"
int visited[MAXV];
typedef struct
{	int data;						//������
	int parent;						//ǰһ�������λ��
} QUERE;							//�ǻ��ζ�������
void ShortPath(AdjGraph *G,int u,int v)
{	//����Ӷ���u������v�������·��
	ArcNode *p;
	int w,i;
	QUERE qu[MAXV];					//�ǻ��ζ���
	int front=-1,rear=-1;			//���е�ͷ��βָ��
	int visited[MAXV];
	for (i=0;i<G->n;i++)			//���ʱ���ó�ֵ0
		visited[i]=0;
	rear++;							//����u����
	qu[rear].data=u;
	qu[rear].parent=-1;
	visited[u]=1;
	while (front!=rear)				//�Ӳ���ѭ��
	{	front++;					//���Ӷ���w
		w=qu[front].data;
		if (w==v)					//�ҵ�vʱ���·��֮�沢�˳�
		{	i=front;				//ͨ�����������·��
			while (qu[i].parent!=-1)
			{	printf("%2d ",qu[i].data);
				i=qu[i].parent;
			}
			printf("%2d\n",qu[i].data);
			break; 
		}
		p=G->adjlist[w].firstarc;	//��w�ĵ�һ���ڽӵ�
		while (p!=NULL)
		{	if (visited[p->adjvex]==0)
			{	visited[p->adjvex]=1;
				rear++;				//��w��δ���ʹ����ڽӵ����
				qu[rear].data=p->adjvex;
				qu[rear].parent=front;
			}
			p=p->nextarc;			//��w����һ���ڽӵ�
		}
	}
}

int main()
{ 
	int n=5, e=7;
	int A[MAXV][MAXV]={
		{0,1,1,0,0},{0,0,1,0,0},{0,0,0,1,1},
		{0,0,0,0,1},{1,0,0,0,0}};	

	AdjGraph *G;
	CreateAdj(G,A,n,e);			////����ͼ8.19���ڽӱ�
	printf("ͼG:\n");DispAdj(G);//����ڽӱ�
	int u=0,v=4;
	printf("ͼG�ж���%d��%d�������·��:\n",u,v);
	ShortPath(G,u,v);
	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}
