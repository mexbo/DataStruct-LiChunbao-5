//��ջ����Թ�����
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
#define M 8
#define N 8
int mg[M+2][N+2]=
{	
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
//---------------------------------------------------------
//--�Թ�ջ��������---------------------------------------
//---------------------------------------------------------
typedef struct
{
	int i;				//��ǰ������к�
	int j;				//��ǰ������к�
	int di;				//di����һ�������ڷ�λ�ķ�λ��
} Box;
typedef struct
{
	Box data[MaxSize];	//��ŷ���
    int top;			//ջ��ָ��
} StType;				//����ջ����

void InitStack(StType *&s)		//��ʼ��ջ
{	s=(StType *)malloc(sizeof(StType));
	s->top=-1;
}
void DestroyStack(StType *&s)	//����ջ
{
	free(s);
}
bool StackEmpty(StType *s)		//�ж�ջ�Ƿ�Ϊ��
{
	return(s->top==-1);
}
bool Push(StType *&s,Box e)	//��ջԪ��e
{
	if (s->top==MaxSize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}
bool Pop(StType *&s,Box &e)	//��ջԪ��e
{
	if (s->top==-1)	
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(StType *s,Box &e)	//ȡջ��Ԫ��e
{
	if (s->top==-1)	
		return false;
	e=s->data[s->top];
	return true;
}
//---------------------------------------------------------
bool mgpath(int xi,int yi,int xe,int ye)	//���·��Ϊ:(xi,yi)->(xe,ye)
{
	Box path[MaxSize], e;
	int i,j,di,i1,j1,k;
	bool find;
	StType *st;								//����ջst
	InitStack(st);							//��ʼ��ջ��ָ��
	e.i=xi; e.j=yi;	e.di=-1;				//����eΪ���
	Push(st,e);								//����e��ջ
	mg[xi][yi]=-1;							//��ڵ��Թ�ֵ��Ϊ-1�����ظ��ߵ��÷���
	while (!StackEmpty(st))					//ջ����ʱѭ��
	{
		GetTop(st,e);						//ȡջ������e
		i=e.i; j=e.j; di=e.di;
		if (i==xe && j==ye)					//�ҵ��˳���,�����·��
		{ 
			printf("һ���Թ�·������:\n");
			k=0;
			while (!StackEmpty(st))
			{
				Pop(st,e);					//��ջ����e
				path[k++]=e;				//��e��ӵ�path������
			}
			while (k>=1)
			{
				k--;
				printf("\t(%d,%d)",path[k].i,path[k].j);
				if ((k+2)%5==0)				//ÿ���ÿ5�������һ��
					printf("\n");  
			}
			printf("\n");
			DestroyStack(st);				//����ջ
			return true;					//���һ���Թ�·���󷵻�true
		}
		find=false;
		while (di<4 && !find)				//�����ڿ��߷���(i1,j1)
		{	
			di++;
			switch(di)
			{
			case 0:i1=i-1; j1=j;   break;
			case 1:i1=i;   j1=j+1; break;
			case 2:i1=i+1; j1=j;   break;
			case 3:i1=i;   j1=j-1; break;
			}
			if (mg[i1][j1]==0) find=true;	//�ҵ�һ�����ڿ��߷��飬����find����
		}
		if (find)							//�ҵ���һ�����ڿ��߷���(i1,j1)
		{	

			st->data[st->top].di=di;		//�޸�ԭջ��Ԫ�ص�diֵ
			e.i=i1; e.j=j1; e.di=-1;
			Push(st,e);						//���ڿ��߷���e��ջ
			mg[i1][j1]=-1;					//(i1,j1)���Թ�ֵ��Ϊ-1�����ظ��ߵ��÷���
		}
		else								//û��·������,����ջ
		{	
			Pop(st,e);						//��ջ��������ջ
			mg[e.i][e.j]=0;					//����ջ�����λ�ñ�Ϊ����·�����߷���
		}
	}
	DestroyStack(st);						//����ջ
	return false;							//��ʾû�п���·��,����false
}
int main()
{
	mgpath(1,1,M,N);
	return 1;
}