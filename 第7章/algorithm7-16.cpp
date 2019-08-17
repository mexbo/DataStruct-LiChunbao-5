//����7.16�����㷨�������������ֵΪx�Ľڵ���������ȡ�
#include "btree.cpp"
bool ancestor(BTNode *b,ElemType x)
{
	if (b==NULL)
		return false;
	else if (b->lchild!=NULL && b->lchild->data==x || b->rchild!=NULL && b->rchild->data==x)
	{
		printf("%c ",b->data);
		return true;
	}
	else if (ancestor(b->lchild,x) || ancestor(b->rchild,x))
	{
		printf("%c ",b->data);
		return true;
	}
	else
		return false;
}
int main()
{
	BTNode *b;
	ElemType x='G';
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTree(b);printf("\n");
	printf("���%c����������:",x);
	ancestor(b,x);printf("\n");
	DestroyBTree(b);
	return 1;
}
