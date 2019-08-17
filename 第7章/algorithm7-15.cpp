//����7.15�����㷨���ж����ö������Ƿ�����
#include "btree.cpp"
bool Like(BTNode *b1,BTNode *b2)
//b1��b2���ö���������ʱ����true�����򷵻�false
{
    bool like1,like2;
    if (b1==NULL && b2==NULL) 
		return true;
    else if (b1==NULL || b2==NULL) 
		return false;
    else
    {
		like1=Like(b1->lchild,b2->lchild);
		like2=Like(b1->rchild,b2->rchild);
		return (like1 && like2);		//����like1��like2����
    }
}
int main()
{
	bool l;
	BTNode *b1,*b2;
	CreateBTree(b1,"A(B(D(,G)),C(E,F))");
	printf("b1:");DispBTree(b1);printf("\n");
	CreateBTree(b2,"a(b(d(,g)),c(e,f))");
	printf("b2:");DispBTree(b2);printf("\n");
	l=Like(b1,b2);
	if (l==true)
		printf("b1��b2����\n");
	else
		printf("b1��b2������\n");
	DestroyBTree(b1);
	DestroyBTree(b2);
	return 1;
}
