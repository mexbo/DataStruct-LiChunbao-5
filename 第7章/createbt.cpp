//������������㷨
#include "btree.cpp"
BTNode *CreateBT1(char *pre,char *in,int n)
/*pre�����������,in�����������,nΪ�������ڵ����,
���㷨ִ�к󷵻ع���Ķ������ĸ��ڵ�ָ��*/
{
	BTNode *s;
	char *p;
	int k;
	if (n<=0) return NULL;
	s=(BTNode *)malloc(sizeof(BTNode));		//�����������ڵ�s
	s->data=*pre;
	for (p=in;p<in+n;p++)					//�������������ҵ���*ppos��λ��k
		if (*p==*pre)						//preָ����ڵ�
			break;							//��in���ҵ����˳�ѭ��
	k=p-in;									//ȷ�����ڵ���in�е�λ��
	s->lchild=CreateBT1(pre+1,in,k);		//�ݹ鹹��������
	s->rchild=CreateBT1(pre+k+1,p+1,n-k-1); //�ݹ鹹��������
	return s;
}
BTNode *CreateBT2(char *post,char *in,int n)
/*post��ź�������,in�����������,nΪ�������ڵ����,
���㷨ִ�к󷵻ع���Ķ������ĸ��ڵ�ָ��*/
{
	BTNode *s;
	char r,*p;
	int k;
	if (n<=0) return NULL;
	r=*(post+n-1);							//���ڵ�ֵ
	s=(BTNode *)malloc(sizeof(BTNode));		//�����������ڵ�s
	s->data=r;
	for (p=in;p<in+n;p++)					//��in�в��Ҹ��ڵ�
		if (*p==r)
			break;
	k=p-in;									//kΪ���ڵ���in�е��±�
	s->lchild=CreateBT2(post,in,k);			//�ݹ鹹��������
	s->rchild=CreateBT2(post+k,p+1,n-k-1);	//�ݹ鹹��������
	return s;
}
int main()
{
	ElemType pre[]="ABDGCEF",in[]="DGBAECF",post[]="GDBEFCA";
	BTNode *b1,*b2;
	b1=CreateBT1(pre,in,7);
	printf("b1:");DispBTree(b1);printf("\n");
	b2=CreateBT2(post,in,7);
	printf("b2:");DispBTree(b2);printf("\n");
	DestroyBTree(b1);
	DestroyBTree(b2);
	return 1;
}
