//����7.13�����㷨�����������ָ���ڵ�Ĳ��
#include "btree.cpp"
int Level(BTNode *b,ElemType x,int h)	//h�ó�ֵ1
{	int l;
	if (b==NULL)
		return(0);
	else if (b->data==x)
		return(h);
	else
	{	l=Level(b->lchild,x,h+1);	//���������в���
		if (l!=0)
			return(l);
		else						//����������δ�ҵ�,�����������в���
			return(Level(b->rchild,x,h+1));
	}
}
int main()
{	BTNode *b;
	int h;
	ElemType x;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTree(b);printf("\n");
	printf("�ڵ�ֵ:");
	scanf("%c",&x);
	h=Level(b,x,1);
	if (h==0)
		printf("b�в�����%c�ڵ�\n",x);
	else
		printf("��b��%c�ڵ�Ĳ��Ϊ%d\n",x,h);
	DestroyBTree(b);
	return 1;
}
