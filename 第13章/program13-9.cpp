//����13.9���ĳ���:����������ʹ��
#include <iostream>
#include <queue>
using namespace std;
int main()
{	queue<int> q;
	q.push(1); q.push(2); q.push(3);
	cout << q.front() << " "; 
	q.pop(); cout << q.front() << " ";  q.pop();
	q.push(4); q.push(5);
	q.pop();
	while (!q.empty())   //�Ӳ���ʱ����
	{	cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	return 1;
}

