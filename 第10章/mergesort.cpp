//�Ե����ϵĶ�·�鲢�����㷨
#include <malloc.h>
#include "seqlist.cpp"

void Merge(RecType R[],int low,int mid,int high) 
{
	RecType *R1;
	int i=low,j=mid+1,k=0; //k��R1���±�,i��j�ֱ�Ϊ��1��2�ε��±�
	R1=(RecType *)malloc((high-low+1)*sizeof(RecType));  //��̬����ռ�
	while (i<=mid && j<=high)     	//�ڵ�1�κ͵�2�ξ�δɨ����ʱѭ��
		if (R[i].key<=R[j].key)    	//����1���еļ�¼����R1��
		{
			R1[k]=R[i];
			i++;k++; 
		}
		else                       		//����2���еļ�¼����R1��
		{
			R1[k]=R[j];
			j++;k++; 
		}
	while (i<=mid)          	       	//����1�����²��ָ��Ƶ�R1
	{ 
		R1[k]=R[i];
		i++;k++; 
	}
    while (j<=high)                	//����2�����²��ָ��Ƶ�R1
	{
		R1[k]=R[j];
		j++;k++;  
	}
    for (k=0,i=low;i<=high;k++,i++) //��R1���ƻ�R��
	    R[i]=R1[k];
} 
void MergePass(RecType R[],int length,int n)	//�������������һ�˹鲢
{
	int i;
	for (i=0;i+2*length-1<n;i=i+2*length) 	//�鲢length�����������ӱ�
		Merge(R,i,i+length-1,i+2*length-1);
	if (i+length-1<n-1)                		//���������ӱ�,���߳���С��length
		Merge(R,i,i+length-1,n-1);  		//�鲢�������ӱ�
	printf("length=%d: ",length);
	DispList(R,n);
}
void MergeSort(RecType R[],int n)			//�Ե����ϵĶ�·�鲢�㷨
{
	int length;
	for (length=1;length<n;length=2*length)//����log2n�˹鲢
		MergePass(R,length,n);
}
int main()
{
	int n=10;
	RecType R[MAXL];
	KeyType a[]={9,8,7,6,5,4,3,2,1,0};
	CreateList(R,a,n);
	printf("   ����ǰ:"); DispList(R,n);
	MergeSort(R,n);
	printf("   �����:"); DispList(R,n);
	return 1;
}


