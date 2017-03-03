#include<stdio.h>
#include<malloc.h>
typedef enum {Link,Thread} PointerTag;		/*ָ���־*/
typedef char DataType;
typedef struct BiThreTree{					/*����ڵ�Ԫ��*/
	PointerTag LTag,RTag;
	DataType data;
	struct BiThreTree *lchild,*rchild;
}BiThreTree;

BiThreTree *pre;		/*ȫ�ֱ��������ڶ�������������*/
int f;
BiThreTree *CreateTree()
{
	BiThreTree *T;
	DataType ch;
	if(f==1)	printf("���ڵ㣬#��ʾ����\n");
	else        printf("����ڵ㣬#��ʾ����");
		scanf("\n%c",&ch);
	f=f+1;
	if(ch=='#')
		T=NULL;
	else 
	{
		T=(BiThreTree*)malloc(sizeof(BiThreTree));
		T->data=ch;
		T->LTag=Link;			/*��ʼ��ʱָ���ʶ��ΪLink*/
		T->RTag=Link;

		printf("%c����  ",T->data);
			T->lchild=CreateTree();

		printf("%c�Һ���  ",T->data);
			T->rchild=CreateTree();
	}
	return T;
}

void InThread(BiThreTree *T)
{
	BiThreTree *p;
	p=T;
	if(p)
	{
		InThread(p->lchild);
		if(p->lchild==NULL)
		{
			p->LTag=Thread;
			p->lchild=pre;
		}
		if(pre->rchild==NULL)
		{
			pre->RTag=Thread;
			pre->rchild=p;
		}
		pre=p;
		InThread(p->rchild);
	}
}

BiThreTree *InOrderThrTree(BiThreTree *T)	/*��������������*/
{
	BiThreTree *Thre;		/*ThreΪͷ����ָ��*/
	Thre=(BiThreTree *)malloc(sizeof(BiThreTree));
	Thre->lchild=T;
	Thre->rchild=Thre;
	pre=Thre;
	InThread(T);
	pre->RTag=Thread;
	pre->rchild=Thre;
	Thre->rchild=pre;
	return Thre;
}

void InThrTravel(BiThreTree *Thre)  /*�������������*/
{
	BiThreTree *p;
	p=Thre->lchild;
	while(p!=Thre)
	{
		while(p->LTag==Link)
			p=p->lchild;
		printf("%4c",p->data);
		while(p->RTag==Thread && p->rchild!=Thre)
		{
			p=p->rchild;
			printf("%4c",p->data);
		}
	    p=p->rchild;
	}
}

void main()
{
	BiThreTree *T,*Thre;
	f=1;
	T=CreateTree();
	Thre=InOrderThrTree(T);
	printf("InOrder Traverse Binary Tree:\n");
	InThrTravel(Thre);
}
