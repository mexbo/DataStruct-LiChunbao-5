//����5.1�����㷨����n!�ĵݹ��㷨
#include <stdio.h>
int fun(int n)
{
	if (n==1) 					//���1
		return(1);				//���2
	else 						//���3
		return(fun(n-1)*n);		//���4
}
int main()
{
	printf("10!=%d\n",fun(10));
	return 1;
}