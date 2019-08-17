//���ŵ�ַ������Ĺ�ϣ��������㷨
#include <stdio.h>
#define MaxSize 100			//��������ϣ����
#define NULLKEY -1			//����չؼ���ֵ
#define DELKEY -2			//���屻ɾ�ؼ���ֵ
typedef int KeyType;		//�ؼ�������
typedef struct
{
	KeyType key;			//�ؼ�����
	int count;				//̽�������
} HashTable;				//��ϣ������
void InsertHT(HashTable ha[],int &n,int m,int p,KeyType k)  //���ؼ���k���뵽��ϣ����
{
	int i,adr;
	adr=k % p;					//�����ϣ����ֵ
	if (ha[adr].key==NULLKEY || ha[adr].key==DELKEY)//k����ֱ�ӷ��ڹ�ϣ����
	{
		ha[adr].key=k;
		ha[adr].count=1;
	}
	else						//������ͻʱ��������̽�ⷨ�����ͻ
	{
		i=1;					//i��¼k������ͻ�Ĵ���
		do 
		{
			adr=(adr+1) % m;	//����̽��
			i++;
		} while (ha[adr].key!=NULLKEY && ha[adr].key!=DELKEY);
		ha[adr].key=k;			//��adr������k
		ha[adr].count=i;		//����̽�����
	}
	n++;						//�ܹؼ��ָ�����1
	
}
void CreateHT(HashTable ha[],int &n,int m,int p,KeyType keys[],int n1)  //������ϣ��
{
	for (int i=0;i<m;i++)				//��ϣ���ÿյĳ�ֵ
    {
        ha[i].key=NULLKEY;
	    ha[i].count=0;
    }
	n=0;
	for (i=0;i<n1;i++)
		InsertHT(ha,n,m,p,keys[i]);	//����n���ؼ���
}
void SearchHT(HashTable ha[],int m,int p,KeyType k)  //�ڹ�ϣ���в��ҹؼ���k
{
	int i=1,adr;
	adr=k % p;					//�����ϣ����ֵ
	while (ha[adr].key!=NULLKEY && ha[adr].key!=k)
	{
		i++;					//�ۼƹؼ��ֱȽϴ���
		adr=(adr+1) % m;		//����̽��
	}
	if (ha[adr].key==k)			//���ҳɹ�
		printf("�ɹ����ؼ���%d���Ƚ�%d��\n",k,i);
	else						//����ʧ��
		printf("ʧ�ܣ��ؼ���%d���Ƚ�%d��\n",k,i);
}
bool DeleteHT(HashTable ha[],int &n,int m,int p,KeyType k)	//ɾ����ϣ���йؼ���k
{
	int adr;
	adr=k % p;					//�����ϣ����ֵ
	while (ha[adr].key!=NULLKEY && ha[adr].key!=k)
		adr=(adr+1) % m;		//����̽��
	if (ha[adr].key==k)			//���ҳɹ�
	{
		ha[adr].key=DELKEY;		//ɾ���ؼ���k
		return true;
	}
	else						//����ʧ��
		return false;			//���ؼ�
}
void ASL(HashTable ha[],int n,int m,int p)	//��ƽ�����ҳ���
{
	int i,j;
	int succ=0,unsucc=0,s;
	for (i=0;i<m;i++)
		if (ha[i].key!=NULLKEY)
			succ+=ha[i].count;		//�ۼƳɹ�ʱ�ܹؼ��ֱȽϴ���
	printf(" �ɹ������ASL(%d)=%g\n",n,succ*1.0/n);
	for (i=0;i<p;i++)
	{
		s=1; j=i;
		while (ha[j].key!=NULLKEY)
		{
			s++;
			j=(j+1) % m;
		}
		unsucc+=s;
	}
	printf(" ���ɹ������ASL(%d)=%g\n",n,unsucc*1.0/p);
}
void DispHT(HashTable ha[],int n,int m,int p)  //�����ϣ��
{
	int i,j;
	int succ=0,unsucc=0,s;
	printf("��ϣ��:\n");
	printf(" ��ϣ���ַ:\t");
	for (i=0;i<m;i++) 
		printf(" %3d",i);
	printf(" \n");
    printf(" ��ϣ��ؼ���:\t");
	for (i=0;i<m;i++) 
		if (ha[i].key==NULLKEY)
			printf("    ");			//���3���ո�
		else
			printf(" %3d",ha[i].key);
	printf(" \n");
	printf(" ̽�����:\t");
	for (i=0;i<m;i++)
		if (ha[i].key==NULLKEY)
			printf("    ");			//���3���ո�
		else
			printf(" %3d",ha[i].count);
	printf(" \n");
	ASL(ha,n,m,p);
}
int main()
{
	int keys[]={16,74,60,43,54,90,46,31,29,88,77};
	int n,m=13,p=13,k;
	HashTable ha[MaxSize];
	printf("(1)������ϣ��\n"); CreateHT(ha,n,m,p,keys,11);
	printf("(2)��ʾ��ϣ��:\n"); DispHT(ha,n,m,p);
	k=29;
	printf("(3)����"); SearchHT(ha,m,p,k);
	k=31;
	printf("(4)ɾ�����ؼ���%d\n",k);
	DeleteHT(ha,n,m,p,k);
	printf("(5)��ʾ��ϣ��:\n"); DispHT(ha,n,m,p);
	printf("(6)����"); SearchHT(ha,m,p,k);
	printf("(7)���룺�ؼ���%d\n",k);
	InsertHT(ha,n,m,p,k);
	printf("(8)��ʾ��ϣ��:\n"); DispHT(ha,n,m,p);
	printf("\n");
	return 1;
}
