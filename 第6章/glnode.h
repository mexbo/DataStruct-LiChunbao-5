typedef char ElemType;
typedef struct lnode
{
	int tag;					//������ͱ�ʶ
	union 
	{
		ElemType data;			//ԭ��ֵ
		struct lnode *sublist;	//ָ���ӱ��ָ��
	} val;
	struct lnode *link;			//ָ����һ��Ԫ��
} GLNode;						//�����������
