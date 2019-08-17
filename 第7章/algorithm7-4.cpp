//����7.4�����㷨�������ֵ����洢�ṹ�����Ļ��������㷨������t�ĸ߶�
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef struct tnode 
{	char data;						//�ڵ��ֵ
	struct tnode *hp;				//ָ���ֵ�
	struct tnode *vp;				//ָ���ӽڵ�
} TSBNode;							//�����ֵ����洢�ṹ����

TSBNode *CreateTree(char *str)		//��str���������ֵ����洢�ṹ
{	struct
	{	TSBNode *nodep;				//�ڵ�ָ��
		int num;					//���Ӹ���
	} St[MaxSize];					//˳��ջ
	int top=-1;						//ջ��ָ��
	int i=0,j; char ch=str[i];
	TSBNode *t=NULL,*p,*q;
	while (ch!='\0')
	{	switch(ch)
		{
		case '(': top++; St[top].nodep=p;
			St[top].num=0;				//��ǰ�ڵ�p��ջ
			break;
		case ')':top--;	break;			//��ջ
		case ',':St[top].num++; break;	//ջ���ڵ�����һ������
		default:
			p=(TSBNode *)malloc(sizeof(TSBNode));
			p->data=ch;					//����һ���ڵ�p���ch
			p->hp=p->vp=NULL;
			if (t==NULL)				//ԭΪ����
				t=p;
			else						//������Ϊջ���ڵ��һ������
			{	if (St[top].num==0)		//��һ��������vpָ����
					St[top].nodep->vp=p;
				else					//����������ջ���ڵ�ĺ��ӽڵ��hpָ����
				{	q=St[top].nodep->vp;
					for (j=1;j<St[top].num;j++)
						q=q->hp;	
					q->hp=p;
				}
			}
			break;
		}
		i++;
		ch=str[i];
	}
	return t;
}
void DispTree(TSBNode *t)		//��������ֵ����洢�ṹ
{	TSBNode *p;
	if (t!=NULL)
	{	printf("%c",t->data);
		if (t->vp!=NULL)		//�к���ʱ���һ��'('
		{	printf("(");
			p=t->vp;			//pָ��ڵ�t�ĵ�һ������
			while (p!=NULL)
			{	DispTree(p);
				p=p->hp;
				if (p!=NULL)
					printf(",");
			}
			printf(")");		//���һ��')'
		}
	}
}
void DestroryTree(TSBNode *&t)	//������t
{	if (t!=NULL)
	{	DestroryTree(t->vp);
		DestroryTree(t->hp);
		free(t);				//�ͷŸ��ڵ�
	}
}
int TreeHeight2(TSBNode *t)
{	TSBNode *p;
	int h,maxh=0;
	if (t==NULL) return 0;		//��������0
	else
	{	p=t->vp;				//ָ���1�����ӽڵ�
		while (p!=NULL)			//ɨ��t����������
		{	h=TreeHeight2(p);	//���p�����ĸ߶�
			if (maxh<h) maxh=h;	//���������������߶�
			p=p->hp;			//��������t����������
		}
		return(maxh+1);			//����maxh+1
	}
}

int main()
{
	TSBNode *t;
	t=CreateTree("A(B,C(E,F,G),D)");
	printf("t:"); DispTree(t);
	printf("\n��t�ĸ߶�:%d\n",TreeHeight2(t));
	DestroryTree(t);
	return 1;
}
