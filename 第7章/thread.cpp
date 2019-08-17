//�����������������㷨
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node 
{
	ElemType data;
	int ltag,rtag;      //���ӵ��������
	struct node *lchild;
	struct node *rchild;
} TBTNode;
void CreateTBTree(TBTNode * &b,char *str)
{
	TBTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  
	char ch;
	b=NULL;				//�����Ķ�������ʼʱΪ��
	ch=str[j];
	while (ch!='\0')	//strδɨ����ʱѭ��
	{
   	   	switch(ch) 
		{
		case '(':top++;St[top]=p;k=1; break;		//Ϊ��ڵ�
		case ')':top--;break;
		case ',':k=2; break;                      	//Ϊ�ҽڵ�
		default:p=(TBTNode *)malloc(sizeof(TBTNode));
				p->data=ch;p->lchild=p->rchild=NULL;
		        if (b==NULL)					//*pΪ�������ĸ��ڵ�
					b=p;
				else  							//�ѽ������������ڵ�
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
void DispTBTree(TBTNode *b) 
{
	if (b!=NULL)
	{
		printf("%c",b->data);
		if (b->lchild!=NULL || b->rchild!=NULL)
		{
			printf("(");
			DispTBTree(b->lchild);
			if (b->rchild!=NULL) printf(",");
			DispTBTree(b->rchild);
			printf(")");
		}
	}
}
TBTNode *pre;						//ȫ�ֱ���
void Thread(TBTNode *&p)
{
	if (p!=NULL)	
	{	
		Thread(p->lchild);    		//������������
		if (p->lchild==NULL)		//ǰ������
		{
			p->lchild=pre;        	//������ǰ�ڵ��ǰ������
			p->ltag=1;
		}
		else p->ltag=0;
		if (pre->rchild==NULL)		//�������
		{	
			pre->rchild=p;     		//����ǰ���ڵ�ĺ������
		   	pre->rtag=1;
		}
		else pre->rtag=0;
	    pre=p;
	   	Thread(p->rchild);  		//������������
	}
}
TBTNode *CreateThread(TBTNode *b)     //����������������
{
	TBTNode *root;
	root=(TBTNode *)malloc(sizeof(TBTNode));  //�������ڵ�
	root->ltag=0;root->rtag=1;
	root->rchild=b;
	if (b==NULL)                //�ն�����
		root->lchild=root;
	else
	{  	
		root->lchild=b;
		pre=root;             	//pre��*p��ǰ���ڵ�,����������
		Thread(b);   			//�������������������
		pre->rchild=root;    	//�����,����ָ����ڵ������
		pre->rtag=1;
		root->rchild=pre;    	//���ڵ���������
	}
    return root;
}
void DestroyTBTree1(TBTNode *&b)	//����
{	if (b->ltag==0)					//�ڵ�b������,�ͷ�������
		DestroyTBTree1(b->lchild);
	if (b->rtag==0)					//�ڵ�b���Һ���,�ͷ�������
		DestroyTBTree1(b->rchild);
	free(b);
}
void DestroyTBTree(TBTNode *&tb)	//����һ�ô�ͷ��������������tb
{
	DestroyTBTree1(tb->lchild);		//�ͷ���tb->lchildΪ���ڵ����
	free(tb);						//�ͷ�ͷ�ڵ�
}

void ThInOrder(TBTNode *tb)
{
	TBTNode *p=tb->lchild;		//ָ����ڵ�
	while (p!=tb)		
	{
		while (p->ltag==0) p=p->lchild;
		printf("%c ",p->data);
		while (p->rtag==1 && p->rchild!=tb)
		{
			p=p->rchild;
			printf("%c ",p->data);
		}
		p=p->rchild;
	}
}
int main()
{
	TBTNode *b,*tb;
	CreateTBTree(b,"A(B(D(,G)),C(E,F))");
	printf(" ������:");DispTBTree(b);printf("\n");
	tb=CreateThread(b);
	printf(" ������������:");ThInOrder(tb);printf("\n");
	DestroyTBTree(tb);
	return 1;
}