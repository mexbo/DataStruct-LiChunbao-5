//ֱ�Ӳ��������㷨
#include "seqlist.cpp"
void InsertSort(RecType R[],int n) //��R[0..n-1]�������������ֱ�Ӳ�������
{	int i, j; RecType tmp;
	for (i=1;i<n;i++) 
	{
		if (R[i].key<R[i-1].key)	//����ʱ 
		{	
			tmp=R[i];
			j=i-1; 
			do					//��R[i]�Ĳ���λ�� 
			{
				R[j+1]=R[j];   	//���ؼ��ִ���R[i].key�ļ�¼����
				j--;
			}  while  (j>=0 && R[j].key>tmp.key);
			R[j+1]=tmp;      		//��j+1������R[i]
		}
		printf("  i=%d: ",i); DispList(R,n);
	}
}

int main()
{
	int n=10;
	RecType R[MAXL];
	KeyType a[]={9,8,7,6,5,4,3,2,1,0};
	CreateList(R,a,n);
	printf("����ǰ:"); DispList(R,n);
	InsertSort(R,n);
	printf("�����:"); DispList(R,n);
	return 1;
}


