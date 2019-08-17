//��ؼ�·���㷨
#include "graph.cpp"
typedef struct
{	int ino;			//���
	int eno;			//�յ�
} KeyNode;				//�ؼ������

bool TopSort(AdjGraph *G,int topseq[])
//��������n�������ŵ���������topseq
{
	int i,j,n=0;
	int st[MAXV];						//����һ��˳��ջ
	int top=-1;							//ջ��ָ��Ϊtop
	ArcNode *p;
	for (i=0;i<G->n;i++)				//���ж��������ó�ֵ0
		G->adjlist[i].count=0;
	for (i=0;i<G->n;i++)				//�����ж�������
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	G->adjlist[p->adjvex].count++;
			p=p->nextarc;
		}
	}
	for (i=0;i<G->n;i++)
		if (G->adjlist[i].count==0)		//���Ϊ0�Ķ����ջ
		{	top++;
			st[top]=i;
		}
	while (top>-1)						//ջ��Ϊ��ʱѭ��
	{	i=st[top];top--;				//��ջ
		topseq[n]=i; n++;
		p=G->adjlist[i].firstarc;		//�ҵ�һ���ڽӵ�
		while (p!=NULL)
		{	j=p->adjvex;
			G->adjlist[j].count--;
			if (G->adjlist[j].count==0)	//���Ϊ0�����ڶ����ջ
			{	top++;
				st[top]=j;
			}
			p=p->nextarc;				//����һ���ڽӵ�
		}
	}
	if (n<G->n)					//���������в������ж���ʱ
		return false;
	else
	{
		printf("��������:");
		for (i=0;i<n;i++)
			printf("%c ",(char)(topseq[i]+'A')); 
		printf("\n");
		return true;
	}
}
bool KeyPath(AdjGraph *G,int &inode,int &enode,KeyNode keynode[],int &d)
//��ͼ�ڽӱ�G�������Դ��inode�����enode�Ĺؼ��keynode[0..d]
{	int topseq[MAXV];						//topseq���ڴ����������
	int i,w;
	ArcNode *p;
	if (!TopSort(G,topseq))
		return false;						//���ܲ�����������ʱ����false
	inode=topseq[0];						//���Դ��
	enode=topseq[G->n-1];					//������
	int ve[MAXV];							//�¼������翪ʼʱ��
	int vl[MAXV];							//�¼�����ٿ�ʼʱ��
	for (i=0;i<G->n;i++) ve[i]=0;			//�Ƚ������¼���ve�ó�ֵΪ0
	for (i=0;i<G->n;i++)					//���������������¼������翪ʼʱ��
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)						//����ÿһ���߼��
		{	w=p->adjvex;
			if (ve[i]+p->weight>ve[w])		//�������
				ve[w]=ve[i]+p->weight;
			p=p->nextarc;
		}
	 }
	for (i=0;i<G->n;i++)					//�Ƚ������¼���vlֵ��Ϊ���ֵ
		vl[i]=ve[enode];
	for (i=G->n-2;i>=0;i--)					//���������������¼�����ٿ�ʼʱ��
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	w=p->adjvex;
			if (vl[w]-p->weight<vl[i])		//����С��
				vl[i]=vl[w]-p->weight; 
			p=p->nextarc;
		}
	}
	d=-1;									//d���keynode�еĹؼ���±�,�ó���Ϊ-1
	for (i=0;i<G->n;i++)					//��ؼ��
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	w=p->adjvex;
			if (ve[i]==vl[w]-p->weight)		//(i��w)��һ���ؼ��
			{
				d++; keynode[d].ino=i; keynode[d].eno=w;
			}
			p=p->nextarc;
		}
	}
	return true;
}
void DispKeynode(AdjGraph *G)
{
	int inode,enode,d,i;
	KeyNode keynode[MAXV];
	if (KeyPath(G,inode,enode,keynode,d))
	{
		printf("��Դ��%c�����%c�Ĺؼ��:",char(inode='A'),char(enode+'A'));
		for (i=0;i<=d;i++)
			printf("(%c,%c)  ",char(keynode[i].ino+'A'),char(keynode[i].eno+'A'));
		printf("\n");
	}
	else printf("������ؼ��\n");
}
int main()
{
	AdjGraph *G;
	int n=9,e=11;
	int A[MAXV][MAXV]={
		{ 0,  6,  4,  5 ,INF,INF,INF,INF,INF},
		{INF, 0, INF,INF, 1 ,INF,INF,INF,INF},
		{INF,INF, 0 ,INF, 1 ,INF,INF,INF,INF},
		{INF,INF,INF, 0 ,INF,INF,INF, 2 ,INF},
		{INF,INF,INF,INF, 0 , 9 , 7 ,INF,INF},
		{INF,INF,INF,INF,INF, 0 ,INF,INF, 2 },
		{INF,INF,INF,INF,INF,INF, 0 ,INF, 4 },
		{INF,INF,INF,INF,INF,INF,INF, 0 , 4 },
		{INF,INF,INF,INF,INF,INF,INF,INF, 0 }};
	printf("����ͼ���ڽӱ�:\n");
	CreateAdj(G,A,n,e);							//����ͼ8.45���ڽӱ�
	printf("ͼG���ڽӱ�:\n"); DispAdj(G);
	DispKeynode(G);								//�󹹳ɹؼ�·���Ĺؼ��
	DestroyAdj(G);								//����ͼ
	return 1;
}