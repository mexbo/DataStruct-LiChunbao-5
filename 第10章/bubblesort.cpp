//ð�������㷨
#include "seqlist.cpp"

void BubbleSort(RecType R[],int n)
{
	int i,j,k;
	RecType tmp;
	for (i=0;i<n-1;i++) 
	{
		for (j=n-1;j>i;j--)	//�Ƚ�,�ҳ�������С�ؼ��ֵļ�¼
			if (R[j].key<R[j-1].key)   
			{
				tmp=R[j];  //R[j]��R[j-1]���н���,����С�ؼ��ּ�¼ǰ��
				R[j]=R[j-1];
				R[j-1]=tmp;
			}
		printf("  i=%d: ",i);
		DispList(R,n);
	}
} 
int main()
{
	int n=10;
	RecType R[MAXL];
	KeyType a[]={9,8,7,6,5,4,3,2,1,0};
	CreateList(R,a,n);
	printf("����ǰ:"); DispList(R,n);
	BubbleSort(R,n); 
	printf("�����:"); DispList(R,n);
	return 1;
}


