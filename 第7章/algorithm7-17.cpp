//����7.17�����㷨�����ú�������ǵݹ��㷨����Ӹ��ڵ㵽ÿ��Ҷ�ӽڵ��·��������
#include "btree.cpp"

typedef struct 
{	BTNode *data[MaxSize];			//���ջ�е�����Ԫ��
	int top;						//���ջ��ָ�룬��ջ��Ԫ����data�����е��±�
} SqStack;							//˳��ջ����

void InitStack(SqStack *&s)			//��ʼ��ջ
{	s=(SqStack *)malloc(sizeof(SqStack));//����һ����˳��ջ�ռ䣬�׵�ַ�����s��
	s->top=-1;						//ջ��ָ����Ϊ-1
}
void DestroyStack(SqStack *&s)		//����ջ
{
	free(s);
}
bool StackEmpty(SqStack *s)			//�ж�ջ�Ƿ�Ϊ��
{
	return(s->top==-1);
}
bool Push(SqStack *&s,BTNode *e)	//��ջ
{	if (s->top==MaxSize-1)			//ջ�����������ջ�����
		return false;
	s->top++;						//ջ��ָ����1
	s->data[s->top]=e;				//Ԫ��e����ջ��ָ�봦
	return true;
}
bool Pop(SqStack *&s,BTNode *&e)	//��ջ
{	if (s->top==-1)					//ջΪ�յ��������ջ�����
		return false;
	e=s->data[s->top];				//ȡջ��ָ��Ԫ�ص�Ԫ��
	s->top--;						//ջ��ָ���1
	return true;
}
bool GetTop(SqStack *s,BTNode *&e)	//ȡջ��Ԫ��
{	if (s->top==-1)					//ջΪ�յ��������ջ�����
		return false;
	e=s->data[s->top];				//ȡջ��Ԫ��
	return true;
}
void AllPath1(BTNode *b)
{	BTNode *p,*r;
	bool flag;
	SqStack *st;					//����һ��˳��ջָ��st
	InitStack(st);					//��ʼ��ջst
	p=b;
	do
	{	while (p!=NULL)				//ɨ��ڵ�p���������½ڵ㲢��ջ
		{	Push(st,p);				//�ڵ�p��ջ
			p=p->lchild;			//�ƶ�������
		}
		r=NULL;						//rָ��ոշ��ʵĽڵ㣬��ʼʱΪ��
		flag=true;					//flagΪ���ʾ���ڴ���ջ���ڵ�
		while (!StackEmpty(st) && flag)
		{	GetTop(st,p);			//ȡ����ǰ��ջ���ڵ�p
			if (p->rchild==r)		//���ڵ�p���Һ���Ϊ�ջ���Ϊ�ոշ��ʹ��Ľڵ�
			{	if (p->lchild==NULL && p->rchild==NULL)	//��ΪҶ�ӽڵ�
				{					//���ջ�����нڵ�ֵ
					for (int i=st->top;i>0;i--)
						printf("%c->",st->data[i]->data);
					printf("%c\n",st->data[0]->data);
				}
				Pop(st,p);
				r=p;				//rָ��շ��ʹ��Ľڵ�
			}
			else
			{	p=p->rchild;		//ת������������
				flag=false;			//��ʾ��ǰ���Ǵ���ջ���ڵ�
			}
		}
	} while (!StackEmpty(st));		//ջ����ѭ��
}

int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTree(b);printf("\n");
	printf("������д�Ҷ�ӽڵ㵽���ڵ������:\n");
	AllPath1(b);
	DestroyBTree(b);
	return 1;
}
