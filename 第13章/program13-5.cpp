//����13.5���ĳ���:����������ʹ��
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> v(3);						//�����ʼ����Ϊ3����������
	v[0]=5;									//�±�0������Ԫ��5
	v[1]=2;									//�±�1������Ԫ��2
	v.push_back(7);							//��β������Ԫ��7
	vector<int>::iterator first=v.begin();	//��firstָ��ͷԪ��
	vector<int>::iterator last=v.end();		//��lastָ��β��Ԫ��
	while (first!=last)						//ѭ���������Ԫ��
		cout << *first++ << " ";
	cout << endl;
	return 1;
}

