//���������㷨
#include "seqlist.cpp"
int count=0;
int partition(RecType R[],int s,int t)	//һ�˻���
{
	int i=s,j=t;
	RecType tmp=R[i];			//��R[i]Ϊ��׼
	while (i<j)  				//�����˽������м�ɨ��,ֱ��i=jΪֹ
	{	while (j>i && R[j].key>=tmp.key)
			j--;				//��������ɨ��,��һ��С��tmp.key��R[j]
		R[i]=R[j];				//�ҵ�������R[j],����R[i]��
		while (i<j && R[i].key<=tmp.key)
			i++;				//��������ɨ��,��һ������tmp.key��R[i]
		R[j]=R[i];				//�ҵ�������R[i],����R[j]��
	}
	R[i]=tmp;
	return i;
}
void QuickSort(RecType R[],int s,int t) //��R[s..t]��Ԫ�ؽ��п�������
{	int i;
	RecType tmp;
	if (s<t) 					//���������ٴ�������Ԫ�ص����
	{	count++;
		i=partition(R,s,t);
		DispList(R,10);			//������
		QuickSort(R,s,i-1);		//��������ݹ�����
		QuickSort(R,i+1,t);		//��������ݹ�����
	}
}
/*
int main()
{
	int i,n=10;
	RecType R[MAXL];
	KeyType a[]={15,18,29,12,35,32,27,23,10,20};
	CreateList(R,a,n);
	printf("����ǰ:"); DispList(R,n);
	QuickSort(R,0,n-1);
	printf("�����:"); DispList(R,n);
	return 1;
}
*/

int main()
{
	int i,n=10;
	RecType R[MAXL];
	KeyType a[]={6,8,7,9,0,1,3,2,4,5};
	CreateList(R,a,n);
	printf("����ǰ:"); DispList(R,n);
	QuickSort(R,0,n-1);
	printf("�����:"); DispList(R,n);
	printf("count=%d\n",count);
	return 1;
}



