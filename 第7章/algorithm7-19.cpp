//����7.19�����㷨������������˳��洢�ṹת���ɶ������洢�ṹ
#include "btree.cpp"
#define MaxSize 30
typedef char Elemtype;
typedef ElemType SqBTree[MaxSize];
BTNode *trans(SqBTree a,int i)
{
	BTNode *b;
	if (i>MaxSize)
		return(NULL);
	if (a[i]=='#')	return(NULL);			//���ڵ㲻����ʱ����NULL
	b=(BTNode *)malloc(sizeof(BTNode));	//�������ڵ�
	b->data=a[i];
	b->lchild=trans(a,2*i);					//�ݹ鴴��������
	b->rchild=trans(a,2*i+1);				//�ݹ鴴��������
	return(b);								//���ظ��ڵ�
}
int main()
{
	BTNode *b;
	SqBTree a;
	ElemType s[]="0ABCD#EF##G####################";
	b=trans(s,1);
	printf("b:");DispBTree(b);printf("\n");
	DestroyBTree(b);
	return 1;
}
