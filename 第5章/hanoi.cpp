//���Hanoi����ĵݹ�ͷǵݹ��㷨
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
void Hanoi1(int n,char a,char b,char c)
{
	if (n==1) 
		printf("\t����%d����Ƭ��%c�ƶ���%c\n",n,a,c);
    else 
	{
		Hanoi1(n-1,a,c,b);
		printf("\t����%d����Ƭ��%c�ƶ���%c\n",n,a,c);
		Hanoi1(n-1,b,a,c);
	}
}

typedef struct
{	int n;							//��Ƭ����
	char x,y,z;						//3������
	bool flag;						//��ֱ���ƶ���ƬʱΪtrue,����Ϊfalse
} ElemType;							//˳��ջ��Ԫ������
typedef struct
{	ElemType data[MaxSize];			//���Ԫ��
	int top;						//ջ��ָ��
} StackType;						//˳��ջ����

//--���Hanoi�����Ӧ˳��ջ�Ļ��������㷨--------------
void InitStack(StackType *&s)			//��ʼ��ջ
{	s=(StackType *)malloc(sizeof(StackType));
	s->top=-1;
}
void DestroyStack(StackType *&s)		//����ջ
{
	free(s);
}
bool StackEmpty(StackType *s)			//�ж�ջ�Ƿ�Ϊ��
{
	return(s->top==-1);
}
bool Push(StackType *&s,ElemType e)		//��ջ
{	if (s->top==MaxSize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}
bool Pop(StackType *&s,ElemType &e)		//��ջ
{	if (s->top==-1)
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(StackType *s,ElemType &e)		//ȡջ��Ԫ��
{	if (s->top==-1)
		return false;
	e=s->data[s->top];
	return true;
}
//----------------------------------------------------
void Hanoi2(int n, char x, char y, char z)
{	StackType *st;							//����˳��ջָ��
	ElemType e,e1,e2,e3;
	if (n<=0) return;						//��������ʱֱ�ӷ���
	InitStack(st);							//��ʼ��ջ
	e.n=n; e.x=x; e.y=y; e.z=z; e.flag=false;
	Push(st,e);								//Ԫ��e��ջ
	while (!StackEmpty(st))					//ջ����ѭ��
	{	Pop(st,e);							//��ջԪ��e
		if (e.flag==false)					//������ֱ���ƶ���Ƭʱ
		{
			e1.n=e.n-1; e1.x=e.y; e1.y=e.x; e1.z=e.z;
			if (e1.n==1)					//ֻ��һ����Ƭʱ��ֱ���ƶ�
				e1.flag=true;
			else							//��һ��������Ƭʱ����ֱ���ƶ�
				e1.flag=false;
			Push(st,e1);					//����Hanoi(n-1,y,x,z)����
			e2.n=e.n; e2.x=e.x; e2.y=e.y; e2.z=e.z; e2.flag=true;
			Push(st,e2);					//����move(n,x,z)����
			e3.n=e.n-1; e3.x=e.x; e3.y=e.z; e3.z=e.y;
			if (e3.n==1)					//ֻ��һ����Ƭʱ��ֱ���ƶ�
				e3.flag=true;
			else
				e3.flag=false;				//��һ��������Ƭʱ����ֱ���ƶ�
			Push(st,e3);					//����Hanoi(n-1,x,z,y)����
		}
		else								//������ֱ���ƶ�ʱ
			printf("\t����%d����Ƭ��%c�ƶ���%c\n",e.n,e.x,e.z);
	}
	DestroyStack(st);						//����ջ
}

int main()
{
	int n=3;
	printf("�ݹ��㷨��%d����Ƭ�ƶ�����:\n",n);
	Hanoi1(n,'X','Y','Z');
	printf("�ǵݹ��㷨��%d����Ƭ�ƶ�����:\n",n);
	Hanoi2(n,'X','Y','Z');
	return 1;
}