//����13.4���ĳ���:ģ�����ʹ��
#include <iostream>
using namespace std;
template <typename T>
class Array
{	int size;
	T *data;				//TΪ���Ͳ���
public:
	Array(int);				//���캯��
	~Array();				//��������
	void setvalue();		//��������Ԫ��
	void dispvalue();		//�����������Ԫ��
};
template <typename T>
Array<T>::Array(int n)		//���캯��
{	size=n;
	data=new T[n];			//Ϊ��̬��������ڴ�ռ�
}
template <typename T>
Array<T>::~Array()			//��������
{	delete [] data; }
template <typename T>
void Array<T>::setvalue()
{	cout << "(����" << size << "������)" << endl;
	for (int i=0;i<size;i++)
	{	cout << "  ��" << i+1 << "������:";
		cin >> data[i];
	}
}
template <typename T>
void Array<T>::dispvalue()
{	for (int i=0;i<size;i++)
		cout << data[i] << " ";
	cout << endl;
}
int main()
{	Array<char> ac(2);	//Array<char>Ϊģ����,ac(2)����ģ����Ķ���
	cout << "����һ���ַ�����";
	ac.setvalue();
	cout << "  �����������:";
	ac.dispvalue();
	Array<int> ad(3);	//Array<int>Ϊģ����,ad(3)����ģ����Ķ���
	cout << "����һ����������:";
	ad.setvalue();
	cout << "  �����������:";
	ad.dispvalue();
	return 1;
}
