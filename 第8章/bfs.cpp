//������ȱ����㷨
#include "graph.cpp"
#define MaxSize 100
//---------------------------------------------------------
//--������ȱ�����ʹ�ö��еĻ��������㷨-------------------
//---------------------------------------------------------
typedef int ElemType;
typedef struct 
{	
	ElemType data[MaxSize];
	int front,rear;		//���׺Ͷ�βָ��
} SqQueue;
void InitQueue(SqQueue *&q)
{	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q)
{
	free(q);
}
bool QueueEmpty(SqQueue *q)
{
	return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,ElemType e)
{	if ((q->rear+1)%MaxSize==q->front)	//���������
		return false;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}
bool deQueue(SqQueue *&q,ElemType &e)
{	if (q->front==q->rear)				//�ӿ������
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}
//---------------------------------------------------------

void BFS(AdjGraph *G,int v)  
{
	int w,i;
	ArcNode *p;
	SqQueue *qu;							//���廷�ζ���ָ��
	InitQueue(qu);							//��ʼ������
	int visited[MAXV];            			//���嶥����ʱ�־����
	for (i=0;i<G->n;i++) visited[i]=0;		//���ʱ�־�����ʼ��
	printf("%2d",v); 						//��������ʶ���ı��
	visited[v]=1;              				//���ѷ��ʱ��
	enQueue(qu,v);
	while (!QueueEmpty(qu))       			//�Ӳ���ѭ��
	{	
		deQueue(qu,w);						//����һ������w
		p=G->adjlist[w].firstarc; 			//ָ��w�ĵ�һ���ڽӵ�
		while (p!=NULL)						//����w�������ڽӵ�
		{	
			if (visited[p->adjvex]==0) 		//����ǰ�ڽӵ�δ������
			{
				printf("%2d",p->adjvex);  	//���ʸ��ڽӵ�
				visited[p->adjvex]=1;		//���ѷ��ʱ��
				enQueue(qu,p->adjvex);		//�ö������
           	}
           	p=p->nextarc;              		//����һ���ڽӵ�
		}
	}
	printf("\n");
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
	printf("�����������:");BFS(G,2);printf("\n");
	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}
