//�������Ļ��������㷨
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node 
{	
	ElemType data;			//����Ԫ��
	struct node *lchild;	//ָ�����ӽڵ�
	struct node *rchild;	//ָ���Һ��ӽڵ�
} BTNode;
void CreateBTree(BTNode * &b,char *str)	//����������
{
	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  
	char ch;
	b=NULL;				//�����Ķ�������ʼʱΪ��
	ch=str[j];
	while (ch!='\0')  	//strδɨ����ʱѭ��
	{
   	   	switch(ch) 
		{
		case '(':top++;St[top]=p;k=1; break;		//Ϊ���ӽڵ�
		case ')':top--;break;
		case ',':k=2; break;                      		//Ϊ���ӽڵ��ҽڵ�
		default:p=(BTNode *)malloc(sizeof(BTNode));
				p->data=ch;p->lchild=p->rchild=NULL;
				if (b==NULL)                    	 	//*pΪ�������ĸ��ڵ�
					b=p;
				else  								//�ѽ������������ڵ�
				{	
					switch(k) 
					{
					case 1:St[top]->lchild=p;break;
					case 2:St[top]->rchild=p;break;
					}
				}
		}
		j++;
		ch=str[j];
	}
}
void DestroyBTree(BTNode *&b)
{	if (b!=NULL)
	{	DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}
BTNode *FindNode(BTNode *b,ElemType x) 
{
	BTNode *p;
	if (b==NULL)
		return NULL;
	else if (b->data==x)
		return b;
	else  
	{
		p=FindNode(b->lchild,x);
		if (p!=NULL) 
			return p;
		else 
			return FindNode(b->rchild,x);
	}
}
BTNode *LchildNode(BTNode *p)
{
    return p->lchild;
}
BTNode *RchildNode(BTNode *p)
{
    return p->rchild;
}
int BTHeight(BTNode *b) 
{
   	int lchildh,rchildh;
   	if (b==NULL) return(0); 				//�����ĸ߶�Ϊ0
   	else  
	{
		lchildh=BTHeight(b->lchild);	//���������ĸ߶�Ϊlchildh
		rchildh=BTHeight(b->rchild);	//���������ĸ߶�Ϊrchildh
		return (lchildh>rchildh)? (lchildh+1):(rchildh+1);
   	}
}
void DispBTree(BTNode *b) 
{
	if (b!=NULL)
	{	printf("%c",b->data);
		if (b->lchild!=NULL || b->rchild!=NULL)
		{	printf("(");						//�к��ӽڵ�ʱ�����(
			DispBTree(b->lchild);				//�ݹ鴦��������
			if (b->rchild!=NULL) printf(",");	//���Һ��ӽڵ�ʱ�����,
			DispBTree(b->rchild);				//�ݹ鴦��������
			printf(")");						//�к��ӽڵ�ʱ�����)
		}
	}
}
/*������������������
void main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E),C(,F))");
	DispBTree(b);
	printf("\n");
}
*/