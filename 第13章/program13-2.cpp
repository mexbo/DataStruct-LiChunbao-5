//����13.2���ĳ���:���캯����ʹ��
#include <iostream>
using namespace std;
class Sample2
{
	int value;
public:
	Sample2() { value=0; }			//���캯��
	Sample2(int v) { value=v; }		//���ع��캯��
	int getvalue() { return value; }
	void setvalue(int v) { value=v; }
};
int main()
{
	Sample2 a[10]={0,1,2,3,4,5,6,7,8,9},b[10];
	cout << "���a:" << endl;
	for (int i=0;i<10;i++)
	{
		cout << "a[" << i << "]=" << a[i].getvalue() << " ";
		if ((i+1)%5==0)				//ÿ���5��Ԫ�ػ�һ��
			cout << endl;
	}
	cout << "���b:" << endl;
	for (int i=0;i<10;i++)
	{	
		cout << "b[" << i << "]=" << b[i].getvalue() << " ";
		if ((i+1)%5==0)				//ÿ���5��Ԫ�ػ�һ��
			cout << endl;
	}
	return 1;
}
