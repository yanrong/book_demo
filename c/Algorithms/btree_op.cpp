/********************************************************************************************************
*Copyright (c++) by xihua_university
*All Rights Reserved
*
*Filename:�����������������������������������������ĵݹ���ǵݹ��㷨�Զ��庯����STL��׼ģ�����ʵ��.cpp
*Function:�����������������������������������������ĵݹ���ǵݹ��㷨�Զ��庯����STL��׼ģ�����ʵ��
*Debugging Evironment:visul studio 2012
*Auther:���̲�
*Final:2013,10,30
*********************************************************************************************************/
#include<iostream>
#include<stack>
#include<queue>
#include<ctime>
using namespace std;
const int MAXLENGTH = 100;
typedef struct bnode//���������
{
	bool mark;
	char data;
    bnode* Lchild;
	bnode* Rchild;
}BiNode, *pBiNode;

typedef struct Stack//ջ
{
	pBiNode data;
	Stack* next;
} Stack, *pStack;

typedef struct Queue//����
{
	pBiNode  data;
	Queue* next;
}Queue, *pQueue;

typedef struct //������βָ��
{
	pQueue front;
	pQueue rear;
} Lqueue, *pLqueue;

//////////////////////////////////////////////////////
pStack Stack_Init ();//ջ��ʼ��
bool Stack_isEmpty (pStack* ppstack);//�ж�ջ�Ƿ�Ϊ��
void Stack_Push (pStack pstack, pBiNode element);//ѹջ
pBiNode Stack_GetTop (pStack pstack);//ȡ��ջ��Ԫ��
pBiNode Stack_Pop (pStack* ppstack);//��ջ
//void Stack_Destroy (pStack pstack);//�ͷ���ջ�ռ�

pLqueue Queue_Init ();//���г�ʼ��
bool Queue_isEmpty (pLqueue* pplqueue);//�ж��Ƿ�Ϊ�ն���
void Queue_In (pLqueue plqueue, pBiNode element);//�����
pBiNode Queue_Out (pLqueue* pplqueue);//������
//pBiNode* Queue_Out (pLqueue* pplqueue, bool boolean);//���س����к���,���������ʵ������
//void Queue_Destroy (pLqueue plqueue);//�ͷ������пռ�

int CountBinary (pBiNode T);//����������
int CountBinaryLeaf (pBiNode T);//����Ҷ�ڵ���
int CountBinaryHeigh (pBiNode T);//��������
pBiNode BinaryTree_Create ();//���򷨴�����ȫ������
void BinaryTree_Print_ByDigui (pBiNode T, int tag);//�ݹ��������򡢺������
void BinaryTree_Print_ByQueue (pBiNode T, bool boolean);//���в��򷨱���������������ݣ���ѡ�����Զ��庯��ʵ�ֻ���STL
void BinaryTree_Init(pBiNode pbinode);//��ǳ�ʼ��
void BinaryTree_Print_ByStack (pBiNode T, int tag, bool boolean);//ջ�������򡢺��򡢱���������������ݣ���ѡ�����Զ��庯��ʵ�ֻ���STL
////////////////////////////////////////////////////
int main()
{
	long start_time, end_time;//��¼���ֱ鷽��������ʱ��
	pBiNode root;


	system("color 1e");
	printf ("��������һ���ַ�����0����\n");
    root = BinaryTree_Create ();//���Զ��庯������
	//root = BinaryTree_Create_ByQueue (false);//��STL��������
	//�ݹ����
    printf ("�ö�����һ����%d�����\n", CountBinary(root));
    printf ("�ö�����һ����%d��Ҷ���\n", CountBinaryLeaf(root));
	printf ("�ö����������Ϊ%d\n", CountBinaryHeigh(root));
	printf ("(1)�ݹ����������ȡ��������:\n");//�ݹ��������
	start_time = clock();
	BinaryTree_Print_ByDigui (root, 1);
	end_time = clock();
	printf ("\n����ʱ��Ϊ:%d����\n\n", end_time-start_time);

	printf ("(2)�ݹ����������ȡ��������:\n");//�ݹ��������
	start_time = clock();
	BinaryTree_Print_ByDigui (root, 2);
	end_time = clock();
	printf ("\n����ʱ��Ϊ:%d����\n\n", end_time-start_time);

	printf ("(3)�ݹ���������ȡ��������:\n");//�ݹ�������
	start_time = clock();
	BinaryTree_Print_ByDigui (root, 3);
	end_time = clock();
	printf ("\n����ʱ��Ϊ:%d����\n\n", end_time-start_time);
	//�ǵݹ����
	printf ("(4)���в��������ȡ��������:\n");//���в������
	start_time = clock();
	BinaryTree_Print_ByQueue (root, true);
	end_time = clock();
	printf ("\n����ʱ��Ϊ:%d����\n\n", end_time-start_time);

	printf ("(5)���в���STL������ȡ��������:\n");//���в���STLʵ��
	start_time = clock();
	BinaryTree_Print_ByQueue (root, false);
	end_time = clock();
	printf ("\n����ʱ��Ϊ:%d����\n\n", end_time-start_time);

	printf ("(6)ջ���������ȡ��������:\n");//ջ�������
	start_time = clock();
	BinaryTree_Print_ByStack (root, 1, true);
	end_time = clock();
	printf ("\n����ʱ��Ϊ:%d����", end_time-start_time);

	printf ("\n\n(7)ջ���������ȡ��������:\n");//ջ�������
	start_time = clock();
	BinaryTree_Print_ByStack (root, 2, true);
	end_time = clock();
	printf ("\n����ʱ��Ϊ:%d����", end_time-start_time);

	printf ("\n\n(8)ջ���������ȡ��������:\n");//ջ�������
	start_time = clock();
	BinaryTree_Print_ByStack (root, 3, true);
	end_time = clock();
	printf ("\n����ʱ��Ϊ:%d����", end_time-start_time);

	printf ("\n\n(9)ջ����STL������ȡ��������:\n");//ջSTL�������
	start_time = clock();
	BinaryTree_Print_ByStack (root, 1, false);
	end_time = clock();
	printf ("\n����ʱ��Ϊ:%d����", end_time-start_time);

	printf ("\n\n(10)ջ����STL������ȡ��������:\n");//ջSTL�������
	start_time = clock();
	BinaryTree_Print_ByStack (root, 2, false);
	end_time = clock();
	printf ("\n����ʱ��Ϊ:%d����", end_time-start_time);

	BinaryTree_Init(root);
	printf ("\n\n(11)ջ����STL������ȡ��������:\n");//ջSTL�������
	start_time = clock();
	BinaryTree_Print_ByStack (root, 3, false);
	end_time = clock();
	printf ("\n����ʱ��Ϊ:%d����\n", end_time-start_time);

	return 0;
}

/***����������***/
int CountBinary (pBiNode T)//�����������
{
	pStack pstack;
	int count(0);


    pstack = Stack_Init ();//ջ��ʼ��
	while (T!=NULL)
	{
   while (T!=NULL)
   {
       count++;
    if (T->Rchild!=NULL)
	   Stack_Push(pstack,T->Rchild);
       T = T->Lchild;
   }
    T = Stack_Pop(&pstack);

	}

return count;
}

/***����Ҷ�ڵ���***/

int CountBinaryLeaf (pBiNode T)//�����������Ҷ�ڵ���
{
pStack pstack;
int count(0);

pstack = Stack_Init ();//ջ��ʼ��
while (!Stack_isEmpty(&pstack) || T!=NULL)
{
while (T!=NULL)
{
	Stack_Push(pstack,T);
	T = T->Lchild;
}

if (!Stack_isEmpty(&pstack))
{
T = Stack_Pop(&pstack);
if (T->Lchild==NULL && T->Rchild==NULL)
count++;
T = T->Rchild;
}
}
return count;

}

/***��������***/
int CountBinaryHeigh (pBiNode T)
{
    pLqueue plqueue;
	pBiNode temp(T);
	int depth(0), visited_unmber(0), queuein_number(0), last_visited_number(0);//visited_unmber(�Ѿ����ʹ��Ľ����)��queuein_number(�Ѿ������еĽ����)
                                                            //last_visited_number(�ò����һ��Ҫ���ʵĽ����)��depth(��������)

    plqueue = Queue_Init();//��ʼ������
    if (temp!=NULL)
	{
     Queue_In(plqueue,temp);
     ++queuein_number;//�����н������1
     last_visited_number = queuein_number;//�������һ��Ҫ���ʵĽ����
	 while (!Queue_isEmpty(&plqueue))
	 {
      temp = Queue_Out(&plqueue);
	  ++visited_unmber;//���ʽ������1
      if (temp->Lchild!=NULL)//����������������
	  {
		  Queue_In(plqueue,temp->Lchild);
          ++queuein_number;//�����н������1
	  }
      if (temp->Rchild!=NULL)//������Һ����������
	  {
       Queue_In(plqueue,temp->Rchild);
       ++queuein_number;//�����н������1
	  }
      if (last_visited_number==visited_unmber)//ִ�е���˵����һ���Ѿ��������
	  {                                       //depth��ȼ�1�������������һ��Ҫ���ʵĽ����

     ++depth;
     last_visited_number = queuein_number;
	 }

	 }
	}
	 return depth;

}

/***���򷨴�����ȫ������***////////////////////////////////////////////////////////////////////////////
pBiNode BinaryTree_Create ()
{
	 char c;
	 pBiNode root;
	 pBiNode T;
     pBiNode temp[MAXLENGTH];
	 int front(1), rear(0);

     c = getchar();
	 while (c!='0')
	 {
		 T = new BiNode();
		 T->mark = false;
		 T->data = c;
         T->Lchild = NULL;
		 T->Rchild = NULL;

		 temp[++rear] = T;

		 if (rear==1)
			 root = T;
		 else
		 {
          if (T!=NULL && temp[front]!=NULL)//�����ĸ����Ů�������������Ů
		  {
            if (rear%2==0)//������ȫ���������ص�����ŮΪż��
				temp[front]->Lchild = T;
			else//������ȫ���������ص�����ŮΪ����
				temp[front]->Rchild = T;
		  }
		  if (rear%2==1)//�Ѿ��������ˣ�fornt��1��һ���������ĸ
		      front++;
		 }
		  c = getchar();
	 }
	return root;

	 }

/***�ݹ��������򡢺������***/////////////////////////////////////////////////////////////////////////////////////
void BinaryTree_Print_ByDigui (pBiNode T, int tag)//�ݹ�Ч�ʵ͡�ռ��ջ�ڴ���׶��Բ
{                                                 //ֻ�ʺ�����һ�ּ�˼�룬���ʺ����㷨
	if (tag==1)//�������
	{
		if (T==NULL)
		return;
		printf ("%c", T->data);
		BinaryTree_Print_ByDigui (T->Lchild, 1);
		BinaryTree_Print_ByDigui (T->Rchild, 1);
	}

	if (tag==2)//�������
	{
	if (T==NULL)
		return;
		BinaryTree_Print_ByDigui (T->Lchild, 2);
		printf ("%c", T->data);
		BinaryTree_Print_ByDigui (T->Rchild, 2);
	}

	if (tag==3)//�������
	{
	if (T==NULL)
		return;
		BinaryTree_Print_ByDigui (T->Lchild, 3);
		BinaryTree_Print_ByDigui (T->Rchild, 3);
		printf ("%c", T->data);
	}
}

/***���в��򷨱����������������***/
void BinaryTree_Print_ByQueue (pBiNode T, bool boolean)
{
  
	pLqueue plqueue;
	queue<pBiNode>queue_list;

	plqueue = Queue_Init ();//��ʼ������
	Queue_In (plqueue, T);
	if (boolean)
	{
		while (!Queue_isEmpty (&plqueue))
		{
			T = Queue_Out (&plqueue);
			printf ("%c", T->data);
			if (T->Lchild!=NULL)//������Ů������ŮΪ"��"ʱ�Ͳ�������
			Queue_In (plqueue, T->Lchild);//����Ů���
			if (T->Rchild!=NULL)//ע��������������
			Queue_In (plqueue, T->Rchild);//����Ů���

		}
	}

	if (!boolean)//STLʵ��
	{
		queue_list.push (T);
		while (!queue_list.empty())
		{
			T = queue_list.front();
			queue_list.pop();
			printf ("%c", T->data);
			if (T->Lchild!=NULL)//������Ů������ŮΪ"��"ʱ�Ͳ�������
			queue_list.push (T->Lchild);//����Ů���
			if (T->Rchild!=NULL)
			queue_list.push (T->Rchild);//����Ů���
		}
	}
}

/***��ǳ�ʼ��***/
void BinaryTree_Init(pBiNode T)
{
 if (T==NULL)
	 return ;
 T->mark = false;
 BinaryTree_Init(T->Lchild);
 BinaryTree_Init(T->Rchild);

}

/***ջ�������򡢺�������������������***/
void BinaryTree_Print_ByStack (pBiNode T, int tag, bool boolean)
{
	pStack pstack;
	stack<pBiNode>stack_list;

	pstack = Stack_Init ();//ջ��ʼ��
	if (boolean)
	{
		if (tag==1)//�������
		{
			while (T!=NULL)//ע��������������
			{
				while (T!=NULL)
				{
                    printf ("%c", T->data);
                    if (T->Rchild!=NULL)
                    Stack_Push (pstack, T->Rchild);
                    T = T->Lchild;
				}
				T = Stack_Pop (&pstack);
            }
        }

		if (tag==2)
		{
			while (!Stack_isEmpty (&pstack) || T!=NULL)///������������˼(ֻ�����,�����Դ�)
			{
				while (T!=NULL)
				{
					Stack_Push (pstack, T);
					T = T->Lchild;
				}
				if (!Stack_isEmpty (&pstack))
				{
				T = Stack_Pop (&pstack);
				printf ("%c",T->data);
				T = T->Rchild;
				}
			}
		}

		if (tag==3)
		{

			while (T!=NULL)
			{

             Stack_Push(pstack,T);///����Ů���ν�ջ
			 T = T->Lchild;
			}

			while (!Stack_isEmpty(&pstack))
			{

            T = Stack_GetTop(pstack);
			if (T->Rchild==NULL || T->Rchild->mark)///Tû������Ů��������Ů�Ѿ������ʵ�
			{
             printf ("%c", T->data);
			 T->mark = true;
			 Stack_Pop(&pstack);
			}
			else
			{
             T = T->Rchild;
			 while (T!=NULL)
			 {
              Stack_Push(pstack,T);
			  T = T->Lchild;
			 }

			}

			}
		}
	}

    if (!boolean)
    {
                if (tag==1)
                {
                    while (T!=NULL)
                    {
                        while (T!=NULL)
                        {
                            printf ("%c", T->data);
                            if (T->Rchild!=NULL)///�˴�����������ж������ſ�����ջ
                            stack_list.push (T->Rchild);
                            T = T->Lchild;
                        }
                        if (!stack_list.empty())
                        {
                            T = stack_list.top();
                            stack_list.pop();
                        }
                    }
                }

            if (tag==2)
            {
                while (!stack_list.empty() || T!=NULL)///������������˼(ֻ�����,�����Դ�)
                {
                    while (T!=NULL)
                    {
                        stack_list.push (T);
                        T = T->Lchild;
                    }
                    if (!stack_list.empty())
                    {
                        T = stack_list.top();
                        stack_list.pop();
                        printf ("%c",T->data);
                        T = T->Rchild;
                    }
                }
            }

            if (tag==3)///�������
            {

                while (T!=NULL)
                {

                 stack_list.push(T);///����Ů���ν�ջ
                 T = T->Lchild;
                }

                while (!stack_list.empty())
                {

                    T = stack_list.top();
                    if (T->Rchild==NULL || T->Rchild->mark)///Tû������Ů��������Ů�Ѿ������ʵ�
                    {
                         printf ("%c", T->data);
                         T->mark = true;
                         stack_list.pop();
                    }
                    else
                    {
                         T = T->Rchild;
                         while (T!=NULL)
                         {
                             stack_list.push(T);
                             T = T->Lchild;
                         }
                    }
                }
            }
        }
}

/***��ʼ����ջ***/
pStack Stack_Init ()///��ͷ������ջ
{
	pStack pstack = new Stack();///ע��˴����ڶ���������ڴ棬����ִ����󲻻ᱻ��������Կ��Է��ص�ַ
	pstack->next = NULL;

	return pstack;

}

/***�ж��Ƿ�Ϊ��ջ***/
bool Stack_isEmpty (pStack* ppstack)
{
	if ((*ppstack)->next==NULL)
		return true;
	return false;
}

/***ȡ��ջ��Ԫ��***/
pBiNode Stack_GetTop (pStack pstack)
{
if (pstack->next==NULL)
return NULL;
return pstack->next->data;
}

/***ѹջ***/
void Stack_Push (pStack pstack,pBiNode element)///ѹջ����Ҫ�Ա�ָ�������ֻ��Ҫѹ�뼴��
{
	pStack p1;
    p1 = new Stack();
	p1->data = element;
	p1->next = pstack->next;
	pstack->next = p1;
}

///��ջʱ����Ҫ�Ա�ָ����в�������Ϊ����top����ͷ��㣬��ջʱͷ��������ʱ�ı�
pBiNode Stack_Pop (pStack* ppstack)
{
	if (!Stack_isEmpty(ppstack))
	{
	pStack temp = (*ppstack)->next;
	(*ppstack)->next = temp->next;
	pBiNode p1 =temp->data;
	delete temp;
	return p1;               ///��ջʱ����top���Ķ�������ַ
	}
	else
	return NULL;
}

/***�ͷ���ջ�ռ�***
void Stack_Destroy (pStack pstack)//�˴�ֻҪ�ͷ�ָ�������ָ�빲�õ��ڴ漴�ɣ����öԱ�ָ��������
{
	pStack temp;
	while (pstack!=NULL)
	{
		temp = pstack;
		pstack = pstack->next;
		delete temp;
		temp = NULL;
	}
}*/

/***��ʼ��������***/
pLqueue Queue_Init ()//��ͷ����������,��ʼ��ʱһ��Ҫ�����׵�ַ
{
	pLqueue plqueue = new Lqueue();
	plqueue->front =new Queue();
	plqueue->front->next = NULL;
	plqueue->rear = plqueue->front;

	return plqueue;//�������ڴ�ĵ�ַ����ʱ��������ֵ��ֵ��ɺ���ʱ�����ᱻ�������Ż����������̬������ڴ���Ȼ����
}

/***�ж��������Ƿ�Ϊ��***/
bool Queue_isEmpty (pLqueue* pplqueue)
{
	if ((*pplqueue)->front==(*pplqueue)->rear)
		return true;
	return false;
}

/***�����***/
void Queue_In (pLqueue plqueue, pBiNode element)//����в���Ҫ�Ա�ָ�����
{
    plqueue->rear->next = new Queue;
	plqueue->rear = plqueue->rear->next;
	plqueue->rear->data = element;
	plqueue->rear->next = NULL;
}

/***������***/
pBiNode Queue_Out (pLqueue* pplqueue)
{
	pBiNode p1;
	if (!Queue_isEmpty (pplqueue))
	{
	pQueue temp = (*pplqueue)->front->next;
	(*pplqueue)->front->next = temp->next;
	if ((*pplqueue)->front->next == NULL)//�˴�һ��Ҫ�жϷ���ֻ��һ����㲢�ҳ�����ʱppqueue->rear�ᱻɾ��
    (*pplqueue)->rear = (*pplqueue)->front;
	p1 = temp->data;
	delete temp;
	temp = NULL;

	return p1;
	}
	else
	return NULL;

}
/*ֻҪͨ�����ظ�ֵ���޷���ԭָ����в�����How?)
pBiNode* Queue_Out (pLqueue* pplqueue, bool boolean)//���س����к�����ֻΪ����������ʱ�����Ҷ�ڵ�����ҽ��������
{

	if (!Queue_isEmpty (pplqueue))
	{
	pQueue temp = (*pplqueue)->front->next;
	(*pplqueue)->front->next = temp->next;
	if ((*pplqueue)->front->next == NULL)//�˴�һ��Ҫ�жϷ���ֻ��һ����㲢�ҳ�����ʱppqueue->rear�ᱻɾ��
    (*pplqueue)->rear = (*pplqueue)->front;
	delete temp;
	temp = NULL;

	return &((*pplqueue)->front->next->data);//��ԭָ��������
	}
	else
	return NULL;

}
*/
/*
***�ͷ������пռ�***
void Queue_Destroy (pLqueue plqueue)
{
	pQueue temp;
	while (plqueue->front!=NULL)
	{
		temp = plqueue->front;
		plqueue->front = plqueue->front->next;
		delete temp;
	}
}*/
