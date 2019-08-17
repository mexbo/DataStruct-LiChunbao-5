//������������͹�����������㷨
#include <stdio.h>
#include <string.h>
#define N 50		//Ҷ�ӽ����
#define M 2*N-1		//���н������
typedef struct
{
	char data[5];	//���ֵ
	double weight;	//Ȩ��
	int parent;		//˫�׽��
	int lchild;		//���ӽ��
	int rchild;		//�Һ��ӽ��
} HTNode;
typedef struct
{
	char cd[N];		//��Ź�������
	int start;
} HCode;
void CreateHT(HTNode ht[],int n0)	//�����������
{	int i,k,lnode,rnode;
	double min1,min2;
	for (i=0;i<2*n0-1;i++)			//���нڵ��������ó�ֵ-1
		ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
	for (i=n0;i<=2*n0-2;i++)		//�������������n0-1���ڵ�
	{	min1=min2=32767;			//lnode��rnodeΪ��СȨ�ص������ڵ�λ��
		lnode=rnode=-1;
		for (k=0;k<=i-1;k++)		//��ht[0..i-1]����Ȩֵ��С�������ڵ�
			if (ht[k].parent==-1)	//ֻ����δ����������Ľڵ��в���
			{	if (ht[k].weight<min1)
				{	min2=min1;rnode=lnode;
					min1=ht[k].weight;lnode=k;
				}
				else if (ht[k].weight<min2)
				{	min2=ht[k].weight;rnode=k;  }
			}
		ht[i].weight=ht[lnode].weight+ht[rnode].weight;
		ht[i].lchild=lnode;ht[i].rchild=rnode;	//ht[i]��Ϊ˫�׽ڵ�
		ht[lnode].parent=i;ht[rnode].parent=i;
	}
}

void CreateHCode(HTNode ht[],HCode hcd[],int n0)	//���������������
{	int i,f,c;
	HCode hc;
	for (i=0;i<n0;i++)				//���ݹ������������������
	{	hc.start=n0;c=i;
		f=ht[i].parent;
		while (f!=-1)				//ѭ��ֱ����˫�׽ڵ㼴���������ڵ�
		{	if (ht[f].lchild==c)	//��ǰ�ڵ���˫�׽ڵ������
				hc.cd[hc.start--]='0';
			else					//��ǰ�ڵ���˫�׽ڵ���Һ���
				hc.cd[hc.start--]='1';
			c=f;f=ht[f].parent;	//�ٶ�˫�׽ڵ����ͬ���Ĳ���
		}
		hc.start++;				//startָ������������ʼ�ַ�
		hcd[i]=hc;
	}
}

void DispHCode(HTNode ht[],HCode hcd[],int n0)	//���������������
{
	int i,k;
	double sum=0,m=0;
	int j;
	printf("  �������������:\n"); //�������������
	for (i=0;i<n0;i++)
	{
		j=0;
		printf("      %s:\t",ht[i].data);
		for (k=hcd[i].start;k<=n0;k++)
		{
			printf("%c",hcd[i].cd[k]);
			j++;
		}
		m+=ht[i].weight;
		sum+=ht[i].weight*j;
		printf("\n");
	}
	printf("\n  ƽ������=%g\n",1.0*sum/m);
}
int main()
{
	int n=8,i;		//n��ʾ��ʼ�ַ����ĸ���
	char *str[]={"a","b","c","d","e","f","g","h"};
	double fnum[]={0.07,0.19,0.02,0.06,0.32,0.03,0.21,0.1};
	HTNode ht[M];
	HCode hcd[N];
	for (i=0;i<n;i++)
	{
		strcpy(ht[i].data,str[i]);
		ht[i].weight=fnum[i];
	}
	printf("\n");
	CreateHT(ht,n);
	CreateHCode(ht,hcd,n);
	DispHCode(ht,hcd,n);
	printf("\n");
	return 1;
}
 
