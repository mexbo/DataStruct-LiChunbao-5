//�������������㷨
#include <stdio.h>
#include <malloc.h>
#include "glnode.h"
int GLLength(GLNode *g)			//������g�ĳ���
{
	int n=0;
	GLNode *g1;
	g1=g->val.sublist;			//gָ������ĵ�һ��Ԫ��
	while (g1!=NULL)
	{	
		n++;					//�ۼ�Ԫ�ظ���
		g1=g1->link;
	}
	return n;
}
int GLDepth(GLNode *g)			//������g�����
{
	GLNode *g1;
	int maxd=0,dep;
	if (g->tag==0)				//Ϊԭ��ʱ����0
		return 0;
	g1=g->val.sublist;			//g1ָ���һ��Ԫ��
	if (g1==NULL)				//Ϊ�ձ�ʱ����1
		return 1;
	while (g1!=NULL)			//�������е�ÿһ��Ԫ��
	{	
		if (g1->tag==1)			//Ԫ��Ϊ�ӱ�����
		{
			dep=GLDepth(g1);	//�ݹ��������ӱ�����
			if (dep>maxd)		//maxdΪͬһ����������ӱ�����ȵ����ֵ
				maxd=dep;
		}
		g1=g1->link;			//ʹg1ָ����һ��Ԫ��
	}
	return(maxd+1);				//���ر�����
}
GLNode *CreateGL(char *&s)				//���������ű�ʾ����ʾs�Ĺ������ʽ�洢�ṹ
{
	GLNode *g;
	char ch=*s++;						//ȡһ���ַ�
	if (ch!='\0')						//��δ�����ж�
	{
		g=(GLNode *)malloc(sizeof(GLNode));//����һ���½��
		if (ch=='(')					//��ǰ�ַ�Ϊ������ʱ
		{
			g->tag=1;					//�½����Ϊ��ͷ���
			g->val.sublist=CreateGL(s); //�ݹ鹹���ӱ�������ͷ���
		}
		else if (ch==')') 
			g=NULL;           			//����')'�ַ�,g��Ϊ��
		else if (ch=='#')				//����'#'�ַ�����ʾΪ�ձ�
			g=NULL;
		else							//Ϊԭ���ַ�
		{
			g->tag=0;					//�½����Ϊԭ�ӽ��
			g->val.data=ch;
		}
	}
	else								//������,g��Ϊ��
		g=NULL;
	ch=*s++;                           	//ȡ��һ���ַ�
	if (g!=NULL)                      	//��δ���������������ֵݽ��
		if (ch==',')                  	//��ǰ�ַ�Ϊ','
			g->link=CreateGL(s);   		//�ݹ鹹���ֵݽ��
		else                            //û���ֵ���,���ֵ�ָ����ΪNULL
			g->link=NULL;
	return g;                     		//���ع����g
}
void DestroyGL(GLNode *&g)		//���ٹ����
{
	GLNode *g1,*g2;
	g1=g->val.sublist;			//g1ָ������ĵ�һ��Ԫ��
	while (g1!=NULL)			//��������Ԫ��
	{
		if (g1->tag==0)			//��Ϊԭ�ӽ��
		{	g2=g1->link;		//g2��ʱ�����ֵܽ��
			free(g1);			//�ͷ�g1��ָԭ�ӽ��
			g1=g2;				//g1ָ�����ֵܽ��
		}
		else					//��Ϊ�ӱ�
		{	g2=g1->link;		//g2��ʱ�����ֵܽ��
			DestroyGL(g1);		//�ݹ��ͷ�g1��ָ�ӱ�Ŀռ�
			g1=g2;				//g1ָ�����ֵܽ��
		}
	}
	free(g);					//�ͷ�ͷ���ռ�
}

void DispGL(GLNode *g)					//��������g
{
	if (g!=NULL)                 		//��Ϊ���ж�
	{									//�ȴ���g��Ԫ��
		if (g->tag==0)               	//g��Ԫ��Ϊԭ��ʱ
			printf("%c", g->val.data);  //���ԭ��ֵ
		else							//g��Ԫ��Ϊ�ӱ�ʱ
		{
			printf("(");                //���'('
			if (g->val.sublist==NULL)  	//Ϊ�ձ�ʱ
				printf("#");
			else						//Ϊ�ǿ��ӱ�ʱ
				DispGL(g->val.sublist); //�ݹ�����ӱ�
			printf(")");               	//���')'
		}
		if (g->link!=NULL) 
		{
			printf(",");
			DispGL(g->link);            //�ݹ���������������
		}
	}
}
