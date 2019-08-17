//��������ͺ���ǵݹ�����㷨
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

void PreOrder1(BTNode *b)			//����ǵݹ�����㷨1
{
	BTNode *p;
	SqStack *st;					//����һ��˳��ջָ��st
	InitStack(st);					//��ʼ��ջst
	Push(st,b);					//���ڵ��ջ
	while (!StackEmpty(st))		//ջ��Ϊ��ʱѭ��
	{
		Pop(st,p);				//��ջ�ڵ�p��������
		printf("%c ",p->data);	//���ʽڵ�p
		if (p->rchild!=NULL)	//���Һ���ʱ�����ջ
			Push(st,p->rchild);
		if (p->lchild!=NULL)	//������ʱ�����ջ
			Push(st,p->lchild);
	}
	printf("\n");
	DestroyStack(st);				//����ջ
}
void PreOrder2(BTNode *b)			//����ǵݹ�����㷨2
{
	BTNode *p;
	SqStack *st;					//����һ��˳��ջָ��st
	InitStack(st);					//��ʼ��ջst
	p=b;
	while (!StackEmpty(st) || p!=NULL)
	{
		while (p!=NULL)				//���ʽڵ�p�����������½ڵ㲢��ջ
		{
			printf("%c ",p->data);	//���ʽڵ�p
			Push(st,p);				//�ڵ�p��ջ
			p=p->lchild;			//�ƶ�������
		}
		if (!StackEmpty(st))		//��ջ����
		{
			Pop(st,p);				//��ջ�ڵ�p
			p=p->rchild;			//ת������������
		}
	}
	printf("\n");
	DestroyStack(st);				//����ջ
}
void InOrder1(BTNode *b)				//����ǵݹ�����㷨
{
	BTNode *p;
	SqStack *st;						//����һ��˳��ջָ��st
	InitStack(st);						//��ʼ��ջst
	if (b!=NULL)
	{
		p=b;
		while (!StackEmpty(st) || p!=NULL)
		{
			while (p!=NULL)				//ɨ��ڵ�p���������½ڵ㲢��ջ
			{
				Push(st,p);				//�ڵ�p��ջ
				p=p->lchild;			//�ƶ�������
			}
			if (!StackEmpty(st))		//��ջ����
			{
				Pop(st,p);				//��ջ�ڵ�p
				printf("%c ",p->data);	//���ʽڵ�p
				p=p->rchild;			//ת������������
			}
		}
		printf("\n");
	}
	DestroyStack(st);				//����ջ
}

void PostOrder1(BTNode *b)				//����ǵݹ�����㷨
{
	BTNode *p,*r;
	bool flag;
	SqStack *st;						//����һ��˳��ջָ��st
	InitStack(st);						//��ʼ��ջst
	p=b;
	do
	{
		while (p!=NULL)					//ɨ��ڵ�p���������½ڵ㲢��ջ
		{
			Push(st,p);					//�ڵ�p��ջ
			p=p->lchild;				//�ƶ�������
		}
		r=NULL;							//rָ��ոշ��ʵĽڵ㣬��ʼʱΪ��
		flag=true;						//flagΪ���ʾ���ڴ���ջ���ڵ�
		while (!StackEmpty(st) && flag)
		{
			GetTop(st,p);				//ȡ����ǰ��ջ���ڵ�p
			if (p->rchild==r)			//���ڵ�p���Һ���Ϊ�ջ���Ϊ�ոշ��ʹ��Ľڵ�	
			{
				printf("%c ",p->data);	//���ʽڵ�p
				Pop(st,p);
				r=p;					//rָ��շ��ʹ��Ľڵ�
			}
			else
			{	
				p=p->rchild;			//ת������������
				flag=false;				//��ʾ��ǰ���Ǵ���ջ���ڵ�
			}
		}
	} while (!StackEmpty(st));			//ջ����ѭ��
	printf("\n");
	DestroyStack(st);				//����ջ
}

int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTree(b);printf("\n");
	printf("�����������1:");PreOrder1(b);
	printf("�����������2:");PreOrder2(b);
	printf("�����������:");InOrder1(b);
	printf("�����������:");PostOrder1(b);
	DestroyBTree(b);
	return 1;
}
