//����5.4�����㷨���ͷ�һ������ͷ���ĵ�����L�����н�㡣
#include "linklist.cpp"
void release(LinkNode *&L)
{
	if (L!=NULL)
	{
		release(L->next);
		free(L);
	}
}
int main()
{
	LinkNode *h;
	int a[]={1,2,3,4};
	InitList(h);		//hΪ��ͷ���ĵ�����
	ListInsert(h,1,1);
	ListInsert(h,2,2);
	ListInsert(h,3,3);
	ListInsert(h,4,4);
	printf("������:");
	DispList(h);
	printf("�ͷŵ�����\n");
	release(h->next);
	free(h);			//�ͷ�ͷ���
	return 1;
}
