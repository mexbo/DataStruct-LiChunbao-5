//����7.18�����㷨�����ò�α�����������Ӹ��ڵ㵽ÿ��Ҷ�ӽڵ��·��������
#include "btree.cpp"
#define MaxSize 100

//----------------------------------------------------------
//-�ǻ��ζ��еĻ��������㷨---------------------------------
//----------------------------------------------------------
typedef struct snode
{
	BTNode *pt;						//��ŵ�ǰ�ڵ�ָ��
	int parent;						//���˫�׽ڵ��ڶ����е�λ��
} NodeType;							//�ǻ��ζ���Ԫ������

typedef struct
{
	NodeType data[MaxSize];			//��Ŷ���Ԫ��
	int front,rear;					//��ͷָ��Ͷ�βָ��
} QuType;							//˳�������


void InitQueue(QuType *&q)			//��ʼ������
{	q=(QuType *)malloc (sizeof(QuType));
	q->front=q->rear=-1;
}
void DestroyQueue(QuType *&q)		//���ٶ���
{
	free(q);
}
bool QueueEmpty(QuType *q)			//�ж϶����Ƿ�Ϊ��
{
	return(q->front==q->rear);
}
bool enQueue(QuType *&q,NodeType e)	//������
{	if (q->rear==MaxSize-1)			//���������
		return false;				//���ؼ�
	q->rear++;						//��β��1
	q->data[q->rear]=e;				//rearλ�ò���Ԫ��e
	return true;					//������
}
bool deQueue(QuType *&q,NodeType &e) //������
{	if (q->front==q->rear)			//�ӿ������
		return false;
	q->front++;
	e=q->data[q->front];
	return true;
}
//----------------------------------------------------------
void AllPath2(BTNode *b)
{
	int k;
	BTNode *p;
	NodeType qelem;
	QuType *qu;							//����Ƿǻ��ζ���ָ��
	InitQueue(qu);						//��ʼ������
	qelem.pt=b; qelem.parent=-1;		//�������ڵ��Ӧ�Ķ���Ԫ��
	enQueue(qu,qelem);					//���ڵ����
	while (!QueueEmpty(qu))				//�Ӳ���ѭ��
	{
		deQueue(qu,qelem);				//����Ԫ��qelem,���ڶ����±�Ϊqu->front
		p=qelem.pt;						//ȡԪ��qelem�Ľڵ�p
		if (p->lchild==NULL && p->rchild==NULL)	//�ڵ�pΪҶ�ӽڵ�
		{
			k=qu->front;				//����ڵ�p�����ڵ��·��������
			while (qu->data[k].parent!=-1)
			{
				printf("%c->",qu->data[k].pt->data);
				k=qu->data[k].parent;
			}
			printf("%c\n",qu->data[k].pt->data);
		}
		if (p->lchild!=NULL)			//�ڵ�p������
		{
			qelem.pt=p->lchild;			//�����ڵ�p�����Ӷ�Ӧ�Ķ���Ԫ��
			qelem.parent=qu->front;		//�ڵ�p�����ӵ�˫��λ��Ϊqu->front
			enQueue(qu,qelem);			//�ڵ�p�����ӽ���
		}
		if (p->rchild!=NULL)			//�ڵ�p���Һ���
		{
			qelem.pt=p->rchild;			//�����ڵ�p���Һ��Ӷ�Ӧ�Ķ���Ԫ��
			qelem.parent=qu->front;		//�ڵ�p���Һ��ӵ�˫��λ��Ϊqu->front
			enQueue(qu,qelem);			//�ڵ�p���Һ��ӽ���
		}
	}
}

int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTree(b);printf("\n");
	printf("�Ӹ��ڵ㵽ÿ��Ҷ�ӽڵ��·��������:\n");
	AllPath2(b);
	DestroyBTree(b);
	return 1;
}