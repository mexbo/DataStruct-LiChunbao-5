//����13.3���ĳ���:����������ʹ��
#include <iostream>
using namespace std;
class Sample3
{
    int x,y;
public:
    Sample3(int x1,int y1)	//���캯��
    {	x=x1;y=y1;  }
    ~Sample3()				//��������
    {	cout << "������������." << endl; }
    void dispoint()
    {	cout << "(" << x << "," << y << ")" << endl; }
};
int main()
{
	Sample3 a(12,6),*p=new Sample3(5,12);	//����ָ��ָ�򴴽�����������
	cout << "First point=>";
	a.dispoint();
	cout << "Second point=>";
	p->dispoint();
	//delete p;
	return 1;
}
