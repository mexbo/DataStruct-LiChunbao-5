//�Ľ���Kruskal�㷨
#include "graph.cpp"
#define MaxSize 100
//-----���鼯�㷨��ʼ---------------------------------------
typedef struct 
{	
	int u;			//�ߵ���ʼ����
    int v;			//�ߵ���ֹ����
    int w;			//�ߵ�Ȩֵ
} Edge;
typedef struct node
{	
	int rank;						//����Ӧ��
	int parent;						//����Ӧ˫���±�
} UFSTree;							//���鼯���������
void MAKE_SET(UFSTree t[],int n)	//��ʼ�����鼯��
{ 
	int i;
	for (i=0;i<n;i++)				//�����Ŵ�0��n-1
	{
		t[i].rank=0;				//�ȳ�ʼ��Ϊ0
		t[i].parent=i;				//˫�׳�ʼ��ָ������
	}
}
int FIND_SET(UFSTree t[],int x)		//��x���������в��Ҽ��ϱ��
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
		t[y].parent=x;				//��y����x�����,y��Ϊx�ĺ��ӽ��
	else							//y�����ȴ��ڵ���x������
	{ 
		t[x].parent=y;				//��x����y�����,x��Ϊy�ĺ��ӽ��
		if (t[x].rank==t[y].rank)	//x��y��������ͬ
			t[y].rank++;			//y��������1
	}
}
//-----���鼯�㷨����---------------------------------------

//-----�������㷨��ʼ---------------------------------------
void sift(Edge E[],int low,int high)	//ɸѡ�㷨
{
	int i=low,j=2*i;     				//E[j]��E[i]������
	Edge temp=E[i];
	while (j<=high) 
	{
		if (j<high && E[j].w<E[j+1].w) 	//���Һ��ӽϴ�,��jָ���Һ���
			j++;    					//f��Ϊ2i+1
		if (temp.w<E[j].w) 
		{
			E[i]=E[j];              	//��E[j]������˫�׽��λ����
			i=j;                    	//�޸�i��jֵ,�Ա��������ɸѡ
			j=2*i;
		}
		else break;                 	//ɸѡ����
	}
	E[i]=temp;                      	//��ɸѡ����ֵ��������λ��
}
void HeapSort(Edge E[],int n)
{
	int i;
	Edge temp;
	for (i=n/2;i>=1;i--)  	//ѭ��������ʼ��
		sift(E,i,n); 
	for (i=n;i>=2;i--)   	//����n-1��ѭ��,���������
	{
		temp=E[1];        	//����һ��Ԫ��ͬ��ǰ������R[1]�Ի�
		E[1]=E[i];
		E[i]=temp;
		sift(E,1,i-1);     	//ɸѡR[1]���,�õ�i-1�����Ķ�
	}
}
//-----�������㷨����---------------------------------------

void Kruskal(MatGraph g)
{
	int i,j,k,u1,v1,sn1,sn2;
	UFSTree t[MaxSize];
	Edge E[MaxSize];
	k=1;					//e������±��1��ʼ��
	for (i=0;i<g.n;i++)		//��g�����ı߼�e
		for (j=0;j<=i;j++)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF)
			{
				E[k].u=i;E[k].v=j;E[k].w=g.edges[i][j];
				k++;
			}
	HeapSort(E,g.e);		//���ö������E���鰴Ȩֵ��������
	MAKE_SET(t,g.n);		//��ʼ�����鼯��t
	k=1;               		//k��ʾ��ǰ�����������ĵڼ�����,��ֵΪ1
	j=1;               		//E�бߵ��±�,��ֵΪ1
	while (k<g.n)       	//���ɵı���С��nʱѭ��
	{	
		u1=E[j].u;
		v1=E[j].v;			//ȡһ���ߵ�ͷβ������u1��v2
		sn1=FIND_SET(t,u1);
		sn2=FIND_SET(t,v1); //�ֱ�õ��������������ļ��ϱ��
		if (sn1!=sn2)     	//���������ڲ�ͬ�ļ���,�ñ�����С��������һ����
		{	
			printf("  (%d,%d):%d\n",u1,v1,E[j].w);
			k++;			//���ɱ�����1
			UNION(t,u1,v1);	//��u1��v1��������ϲ�
		}
		j++;   				//ɨ����һ����
	}
}

int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={
		{0,28,INF,INF,INF,10,INF},
		{28,0,16,INF,INF,INF,14},
		{INF,16,0,12,INF,INF,INF},
		{INF,INF,12,0,22,INF,18},
		{INF,INF,INF,22,0,25,24},
		{10,INF,INF,INF,25,0,INF},
		{INF,14,INF,18,24,INF,0}};
	int n=7, e=9;
	CreateMat(g,A,n,e);			//�������̡̳���ͼ8.27���ڽӾ���
	printf("ͼG���ڽӾ���:\n");
	DispMat(g);					//����ڽӾ���
	printf("Kruskal�㷨���\n");
	Kruskal(g);
	return 1;
}