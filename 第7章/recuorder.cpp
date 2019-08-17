//��������ͺ���ݹ�����㷨
#include "btree.cpp"
void PreOrder(BTNode *b)  		//��������ĵݹ��㷨
{
	if (b!=NULL)  
	{
		printf("%c ",b->data);	//���ʸ����
		PreOrder(b->lchild);	//�������������
		PreOrder(b->rchild);	//�������������
	}
}
void InOrder(BTNode *b)   		//��������ĵݹ��㷨
{
	if (b!=NULL)  
	{	
		InOrder(b->lchild);		//�������������
		printf("%c ",b->data);	//���ʸ����
		InOrder(b->rchild);		//�������������
	}
}
void PostOrder(BTNode *b) 		//��������ĵݹ��㷨
{
	if (b!=NULL)  
	{
		PostOrder(b->lchild);	//�������������
		PostOrder(b->rchild);	//�������������
		printf("%c ",b->data);	//���ʸ����
	}
}
int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTree(b);printf("\n");
	printf("�����������:");PreOrder(b);printf("\n");
	printf("�����������:");InOrder(b);printf("\n");
	printf("�����������:");PostOrder(b);printf("\n");
	DestroyBTree(b);
	return 1;
}
