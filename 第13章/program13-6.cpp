//����13.6���ĳ���:˫�˶���������ʹ��
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
void disp(deque<int> &dq);
int main()
{
	deque<int> dq;			//����һ��˫�˶���dq
	dq.push_front(1);			//��ͷ����1
	dq.push_back(2);			//��β����2
	dq.push_front(3);			//��ͷ����3
	dq.push_back(4);			//��β����4
	disp(dq);
	dq.pop_front();			//ɾ����ͷԪ��
	dq.pop_back();			//ɾ����βԪ��
	disp(dq);
	return 1;
}
void disp(deque<int> &dq)
{
	deque<int>::iterator iter;
	for (iter=dq.begin();iter!=dq.end();iter++)
		cout << *iter << " ";
	cout << endl;
}
