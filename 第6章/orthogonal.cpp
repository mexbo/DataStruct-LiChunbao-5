//ϡ������ʮ�������ʾ
#include <stdio.h>
#include <malloc.h>
#define M 3         			//������
#define N 4           			//������
#define Max ((M)>(N)?(M):(N))   //�������нϴ���
typedef int ElemType;
typedef struct mtxn 
{ 
	int row;					//�к�
	int col;					//�к�
   	struct mtxn *right,*down;	//���Һ����µ�ָ��
	union 
	{
		ElemType value;
		struct mtxn *link;
	} tag;
} MatNode;			//ʮ����������
void CreatMat(MatNode *&mh,ElemType a[][N])	//����a��ʮ������
{
	int i,j;
	MatNode *h[Max],*p,*q,*r;
	mh=(MatNode *)malloc(sizeof(MatNode));//����ʮ�������ͷ���
	mh->row=M;mh->col=N;
	r=mh;					//rָ��β���
	for (i=0;i<Max;i++)		//����β�巨����ͷ���h1,h2,��ѭ������
	{
		h[i]=(MatNode *)malloc(sizeof(MatNode));
		h[i]->down=h[i]->right=h[i];		//��down��right������Ϊѭ����
		r->tag.link=h[i];					//��h[i]�ӵ�������
		r=h[i];
	}
	r->tag.link=mh;							//��Ϊѭ������
	for (i=0;i<M;i++)						//����ÿһ��
	{
		for (j=0;j<N;j++)					//����ÿһ��
		{
			if (a[i][j]!=0)					//�������Ԫ��
			{
				p=(MatNode *)malloc(sizeof(MatNode));	//����һ���½��
				p->row=i;p->col=j;p->tag.value=a[i][j];
				q=h[i];      					//�������б��еĲ���λ��
                while (q->right!=h[i] && q->right->col<j) 
                  	q=q->right;
				p->right=q->right;q->right=p;	//����б�Ĳ���
				q=h[j];      					//�������б��еĲ���λ��
				while (q->down!=h[j] && q->down->row<i) 
					q=q->down;
				p->down=q->down;q->down=p;  	//����б�Ĳ���
			}
		}
	}
}
void DestroyMat(MatNode *&mh)		//����ʮ������
{
	MatNode *pre,*p,*mp;
	mp=mh->tag.link;				//mpָ��h[i]
	while (mp!=mh)					//�ͷ��������ݽ��
	{
		pre=mp->right;				//preָ��h[i]�����׽��
		if (pre!=mp)				//h[i]����
		{
			p=pre->right;			//pָ����pre�ĺ�̽��
			while (p!=mp)
			{
				free(pre);
				pre=p; p=p->right;
			}
		}
		mp=mp->tag.link;			//mpָ����һ��ͷ���
	}
	//�ͷ����е�ͷ���
	pre=mh->tag.link;				//preָ��h[i]
	p=pre->tag.link;				//pָ��h[i+1]
	while (p!=mh)
	{
		free(pre);
		pre=p; p=p->tag.link;
	}
	free(mh);
}
void DispMat(MatNode *mh)		//���ʮ������
{
	MatNode *p,*q;
	printf("��=%d  ��=%d\n", mh->row,mh->col);
	p=mh->tag.link;
	while (p!=mh) 
	{	
		q=p->right;
		while (p!=q) 		//���һ�з���Ԫ��
		{
			printf("%d\t%d\t%d\n", q->row,q->col,q->tag.value);
			q=q->right;
		}
		p=p->tag.link;
	}
}
//�����������ڵ���
int main()
{
	ElemType a[M][N]={{1,0,0,2},{0,0,3,0},{0,0,0,4}};
	MatNode *mx;
	CreatMat(mx,a);
	printf("a��ʮ������:\n");DispMat(mx);
	DestroyMat(mx);
	return 1;
}
