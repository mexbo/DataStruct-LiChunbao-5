//�������㷨
#include "seqlist.cpp"

void sift(RecType R[],int low,int high)
{
	int i=low,j=2*i;     					//R[j]��R[i]������
	RecType temp=R[i];
	while (j<=high) 
	{
		if (j<high && R[j].key<R[j+1].key) 	//���Һ��ӽϴ�,��jָ���Һ���
			j++;    						//��Ϊ2i+1
		if (temp.key<R[j].key) 
		{
			R[i]=R[j];              		//��R[j]������˫�׽��λ����
			i=j;                    		//�޸�i��jֵ,�Ա��������ɸѡ
			j=2*i;
		}
		else break;                 		//ɸѡ����
	}
	R[i]=temp;                      		//��ɸѡ����ֵ��������λ��
}

void HeapSort(RecType R[],int n)
{
	int i;
	RecType tmp;
	for (i=n/2;i>=1;i--)	//ѭ��������ʼ��,����sift�㷨 n/2 ��
		sift(R,i,n); 
	printf("��ʼ��:"); DispList1(R,n);
	for (i=n;i>=2;i--)		//����n-1�����������,ÿһ�˶������Ԫ�ظ�����1
	{	tmp=R[1];			//�����һ��Ԫ�����R[1]����
		R[1]=R[i];
		R[i]=tmp;
		printf("��%d��: ",n-i+1); DispList1(R,n);
		sift(R,1,i-1);		//��R[1..i-1]����ɸѡ,�õ�i-1���ڵ�Ķ�
		printf("ɸѡΪ:"); DispList1(R,n);
	}
}


int main()
{
	int n=10;
	RecType R[MAXL];
	KeyType a[]={15,18,29,12,35,32,27,23,10,20};
	CreateList1(R,a,n);
	printf("����ǰ:"); DispList1(R,n);
	HeapSort(R,n);
	printf("�����:"); DispList1(R,n);
	return 1;
}

/*
int main()
{
	int n=10;
	RecType R[MAXL];
	KeyType a[]={0,9,8,7,6,5,4,3,2,1,0};
	CreateList1(R,a,n);
	printf("����ǰ:"); DispList1(R,n);
	HeapSort(R,n);
	printf("�����:"); DispList1(R,n);
	return 1;
}
*/

