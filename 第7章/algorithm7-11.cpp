//����7.11�����㷨������һ�ø��������������нڵ����
#include "btree.cpp"
int Nodes(BTNode *b)
{	int num1,num2;
	if (b==NULL) 
		return 0;
	else
		return Nodes(b->lchild)+Nodes(b->rchild)+1;
}

int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTree(b);printf("\n");
	printf("�ڵ����:%d\n",Nodes(b));
	DestroyBTree(b);
	return 1;
}
