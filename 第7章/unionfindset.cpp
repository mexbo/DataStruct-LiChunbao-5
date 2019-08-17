//���鼯���㷨
#include <stdio.h>
#define MaxSize 100
#define N 10		//�����漰������,�˵ı�Ŵ�1��N
#define M 7			//���ݹ�ϵ����
#define Q 3			//ѯ�ʸ���
typedef struct node
{
	int data;		//����Ӧ�˵ı��
	int rank;		//����Ӧ��
	int parent;		//����Ӧ˫���±�
} UFSTree;
void MAKE_SET(UFSTree t[],int n)	//��ʼ�����鼯��
{ 
	int i;
	for (i=1;i<=n;i++)
	{
		t[i].data=i;		//����Ϊ���˵ı��
		t[i].rank=0;		//�ȳ�ʼ��Ϊ0
		t[i].parent=i;		//˫�׳�ʼ��ָ������
	}
}
int FIND_SET(UFSTree t[],int x)	//��x���������в��Ҽ��ϱ��
{
	if (x!=t[x].parent)					//˫�ײ�������
		return(FIND_SET(t,t[x].parent));//�ݹ���˫������x
	else
		return(x);						//˫��������,����x
}
void UNION(UFSTree t[],int x,int y)	//��x��y���ڵ������ϲ�
{ 
	x=FIND_SET(t,x);
	y=FIND_SET(t,y);
	if (t[x].rank>t[y].rank)		//y������С��x������
		t[y].parent=x;				//��y����x�����,x��Ϊy�ĺ��ӽ��
	else							//y�����ȴ��ڵ���x������
	{ 
		t[x].parent=y;				//��x����y�����,y��Ϊx�ĺ��ӽ��
		if (t[x].rank==t[y].rank)	//x��y��������ͬ
			t[y].rank++;			//y��������1
	}
}
int main()
{
	int i,x,y;
	UFSTree t[MaxSize];
	int rel[M][2]={{2,4},{5,7},{1,3},{8,9},{1,2},{5,6},{2,3}};
	int ans[Q][2]={{3,4},{7,10},{8,9}};
	MAKE_SET(t,N);					//��ʼ�����鼯��t
	for (i=0;i<M;i++)				//���ݹ�ϵ���кϲ�����
		UNION(t,rel[i][0],rel[i][1]);
	printf("data  rank  parent\n");	//������鼯��t
	for (i=1;i<=N;i++)
		printf("%4d%5d%6d\n",t[i].data,t[i].rank,t[i].parent);
	printf("\n");
	printf("��ѯ�ʵĽ��:\n");		//��������
	for (i=0;i<Q;i++)
	{
		x=FIND_SET(t,ans[i][0]);
		y=FIND_SET(t,ans[i][1]);
		if (x==y)
			printf("  (%d,%d):Yes\n",ans[i][0],ans[i][1]);
		else
			printf("  (%d,%d):No\n",ans[i][0],ans[i][1]);
	}
	return 1;
}
