//��α����㷨
#include "btree.cpp"
#define MaxSize 100
//--------------------------------------------------------
//--ѭ�����л��������㷨----------------------------------
//--------------------------------------------------------
typedef struct 
{	BTNode *data[MaxSize];				//��Ŷ���Ԫ��
	int front,rear;						//��ͷ�Ͷ�βָ��
} SqQueue;								//˳�������
void InitQueue(SqQueue *&q)				//��ʼ������
{	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q)			//���ٶ���
{
	free(q);
}
bool QueueEmpty(SqQueue *q)				//�ж϶����Ƿ�Ϊ��
{
	return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,BTNode *e)		//������
{	if ((q->rear+1)%MaxSize==q->front)	//���������
		return false;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}
bool deQueue(SqQueue *&q,BTNode *&e)	//������
{	if (q->front==q->rear)				//�ӿ������
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}
//--------------------------------------------------------

void LevelOrder(BTNode *b)
{
	BTNode *p;
	SqQueue *qu;
	InitQueue(qu);					//��ʼ������
	enQueue(qu,b);					//�����ָ��������
	while (!QueueEmpty(qu))			//�Ӳ�Ϊ��ѭ��
	{
		deQueue(qu,p);				//���ӽڵ�p
		printf("%c ",p->data);		//���ʽڵ�p
		if (p->lchild!=NULL)		//������ʱ�������
			enQueue(qu,p->lchild);
		if (p->rchild!=NULL)		//���Һ���ʱ�������
			enQueue(qu,p->rchild);
	} 
}
int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTree(b);printf("\n");
	printf("��α�������:");LevelOrder(b);printf("\n");
	DestroyBTree(b);
	return 1;
}
