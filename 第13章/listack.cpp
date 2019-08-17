//��ջ��ģ��LiStack
#include <iostream>
using namespace std;
template <typename T>
struct NodeType				//�������������
{	T data;					//������
	NodeType *next;			//ָ����
};
template <typename T>
class LiStack				//��ջ��ģ��
{
	NodeType<T> *lhead;		//�������ͷ���
public:
	LiStack()				//���캯��,��ʼ��ջ
	{
		lhead=new NodeType<T>();
		lhead->next=NULL;
	}
	~LiStack()				//��������,����ջ
	{
		NodeType<T> *p=lhead->next;
		while (p!=NULL)
		{
			delete lhead;
			lhead=p;
			p=p->next;
		}
		delete lhead;
	}
	int StackEmpty()			//�ж�ջ�Ƿ�Ϊ��
	{	
		return(lhead->next==NULL); 
	}
	void Push(T e)				//��ջ
	{	NodeType<T> *p;
		p=new NodeType<T>();
		p->data=e;
		p->next=lhead->next;	//����*p�����Ϊ��һ�����ݽ��
		lhead->next=p;
	}
	bool Pop(T &e)				//��ջ
	{	NodeType<T> *p;
		if (lhead->next==NULL)	//ջ�յ����
			return false;
		p=lhead->next;			//pָ���һ�����ݽ��
		e=p->data;
		lhead->next=p->next;
		delete p;
		return true;
	}
	bool GetTop(T &e)			//ȡջ��Ԫ��
	{	if (lhead->next==NULL)	//ջ�յ����
			return false;
		e=lhead->next->data;
		return true;
	}
};
int main()
{	char e;
	LiStack<char> s;			//����ջ����
	cout << "��ջΪ" << (s.StackEmpty()?"��":"�ǿ�") << endl;
	cout << "���ν���ջԪ��a,b,c,d,e" << endl;
	s.Push('a');
	s.Push('b');
	s.Push('c');
	s.Push('d');
	s.Push('e');
	cout << "��ջΪ" << (s.StackEmpty()?"��":"�ǿ�") << endl;
	s.GetTop(e);
	cout << "��ջջ��Ԫ��Ϊ:" << e << endl;
	cout << "����ջ����:";
	while (!s.StackEmpty())
	{	s.Pop(e);
		cout << e << " ";
	}
	cout << endl;
	cout << "��ջΪ" << (s.StackEmpty()?"��":"�ǿ�") << endl;
	return 1;
}

