//�Ľ���ð�������㷨
#include "seqlist.cpp"

void BubbleSort1(RecType R[],int n)
{	int i,j;
	bool exchange;
	RecType tmp;
	for (i=0;i<n-1;i++) 
	{	exchange=false;					//һ��ǰexchange��Ϊ��
		for (j=n-1;j>i;j--)				//��λR[i],ѭ��n-i-1��
			if (R[j].key<R[j-1].key)	//��������Ԫ�ط���ʱ
			{	tmp=R[j];				//��������Ԫ�ؽ���
				R[j]=R[j-1];
				R[j-1]=tmp;
				exchange=true;			//һ���н�����exchange��Ϊ��
			}
		printf("  i=%d: ",i);
		DispList(R,n);
		if (!exchange)					//����û�з�����������;�����㷨
			return;
	}
}

int main()
{
	int n=10;
	RecType R[MAXL];
	KeyType a[]={0,1,7,2,5,4,3,6,8,9};
	CreateList(R,a,n);
	printf("����ǰ:"); DispList(R,n);
	BubbleSort1(R,n);  
	printf("�����:"); DispList(R,n);
	return 1;
}


