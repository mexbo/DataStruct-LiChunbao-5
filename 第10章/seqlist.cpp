//˳�����������㷨
#include <stdio.h>
#define MAXL 100		//��󳤶�
typedef int KeyType;	//����ؼ�������Ϊint
typedef char InfoType;

typedef struct
{	KeyType key;		//�ؼ�����
	InfoType data;		//�������������ΪInfoType
} RecType;				//����Ԫ�ص�����

void swap(RecType x,RecType y)	//x��y����
{
	RecType tmp=x;
	x=y; y=tmp;
}

void CreateList(RecType R[],KeyType keys[],int n)	//����˳���
{
	for (int i=0;i<n;i++)			//R[0..n-1]��������¼
		R[i].key=keys[i];
}
void DispList(RecType R[],int n)	//���˳���
{
	for (int i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
}
//----����������Զ�����ĳ���
void CreateList1(RecType R[],KeyType keys[],int n)	//����˳���
{
	for (int i=1;i<=n;i++)			//R[1..n]��������¼
		R[i].key=keys[i-1];
}
void DispList1(RecType R[],int n)	//���˳���
{
	for (int i=1;i<=n;i++)
		printf("%d ",R[i].key);
	printf("\n");
}