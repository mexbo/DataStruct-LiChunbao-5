//����6.3�����㷨��������g��ԭ�Ӹ���
#include "glist.cpp"

//�ⷨ1�ķ���
int Count1(GLNode *g)					//������g��ԭ�Ӹ���
{	int n=0;
	GLNode *g1=g->val.sublist;
	while (g1!=NULL)					//��ÿ��Ԫ�ؽ���ѭ������
	{	if (g1->tag==0)					//Ϊԭ��ʱ
			n++;						//ԭ�Ӹ�����1
		else							//Ϊ�ӱ�ʱ
			n+=Count1(g1);				//�ۼ�Ԫ�ص�ԭ�Ӹ���
		g1=g1->link;					//�ۼ��ֵܵ�ԭ�Ӹ���
	}
	return n;							//������ԭ�Ӹ���
}
//�ⷨ2�ķ���
int Count2(GLNode *g)					//������g��ԭ�Ӹ���
{	int n=0;
	if (g!=NULL)						//��ÿ��Ԫ�ؽ���ѭ������
	{	if (g->tag==0)					//Ϊԭ��ʱ
			n++;						//ԭ�Ӹ�����1
		else							//Ϊ�ӱ�ʱ
			n+=Count2(g->val.sublist);	//�ۼ�Ԫ�ص�ԭ�Ӹ���
		n+=Count2(g->link);				//�ۼ��ֵܵ�ԭ�Ӹ���
	}
	return n;							//������ԭ�Ӹ���
}

int main()
{
	GLNode *g;
	char *str="((a),b,(c,d))";
	g=CreateGL(str);
	DispGL(g);
	printf("\n");
	printf("�ⷨ1ԭ�Ӹ�����%d\n",Count1(g));
	printf("�ⷨ2ԭ�Ӹ�����%d\n",Count2(g));
	DestroyGL(g);
	return 1;
}
