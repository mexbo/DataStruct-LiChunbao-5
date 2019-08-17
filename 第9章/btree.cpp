//B-�������㷨
#include <stdio.h>
#include <malloc.h>
#define MAXM 10						//����B-�������Ľ���
typedef int KeyType;        		//KeyTypeΪ�ؼ�������
typedef struct node
{	int keynum;                		//��㵱ǰӵ�еĹؼ��ֵĸ���
    KeyType key[MAXM];		   		//key[1..keynum]��Źؼ���,key[0]����
	struct node *parent;			//˫�׽��ָ��
    struct node *ptr[MAXM];			//���ӽ��ָ������ptr[0..keynum]
} BTNode;         					//B-���������
typedef struct 						//B-���Ĳ��ҽ������
{
	BTNode *pt;						//ָ���ҵ��Ľ��
    int i;							//1..m,�ڽ���еĹؼ������
    int tag;						//1:���ҳɹ�,O:����ʧ��
}  Result;							//���ҽ������
int m;								//m��B-��,Ϊȫ�ֱ���
int Max;							//m��B-����ÿ����������ؼ��ָ���,Max=m-1
int Min;							//m��B-���з�Ҷ�ӽ������ٹؼ��ָ���,Min=(m-1)/2
int Search(BTNode *p,KeyType k) 
{  //��p->key[1..keynum]�в���i,ʹ��p->key[i]<=k<p->key[i+1]
	int i; 
	for(i=0;i<p->keynum && p->key[i+1]<=k;i++);
	return i;
}
Result SearchBTree(BTNode *t,KeyType k)
{ /*��m��t��t�ϲ��ҹؼ���k,���ؽ��(pt,i,tag)�������ҳɹ�,������ֵ
   tag=1,ָ��pt��ָ����е�i���ؼ��ֵ���k����������ֵtag=0,����k��
   �ؼ���Ӧ������ָ��Pt��ָ����е�i�͵�i+1���ؼ���֮��*/
	BTNode *p=t,*q=NULL;			//��ʼ��,pָ�������,qָ��p��˫��
	int found=0,i=0;
	Result r;
	while (p!=NULL && found==0)
	{
		i=Search(p,k);				//��p->key[1..keynum]�в���i,ʹ��p->key[i]<=k<p->key[i+1]
		if (i>0 && p->key[i]==k)	//�ҵ�����ؼ���
			found=1;
		else
		{
			q=p;
			p=p->ptr[i];
		}
	}
	r.i=i;
	if (found==1)					//���ҳɹ�
	{
		r.pt=p;r.tag=1;
	}
	else							//���Ҳ��ɹ�,����K�Ĳ���λ����Ϣ
	{
		r.pt=q;r.tag=0;
	}
	return r;						//����k��λ��(�����λ��)
}
void Insert(BTNode *&q,int i,KeyType x,BTNode *ap)
{ //��x��ap�ֱ���뵽q->key[i+1]��q->ptr[i+1]��
	int j;
	for(j=q->keynum;j>i;j--)	//�ճ�һ��λ��
	{
		q->key[j+1]=q->key[j];
		q->ptr[j+1]=q->ptr[j];
	}
	q->key[i+1]=x;
	q->ptr[i+1]=ap;
	if (ap!=NULL) ap->parent=q;  
	q->keynum++;
}
void Split(BTNode *&q,BTNode *&ap)
{ //�����q���ѳ��������,ǰһ�뱣��,��һ�������������ap
	int i,s=(m+1)/2;
	ap=(BTNode *)malloc(sizeof(BTNode));	//�����½��*ap
	ap->ptr[0]=q->ptr[s];					//��һ������ap
	for (i=s+1;i<=m;i++)
	{
		ap->key[i-s]=q->key[i];
		ap->ptr[i-s]=q->ptr[i];
		if (ap->ptr[i-s]!=NULL)
			ap->ptr[i-s]->parent=ap;
	}	
	ap->keynum=q->keynum-s;	
	ap->parent=q->parent;	
	for (i=0;i<=q->keynum-s;i++) //�޸�ָ��˫�׽���ָ��
		if (ap->ptr[i]!=NULL) ap->ptr[i]->parent = ap;
	q->keynum=s-1;						//q��ǰһ�뱣��,�޸�keynum
}
void NewRoot(BTNode *&t,BTNode *p,KeyType x,BTNode *ap)
{ //���ɺ���Ϣ(T,x,ap)���µĸ����*t,ԭt��apΪ����ָ��
	t=(BTNode *)malloc(sizeof(BTNode));
	t->keynum=1;t->ptr[0]=p;t->ptr[1]=ap;t->key[1]=x;
	if (p!=NULL) p->parent=t;  
	if (ap!=NULL) ap->parent=t;
	t->parent=NULL;
}
void InsertBTree(BTNode *&t, KeyType k, BTNode *q, int i) 
{ /*��m��t��t�Ͻ��*q��key[i]��key[i+1]֮�����ؼ���k��������
   ������,����˫�������б�Ҫ�Ľ����ѵ���,ʹt����m��t����*/
	BTNode *ap;
	int finished,needNewRoot,s;
	KeyType x;
	if (q==NULL)						//t�ǿ���(����q��ֵΪNULL)
		NewRoot(t,NULL,k,NULL);			//���ɽ����ؼ���k�ĸ����*t
	else 
	{
		x=k;ap=NULL;finished=needNewRoot=0;     
		while (needNewRoot==0 && finished==0) 
		{
			Insert(q,i,x,ap);				//��x��ap�ֱ���뵽q->key[i+1]��q->ptr[i+1]
			if (q->keynum<=Max) finished=1;	//�������
			else 
			{  //���ѽ��*q,��q->key[s+1..m],q->ptr[s..m]��q->recptr[s+1..m]�����½��*ap
				s=(m+1)/2;
				Split(q,ap); 
				x=q->key[s];
				if (q->parent)				//��˫�׽��*q�в���x�Ĳ���λ��
				{  
					q=q->parent;i=Search(q, x);  
				} 
				else needNewRoot=1;
			}
		}
		if (needNewRoot==1)					//������ѷ���Ϊ���*q��*ap
			NewRoot(t,q,x,ap);				//�����¸����*t,q��apΪ����ָ��
	}
}
void DispBTree(BTNode *t)	//�����ű�ʾ�����B-��
{
	int i;
	if (t!=NULL)
	{
		printf("[");			//�����ǰ���ؼ���
		for (i=1;i<t->keynum;i++)
			printf("%d ",t->key[i]);
		printf("%d",t->key[i]);
		printf("]");
		if (t->keynum>0)
		{
			if (t->ptr[0]!=0) printf("(");  //������һ������ʱ���"("��
			for (i=0;i<t->keynum;i++)		//��ÿ���������еݹ����
			{
				DispBTree(t->ptr[i]);
				if (t->ptr[i+1]!=NULL) printf(",");
			}
			DispBTree(t->ptr[t->keynum]);
			if (t->ptr[0]!=0) printf(")");	//������һ������ʱ���")"��
		}
	}
}
void Remove(BTNode *p,int i)
//��*p���ɾ��key[i]�����ĺ���ָ��ptr[i]
{
	int j;
	for (j=i+1;j<=p->keynum;j++)		//ǰ��ɾ��key[i]��ptr[i]
	{
		p->key[j-1]=p->key[j];
		p->ptr[j-1]=p->ptr[j];
	}
	p->keynum--;
}
void Successor(BTNode *p,int i)
//���ұ�ɾ�ؼ���p->key[i](�ڷ�Ҷ�ӽ����)�����Ҷ�ӽ��
{
	BTNode *q;
	for (q=p->ptr[i];q->ptr[0]!=NULL;q=q->ptr[0]);
	p->key[i]=q->key[1];	//���ƹؼ���ֵ
}
void MoveRight(BTNode *p,int i)
//��һ���ؼ����ƶ������ֵ���
{
	int c;
	BTNode *t=p->ptr[i];
	for (c=t->keynum;c>0;c--)	//�����ֵ������йؼ����ƶ�һλ
	{
		t->key[c+1]=t->key[c];
		t->ptr[c+1]=t->ptr[c];
	}
	t->ptr[1]=t->ptr[0];		//��˫�׽���ƶ��ؼ��ֵ����ֵ���
	t->keynum++;
	t->key[1]=p->key[i];
	t=p->ptr[i-1];				//�����ֵ������һ���ؼ����ƶ���˫�׽����
	p->key[i]=t->key[t->keynum];
	p->ptr[i]->ptr[0]=t->ptr[t->keynum];
	t->keynum--;
}
void MoveLeft(BTNode *p,int i)
//��һ���ؼ����ƶ������ֵ���
{
	int c;
	BTNode *t;
	t=p->ptr[i-1];				//��˫�׽���еĹؼ����ƶ������ֵ���
	t->keynum++;
	t->key[t->keynum]=p->key[i];
	t->ptr[t->keynum]=p->ptr[i]->ptr[0];

	t=p->ptr[i];				//�����ֵ��еĹؼ����ƶ���˫���ֵ���
	p->key[i]=t->key[1];
	p->ptr[0]=t->ptr[1];
	t->keynum--;
	for (c=1;c<=t->keynum;c++)	//�����ֵ������йؼ����ƶ�һλ
	{
		t->key[c]=t->key[c+1];
		t->ptr[c]=t->ptr[c+1];
	}
}
void Combine(BTNode *p,int i)
//���������ϲ���һ�������
{
	int c;
	BTNode *q=p->ptr[i];			//ָ���ҽ��,�������ÿպ�ɾ��
	BTNode *l=p->ptr[i-1];
	l->keynum++;					//lָ������
	l->key[l->keynum]=p->key[i];
	l->ptr[l->keynum]=q->ptr[0];
	for (c=1;c<=q->keynum;c++)		//�����ҽ���е����йؼ���
	{
		l->keynum++;
		l->key[l->keynum]=q->key[c];
		l->ptr[l->keynum]=q->ptr[c];
	}
	for (c=i;c<p->keynum;c++)		//ɾ����������еĹؼ���
	{
		p->key[c]=p->key[c+1];
		p->ptr[c]=p->ptr[c+1];
	}
	p->keynum--;
	free(q);						//�ͷſ��ҽ��Ŀռ�
}
void Restore(BTNode *p,int i)
//�ؼ���ɾ����,����B-��,�ҵ�һ���ؼ��ֽ�����뵽p->ptr[i]��
{
	if (i==0)							//Ϊ����߹ؼ��ֵ����
		if (p->ptr[1]->keynum>Min)
			MoveLeft(p,1);
		else
			Combine(p,1);
	else if (i==p->keynum)				//Ϊ���ұ߹ؼ��ֵ����
		if (p->ptr[i-1]->keynum>Min)
			MoveRight(p,i);
		else
			Combine(p,i);
	else if (p->ptr[i-1]->keynum>Min)	//Ϊ�������
		MoveRight(p,i);
	else if (p->ptr[i+1]->keynum>Min)
		MoveLeft(p,i+1);
	else
		Combine(p,i);
}
int SearchNode(KeyType k,BTNode *p,int &i)
//�ڽ��p���ҹؼ���Ϊk��λ��i,�ɹ�ʱ����1,���򷵻�0
{
	if (k<p->key[1])	//kС��*p������С�ؼ���ʱ����0
	{
		i=0;
		return 0;
	}
	else				//��*p����в���
	{
		i=p->keynum;
		while (k<p->key[i] && i>1)
			i--;
		return(k==p->key[i]);
	}
}
int RecDelete(KeyType k,BTNode *p)
//���Ҳ�ɾ���ؼ���k
{
	int i;
	int found;
	if (p==NULL)
		return 0;
	else
	{
		if ((found=SearchNode(k,p,i))==1)		//���ҹؼ���k
		{
			if (p->ptr[i-1]!=NULL)				//��Ϊ��Ҷ�ӽ��
			{
				Successor(p,i);					//�����̴�����
				RecDelete(p->key[i],p->ptr[i]);	//p->key[i]��Ҷ�ӽ����
			}
			else
				Remove(p,i);					//��*p�����λ��i��ɾ���ؼ���
		}
		else
			found=RecDelete(k,p->ptr[i]);		//�غ��ӽ��ݹ���Ҳ�ɾ���ؼ���k
		if (p->ptr[i]!=NULL)
			if (p->ptr[i]->keynum<Min)			//ɾ����ؼ��ָ���С��MIN
				Restore(p,i);
		return found;
	}
}
void DeleteBTree(KeyType k,BTNode *&root)
//��B-��root��ɾ���ؼ���k,����һ�������ɾ��ָ���Ĺؼ���,�����������ؼ���,��ɾ���ý��
{
	BTNode *p;				//�����ͷ�һ���յ�root
	if (RecDelete(k,root)==0)
		printf("   �ؼ���%d����B-����\n",k);
	else if (root->keynum==0)
	{
		p=root;
		root=root->ptr[0];
		free(p);
	}
}
int main()
{
	BTNode *t=NULL;
	Result s;
	int j,n=20;
	KeyType a[]={1,2,6,7,11,4,8,13,10,5,17,9,16,20,3,12,14,18,19,15},k;
	m=5;								//��10.7
	Max=m-1;Min=(m-1)/2;
	printf("\n");
	printf(" ����һ��%d��B-��:\n",m);
	for (j=0;j<n;j++)					//����һ��5��B-��t	
	{
		s=SearchBTree(t,a[j]);
		if (s.tag==0)
			InsertBTree(t,a[j],s.pt,s.i);	
		printf("   ��%d��,����%d: ",j+1,a[j]);DispBTree(t);printf("\n");
	}
	printf(" ɾ������:\n");				//��10.8
	k=8;
	DeleteBTree(k,t);
	printf("   ɾ��%d: ",k);
	DispBTree(t);printf("\n");
	k=16;
	DeleteBTree(k,t);
	printf("   ɾ��%d: ",k);
	DispBTree(t);printf("\n");
	k=15;
	DeleteBTree(k,t);
	printf("   ɾ��%d: ",k);
	DispBTree(t);printf("\n");
	k=4;
	DeleteBTree(k,t);
	printf("   ɾ��%d: ",k);
	DispBTree(t);printf("\n\n");
	return 1;
}
