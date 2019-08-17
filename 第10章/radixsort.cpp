//���λ���ȵĻ��������㷨
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXE 20			//���Ա������Ԫ�ظ���
#define MAXR 10			//���������ȡֵ
#define MAXD 8			//�ؼ���λ�������ȡֵ
typedef struct node
{	
	char data[MAXD];	//��¼�Ĺؼ��ֶ�����ַ���
    struct node *next;
} NodeType;
void CreaLink(NodeType *&p,char *a[],int n);
void DispLink(NodeType *p);
void RadixSort(NodeType *&p,int r,int d) //ʵ�ֻ�������:pΪ��������������ָ��,rΪ����,dΪ�ؼ���λ��
{
	NodeType *head[MAXR],*tail[MAXR],*t;//��������ӵ���βָ��
	int i,j,k;
	for (i=0;i<=d-1;i++)           		//�ӵ�λ����λѭ��
	{	
		for (j=0;j<r;j++) 				//��ʼ���������ס�βָ��
			head[j]=tail[j]=NULL;
		while (p!=NULL)          		//����ԭ������ÿ�����ѭ��
		{	
			k=p->data[i]-'0';   		//�ҵ�k������
			if (head[k]==NULL)   		//���з���
			{
				head[k]=p;
				tail[k]=p;
			}
          	else
			{
              	tail[k]->next=p;
				tail[k]=p;
			}
            p=p->next;             		//ȡ��һ���������Ԫ��
		}
		p=NULL;							//������p���ռ����н��
       	for (j=0;j<r;j++)        		//����ÿһ������ѭ��
        	if (head[j]!=NULL)         	//�����ռ�
			{	
				if (p==NULL)
				{
					p=head[j];
					t=tail[j];
				}
				else
				{
					t->next=head[j];
					t=tail[j];
				}
			}
		t->next=NULL;					//���һ������next����NULL
		printf("  ��%sλ����\t",(i==0?"��":"ʮ"));
		DispLink(p);
	}
}
void CreateLink(NodeType *&p,char a[MAXE][MAXD],int n)	//���ú�巨��������
{
	int i;
	NodeType *s,*t;
	for (i=0;i<n;i++)
	{
		s=(NodeType *)malloc(sizeof(NodeType));
		strcpy(s->data,a[i]);
		if (i==0)
		{
			p=s;t=s;
		}
		else
		{
			t->next=s;t=s;
		}
	}
	t->next=NULL;
}
void DispLink(NodeType *p)	//�������
{
	while (p!=NULL)
	{
		printf("%c%c ",p->data[1],p->data[0]);
		p=p->next;
	}
	printf("\n");
}
void main()
{
	int n=10,r=10,d=2;
	int i,j,k;
	NodeType *p;
	char a[MAXE][MAXD];
	int b[]={75,23,98,44,57,12,29,64,38,82};
	for (i=0;i<n;i++)		//��b[i]ת�����ַ���
	{
		k=b[i];
		for (j=0;j<d;j++)	//����b[0]=75,ת����a[0][0]='7',a[0][1]='5'
		{
			a[i][j]=k%10+'0';
			k=k/10;
		}
		a[i][j]='\0';
	}
	CreateLink(p,a,n);
	printf("\n");
	printf("  ��ʼ�ؼ���\t");		//�����ʼ�ؼ�������
	DispLink(p);
	RadixSort(p,10,2);
	printf("  ���ս��\t");			//������ս��
	DispLink(p);
	printf("\n");
}
