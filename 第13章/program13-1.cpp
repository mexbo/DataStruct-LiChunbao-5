//����13.1���ĳ���:��Ķ���
#include <iostream>
using namespace std;
class Sample  					//������Sample
{
private:
    int x,y; 						//���ݳ�Ա
public:
    void setvalue(int x1,int y1); 	//��Ա����
    void display();
};
void Sample::setvalue(int x1,int y1) { x=x1;y=y1; }
void Sample::display()
{
    cout << "x=" << x << ",y=" << y << endl;
}
