//ͼ�����ִ洢�ṹ
#define INF 32767				//�����
#define	MAXV 100				//��󶥵����
typedef char InfoType;

//���¶����ڽӾ�������
typedef struct
{	int no;						//������
	InfoType info;				//����������Ϣ
} VertexType;					//��������
typedef struct
{	int edges[MAXV][MAXV];		//�ڽӾ�������
	int n,e;					//������������
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
} MatGraph;						//������ͼ�ڽӾ�������

//���¶����ڽӱ�����
typedef struct ANode
{	int adjvex;					//�ñߵ��ڽӵ���
	struct ANode *nextarc;		//ָ����һ���ߵ�ָ��
	int weight;					//�ñߵ������Ϣ����Ȩֵ�������ͱ�ʾ��
} ArcNode;						//�߽������
typedef struct Vnode
{	InfoType info;				//����������Ϣ
	int count;					//��Ŷ������,����������������
	ArcNode *firstarc;			//ָ���һ����
} VNode;						//�ڽӱ�ͷ�������
typedef struct 
{	VNode adjlist[MAXV];		//�ڽӱ�ͷ�������
	int n,e;					//ͼ�ж�����n�ͱ���e
} AdjGraph;						//������ͼ�ڽӱ�����
