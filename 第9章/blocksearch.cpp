//�ֿ�����㷨
#include "seqlist.cpp"
#define MAXI 20			//���������󳤶�
typedef struct 
{
	KeyType key;	//KeyTypeΪ�ؼ��ֵ�����
	int link;		//ָ���Ӧ�����ʼ�±�
} IdxType;			//������Ԫ������

int IdxSearch(IdxType I[],int b,RecType R[],int n,KeyType k) //�ֿ����
{	
	int s=(n+b-1)/b;			//sΪÿ���Ԫ�ظ�����ӦΪn/b������ȡ��
	int low=0,high=b-1,mid,i;
	while (low<=high)			//���������н����۰���ң��ҵ���λ��Ϊhigh+1
	{	mid=(low+high)/2;
		if (I[mid].key>=k)
			high=mid-1;
		else 
			low=mid+1;
	}
	//Ӧ���������high+1���У����������ݱ��н���˳�����
	i=I[high+1].link;
	while (i<=I[high+1].link+s-1 && R[i].key!=k)
		i++;
	if (i<=I[high+1].link+s-1)
		return i+1;			//���ҳɹ������ظ�Ԫ�ص��߼����
	else
		return 0;			//����ʧ�ܣ�����0
}


int main()
{
	int n=25,b=5,j;
	RecType R[MAXL];
	IdxType I[MAXI]={{14,0},{34,5},{66,10},{85,15},{100,20}};
	KeyType a[]={8,14,6,9,10,22,34,18,19,31,40,38,54,66,46,71,78,68,80,85,100,94,88,96,87};
	KeyType k=85;
	CreateList(R,a,n);
	printf("���ұ�"); DispList(R,n);
	j=IdxSearch(I,b,R,n,k);
	if (j!=-1)
		printf("R[%d]=%d\n",j,k);
	else
		printf("δ�ҵ�%d\n",k);
	return 1;
}
