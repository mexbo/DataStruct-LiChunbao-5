//����13.8���ĳ���:ջ������ʹ��
#include <iostream>
#include <stack>
using namespace std;
int main()
{	stack<int> st;
	st.push(1); st.push(2); st.push(3);    
	cout << st.top() << " ";
	st.pop();	cout << st.top() << " ";
	st.pop();	st.top() = 7;
	st.push(4);st.push(5);
	st.pop() ;
	while (!st.empty()) 	//ջ����ʱ���ջ��Ԫ�ز���ջ
	{	cout << st.top() << " ";
		st.pop() ;
	}
	cout << endl;
	return 1;
}

