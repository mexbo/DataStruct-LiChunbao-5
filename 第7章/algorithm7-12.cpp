//����7.12�����㷨�����һ�ø���������������Ҷ�ӽڵ�
#include "btree.cpp"
void DispLeaf(BTNode *b)
{
	if (b!=NULL) 
	{
		if (b->lchild==NULL && b->rchild==NULL) 
			printf("%c ",b->data);	//����Ҷ�ӽڵ�
		DispLeaf(b->lchild);		//����������е�Ҷ�ӽڵ�
		DispLeaf(b->rchild);		//����������е�Ҷ�ӽڵ�
	}
}
void DispLeaf1(BTNode *b)
{
	if (b!=NULL) 
	{
		if (b->lchild==NULL && b->rchild==NULL) 
			printf("%c ",b->data);	//����Ҷ�ӽڵ�
		DispLeaf1(b->rchild);		//����������е�Ҷ�ӽڵ�
		DispLeaf1(b->lchild);		//����������е�Ҷ�ӽڵ�
	}
}
int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTree(b);printf("\n");
	printf("�������������Ҷ�ӽڵ�:");DispLeaf(b);printf("\n");
	printf("���ҵ����������Ҷ�ӽڵ�:");DispLeaf1(b);printf("\n");
	DestroyBTree(b);
	return 1;
}
