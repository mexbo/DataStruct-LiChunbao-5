//����7.14�����㷨�����������ָ����εĽڵ����
#include "btree.cpp"
void Lnodenum(BTNode *b,int h,int k,int &n)
{	if (b==NULL)			//����ֱ�ӷ���
		return;
	else					//����ǿ���
	{	if (h==k) n++;		//��ǰ���ʵĽڵ��ڵ�k��ʱ��n��1
		else if (h<k)		//����ǰ�ڵ���С��k���ݹ鴦����������
		{	Lnodenum(b->lchild,h+1,k,n);
			Lnodenum(b->rchild,h+1,k,n);
		}
	}
}
int main()
{	BTNode *b;
	int k,n=0;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTree(b);printf("\n");
	printf("���:");
	scanf("%d",&k);
	Lnodenum(b,1,k,n);
	if (n==0)
		printf("b�в����ڵ�%d��\n",k);
	else
		printf("��b�е�%d����%d���ڵ�\n",k,n);
	DestroyBTree(b);
	return 1;
}
