//AVL�㷨
#include <stdio.h>
#include <malloc.h>
typedef int KeyType;					//�ؼ�������
typedef char InfoType;
typedef struct node               		//��¼����
{	
	KeyType key;                  		//�ؼ�����
    int bf;								//ƽ������
    InfoType data;               		//����������
    struct node *lchild,*rchild;		//���Һ���ָ��
} BSTNode;
void LeftProcess(BSTNode *&p,int &taller)
//����ָ��p��ָ���Ϊ���Ķ���������ƽ����ת����,���㷨����ʱ,ָ��pָ���µĸ����
{
	BSTNode *p1,*p2;
	if (p->bf==0)			//ԭ�����������ȸ�,�������������߶�ʹ������
	{
		p->bf=1;
		taller=1;
	}
	else if (p->bf==-1)		//ԭ������������������,�����������ȸ� 
	{
		p->bf=0;
		taller=0;
	}
	else					//ԭ������������������,������������ƽ�⴦��
	{
		p1=p->lchild;		//p1ָ����p������
		if (p1->bf==1)		//�½������ڽ��b�����ӵ���������,Ҫ��LL����
		{
			p->lchild=p1->rchild;
			p1->rchild=p;
			p->bf=p1->bf=0;
			p=p1;
		}
		else if (p1->bf==-1)	//�½������ڽ��b�����ӵ���������,Ҫ��LR����
		{
			p2=p1->rchild;
			p1->rchild=p2->lchild;
			p2->lchild=p1;
			p->lchild=p2->rchild;
			p2->rchild=p;
			if (p2->bf==0)			//�½�����p2����ΪҶ�ӽ������
				p->bf=p1->bf=0;	
			else if (p2->bf==1)		//�½�����p2���������ϵ����
			{
				p1->bf=0;p->bf=-1;
			}
			else					//�½�����p2���������ϵ����
			{
				p1->bf=1;p->bf=0;
			}
			p=p2;p->bf=0;			//�Խ�pָ���µĸ����,������bfֵΪ0
		}
		taller=0;
	}
}
void RightProcess(BSTNode *&p,int &taller)
//����ָ��p��ָ���Ϊ���Ķ���������ƽ����ת����,���㷨����ʱ,ָ��pָ���µĸ����
{
	BSTNode *p1,*p2;
	if (p->bf==0)			//ԭ�����������ȸ�,�������������߶�ʹ������
	{
		p->bf=-1;
		taller=1;
	}
	else if (p->bf==1)		//ԭ������������������,�����������ȸ�
	{
		p->bf=0;	
		taller=0;
	}
	else					//ԭ������������������,������������ƽ�⴦��
	{
		p1=p->rchild;		//p1ָ����p�������������
		if (p1->bf==-1)		//�½������ڽ��b���Һ��ӵ���������,Ҫ��RR����
		{
			p->rchild=p1->lchild;
			p1->lchild=p;
			p->bf=p1->bf=0;
			p=p1;
		}
		else if (p1->bf==1)		//�½������ڽ��p���Һ��ӵ���������,Ҫ��RL����
		{
			p2=p1->lchild;
			p1->lchild=p2->rchild;
			p2->rchild=p1;
			p->rchild=p2->lchild;
			p2->lchild=p;
			if (p2->bf==0)			//�½�����p2����ΪҶ�ӽ������
				p->bf=p1->bf=0;	
			else if (p2->bf==-1)	//�½�����p2���������ϵ����
			{
				p1->bf=0;p->bf=1;
			}
			else					//�½�����p2���������ϵ����
			{
				p1->bf=-1;p->bf=0;
			}
			p=p2;p->bf=0;			//�Խ�pָ���µĸ����,������bfֵΪ0
		}
		taller=0;
	}
}
int InsertAVL(BSTNode *&b,KeyType e,int &taller)
/*����ƽ��Ķ���������b�в����ں�e����ͬ�ؼ��ֵĽ��,�����һ��
  ����Ԫ��Ϊe���½��,������1,���򷵻�0����������ʹ����������
  ʧȥƽ��,����ƽ����ת����,��������taller��ӳb�������*/
{
	  if(b==NULL)			//ԭΪ����,�����½��,�������ߡ�,��tallerΪ1
	{ 
		b=(BSTNode *)malloc(sizeof(BSTNode));
		b->key=e;
		b->lchild=b->rchild=NULL;
		b->bf=0;
		taller=1;
	}
    else
    {
		if (e==b->key)				//�����Ѵ��ں�e����ͬ�ؼ��ֵĽ�����ٲ���
		{ 
			taller=0;
			return 0;
		}
		if (e<b->key)				//Ӧ�����ڽ��b���������н�������
		{ 
			if ((InsertAVL(b->lchild,e,taller))==0) //δ����
				return 0;
			if (taller==1)			//�Ѳ��뵽���b�����������������������ߡ�
				LeftProcess(b,taller);
		}
		else						//Ӧ�����ڽ��b���������н�������
		{ 
			if ((InsertAVL(b->rchild,e,taller))==0) //δ����
				return 0;
			if (taller==1)			//�Ѳ��뵽b���������������������ߡ�
				RightProcess(b,taller);
		}
    }
	return 1;
}
void DispBSTree(BSTNode *b)			//�����ű�ʾ�����AVL
{
	if (b!=NULL)
	{
		printf("%d",b->key);
		if (b->lchild!=NULL || b->rchild!=NULL)
		{
			printf("(");
			DispBSTree(b->lchild);
			if (b->rchild!=NULL) printf(",");
			DispBSTree(b->rchild);
			printf(")");
		}
	}
}
void DestroyAVL(BSTNode *&b)	//����AVL
{
	if (b!=NULL)
	{
		DestroyAVL(b->lchild);
		DestroyAVL(b->rchild);
		free(b);
	}
}
void LeftProcess1(BSTNode *&p,int &taller)	//��ɾ�����ʱ��������
{
	BSTNode *p1,*p2;
	if (p->bf==1)
	{
		p->bf=0;
		taller=1;
	}
	else if (p->bf==0)
	{
		p->bf=-1;
		taller=0;
	}
	else		//p->bf=-1
	{
		p1=p->rchild;
		if (p1->bf==0)			//����RR����
		{
			p->rchild=p1->lchild;
			p1->lchild=p;
			p1->bf=1;p->bf=-1;
			p=p1;
			taller=0;
		}
		else if (p1->bf==-1)	//����RL����
		{
			p->rchild=p1->lchild;
			p1->lchild=p;
			p->bf=p1->bf=0;
			p=p1;
			taller=1;
		}
		else					//����RL����
		{
			p2=p1->lchild;
			p1->lchild=p2->rchild;
			p2->rchild=p1;
			p->rchild=p2->lchild;
			p2->lchild=p;
			if (p2->bf==0)
			{
				p->bf=0;p1->bf=0;
			}
			else if (p2->bf==-1)
			{
				p->bf=1;p1->bf=0;
			}
			else
			{
				p->bf=0;p1->bf=-1;
			}
			p2->bf=0;
			p=p2;
			taller=1;
		}
	}
}
void RightProcess1(BSTNode *&p,int &taller) //��ɾ�����ʱ�����Ҵ���
{
	BSTNode *p1,*p2;
	if (p->bf==-1)
	{
		p->bf=0;
		taller=-1;
	}
	else if (p->bf==0)
	{
		p->bf=1;
		taller=0;
	}
	else		//p->bf=1
	{
		p1=p->lchild;
		if (p1->bf==0)			//����LL����
		{
			p->lchild=p1->rchild;
			p1->rchild=p;
			p1->bf=-1;p->bf=1;
			p=p1;
			taller=0;
		}
		else if (p1->bf==1)		//����RL����
		{
			p->lchild=p1->rchild;
			p1->rchild=p;
			p->bf=p1->bf=0;
			p=p1;
			taller=1;
		}
		else					//����LR����
		{
			p2=p1->rchild;
			p1->rchild=p2->lchild;
			p2->lchild=p1;
			p->lchild=p2->rchild;
			p2->rchild=p;
			if (p2->bf==0)
			{
				p->bf=0;p1->bf=0;
			}
			else if (p2->bf==1)
			{
				p->bf=-1;p1->bf=0;
			}
			else
			{
				p->bf=0;p1->bf=1;
			}
			p2->bf=0;
			p=p2;
			taller=1;
		}
	}
}
void Delete2(BSTNode *q,BSTNode *&r,int &taller)  
//��DeleteAVL()����,���ڴ���ɾ����������������յ����
{
	if (r->rchild==NULL)
	{
		q->key=r->key;
		q=r;
		r=r->lchild;
		free(q);
		taller=1;
	}
	else
	{
		Delete2(q,r->rchild,taller);
		if (taller==1) 
			RightProcess1(r,taller);
	}
}
int DeleteAVL(BSTNode *&p,KeyType x,int &taller) //��AVL��p��ɾ���ؼ���Ϊx�Ľ��
{
	int k;
	BSTNode *q;
	if (p==NULL) 
		return 0;
	else if (x<p->key)
	{
		k=DeleteAVL(p->lchild,x,taller);
		if (taller==1) 
			LeftProcess1(p,taller);
		return k;
	}
	else if (x>p->key)
	{
		k=DeleteAVL(p->rchild,x,taller);
		if (taller==1) 
			RightProcess1(p,taller);
		return k;
	}
	else			//�ҵ��˹ؼ���Ϊx�Ľ��,��pָ����
	{
		q=p;
		if (p->rchild==NULL)		//��ɾ���������Ϊ��
		{
			p=p->lchild;
			free(q);
			taller=1;
		}
		else if (p->lchild==NULL)	//��ɾ���������Ϊ��
		{
			p=p->rchild;
			free(q);
			taller=1;
		}
		else						//��ɾ�����������������
		{
			Delete2(q,q->lchild,taller);
			if (taller==1) 
				LeftProcess1(q,taller);
			p=q;
		}
		return 1;
	}
}
int main()
{
	BSTNode *b=NULL;
	int i,j,k;
	KeyType a[]={16,3,7,11,9,26,18,14,15},n=9;  //��9.5
	printf(" ����һ��AVL��:\n");
	for(i=0;i<n;i++)
	{
		printf("   ��%d��,����%dԪ��:",i+1,a[i]);
		InsertAVL(b,a[i],j);
		DispBSTree(b);printf("\n"); 
	}
	printf("   AVL:");DispBSTree(b);printf("\n");
	printf(" ɾ������:\n");						//��9.6
	k=11;
	printf("   ɾ���ؼ���%d:",k);
	DeleteAVL(b,k,j);
	printf("   AVL:");DispBSTree(b);printf("\n");
	k=9;
	printf("   ɾ���ؼ���%d:",k);
	DeleteAVL(b,k,j);
	printf("   AVL:");DispBSTree(b);printf("\n");
	k=15;
	printf("   ɾ���ؼ���%d:",k);
	DeleteAVL(b,k,j);
	printf("   AVL:");DispBSTree(b);printf("\n\n");
	DestroyAVL(b);
	return 1;
}