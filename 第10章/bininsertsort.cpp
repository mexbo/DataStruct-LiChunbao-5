//�۰���������㷨
#include "seqlist.cpp"

void BinInsertSort(RecType R[],int n)
{	int i, j, low, high, mid;
	RecType tmp;
	for (i=1;i<n;i++) 
	{
		if (R[i].key<R[i-1].key)		//����ʱ 
		{
			tmp=R[i];		  			//��R[i]���浽tmp��
	     	low=0;  high=i-1;
			while (low<=high)	  		//��R[low..high]�в��Ҳ����λ��
			{
				mid=(low+high)/2;		//ȡ�м�λ��
				if (tmp.key<R[mid].key)
					high=mid-1;			//������������
				else 
					low=mid+1;			//��������Ұ���
			}                          	//��λ��high
			for (j=i-1;j>=high+1;j--)	//���н���Ԫ�غ���
				R[j+1]=R[j];
			R[high+1]=tmp;				//����tmp 
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
	BinInsertSort(R,n);
	printf("�����:"); DispList(R,n);
	return 1;
}


