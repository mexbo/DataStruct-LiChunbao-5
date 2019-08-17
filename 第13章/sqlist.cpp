//˳�����ģ��
#include <iostream>
using namespace std;
template <typename T>
class SqList					//˳�����
{	T *pelem;
   	int length;
public:
	SqList(int n)				//���캯��,���ڳ�ʼ��������
	{
		pelem=new T[n];
		length=0; 
	}
	~SqList()					//��������,�����ͷŷ���Ŀռ�
	{
		delete pelem;
	}
	bool ListEmpty()			//�ж����Ա��Ƿ�Ϊ�ձ�
	{
		return(length==0); 
	}
	int ListLength()			//�����Ա�ĳ���
	{
		return(length);
	}
	void DispList()			//������Ա�
	{
		int i;
		if (ListEmpty()) return;
		cout << "˳���:";
		for (i=0;i<length;i++)
			cout << pelem[i] << " ";
		cout << endl;
	}
	bool GetElem(int i,T &e)	//�����Ա���ĳ������Ԫ��ֵ
	{
		if (i<1 || i>length)
			return false;
		e=pelem[i-1];
		return true;
	}
	int LoacteElem(T e)		//��Ԫ��ֵ����
	{
		int i=0;
		while (i<length && pelem[i]!=e) i++;
		if (i>=length)
			return 0;
		else
			return i+1;
	}
	bool ListInsert(int i,T e)	//��������Ԫ��
	{	int j;
		if (i<1 || i>length+1)
			return false;
		i--;						//��˳���λ��ת��Ϊpelem�±�
		for (j=length;j>i;j--)		//��pelem[i]������Ԫ�غ���һ��λ��
			pelem[j]=pelem[j-1];
		pelem[i]=e;
		length++;					//˳�������1
		return true;
	}
	bool ListDelete(int i,T &e)//ɾ������Ԫ��
	{	int j;
		if (i<1 || i>length) return false;
		i--;						//��˳���λ��ת��Ϊpelem�±�
		e=pelem[i];
		for (j=i;j<length-1;j++)
			pelem[j]=pelem[j+1];
		length--;
		return true;
	}
};
int main()
{
	char e;int i;
	SqList<char> s(10);			//����һ���ַ�˳������s
	s.ListInsert(1,'a');
	s.ListInsert(2,'b');
	s.ListInsert(3,'c');
	s.ListInsert(4,'d');
	s.DispList();
	s.GetElem(2,e);
	cout << "��2���ڵ�ֵ:" << e << endl;
	i=s.LoacteElem('d');
	cout << "����ֵΪd�Ľڵ����Ϊ" << i << endl;
	cout << "ɾ����2���ڵ�" << endl;
	s.ListDelete(2,e);
	s.DispList();
	cout << "ɾ����3���ڵ�" << endl;
	s.ListDelete(3,e);
	s.DispList();
	cout << "����e��Ϊ��1���ڵ�" << endl;
	s.ListInsert(1,'e');
	s.DispList();
	cout << "����f��Ϊ��3���ڵ�" << endl;
	s.ListInsert(3,'f');
	s.DispList();
	return 1;
}
