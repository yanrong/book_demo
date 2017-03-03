/********************************************************************************************************
*Copyright (c++) by xihua_university
*All Rights Reserved
*
*Filename:二叉树先序遍历、中序遍历、后序遍历、层序遍历的递归与非递归算法自定义函数与STL标准模板类的实现.cpp
*Function:二叉树先序遍历、中序遍历、后序遍历、层序遍历的递归与非递归算法自定义函数与STL标准模板类的实现
*Debugging Evironment:visul studio 2012
*Auther:何晏波
*Final:2013,10,30
*********************************************************************************************************/
#include<iostream>
#include<stack>
#include<queue>
#include<ctime>
using namespace std;
const int MAXLENGTH = 100;
typedef struct bnode//二叉树结点
{
	bool mark;
	char data;
    bnode* Lchild;
	bnode* Rchild;
}BiNode, *pBiNode;

typedef struct Stack//栈
{
	pBiNode data;
	Stack* next;
} Stack, *pStack;

typedef struct Queue//队列
{
	pBiNode  data;
	Queue* next;
}Queue, *pQueue;

typedef struct //队列首尾指针
{
	pQueue front;
	pQueue rear;
} Lqueue, *pLqueue;

//////////////////////////////////////////////////////
pStack Stack_Init ();//栈初始化
bool Stack_isEmpty (pStack* ppstack);//判断栈是否为空
void Stack_Push (pStack pstack, pBiNode element);//压栈
pBiNode Stack_GetTop (pStack pstack);//取得栈顶元素
pBiNode Stack_Pop (pStack* ppstack);//出栈
//void Stack_Destroy (pStack pstack);//释放链栈空间

pLqueue Queue_Init ();//队列初始化
bool Queue_isEmpty (pLqueue* pplqueue);//判断是否为空队列
void Queue_In (pLqueue plqueue, pBiNode element);//入队列
pBiNode Queue_Out (pLqueue* pplqueue);//出队列
//pBiNode* Queue_Out (pLqueue* pplqueue, bool boolean);//重载出队列函数,后面参数无实际意义
//void Queue_Destroy (pLqueue plqueue);//释放链队列空间

int CountBinary (pBiNode T);//计算结点总数
int CountBinaryLeaf (pBiNode T);//计算叶节点数
int CountBinaryHeigh (pBiNode T);//计算树高
pBiNode BinaryTree_Create ();//层序法创建完全二叉树
void BinaryTree_Print_ByDigui (pBiNode T, int tag);//递归先序、中序、后序遍历
void BinaryTree_Print_ByQueue (pBiNode T, bool boolean);//队列层序法遍历输出二叉树内容，可选择是自定义函数实现还是STL
void BinaryTree_Init(pBiNode pbinode);//标记初始化
void BinaryTree_Print_ByStack (pBiNode T, int tag, bool boolean);//栈先序、中序、后序、遍历输出二叉树内容，可选择是自定义函数实现还是STL
////////////////////////////////////////////////////
int main()
{
	long start_time, end_time;//记录各种遍方法历所花时间
	pBiNode root;


	system("color 1e");
	printf ("请输入有一串字符，以0结束\n");
    root = BinaryTree_Create ();//用自定义函数创建
	//root = BinaryTree_Create_ByQueue (false);//用STL函数创建
	//递归遍历
    printf ("该二叉树一共有%d个结点\n", CountBinary(root));
    printf ("该二叉树一共有%d个叶结点\n", CountBinaryLeaf(root));
	printf ("该二叉树的深度为%d\n", CountBinaryHeigh(root));
	printf ("(1)递归先序遍历读取内容如下:\n");//递归先序遍历
	start_time = clock();
	BinaryTree_Print_ByDigui (root, 1);
	end_time = clock();
	printf ("\n所用时间为:%d毫秒\n\n", end_time-start_time);

	printf ("(2)递归中序遍历读取内容如下:\n");//递归中序遍历
	start_time = clock();
	BinaryTree_Print_ByDigui (root, 2);
	end_time = clock();
	printf ("\n所用时间为:%d毫秒\n\n", end_time-start_time);

	printf ("(3)递归后序遍历读取内容如下:\n");//递归后序遍历
	start_time = clock();
	BinaryTree_Print_ByDigui (root, 3);
	end_time = clock();
	printf ("\n所用时间为:%d毫秒\n\n", end_time-start_time);
	//非递归遍历
	printf ("(4)队列层序遍历读取内容如下:\n");//队列层序遍历
	start_time = clock();
	BinaryTree_Print_ByQueue (root, true);
	end_time = clock();
	printf ("\n所用时间为:%d毫秒\n\n", end_time-start_time);

	printf ("(5)队列层序STL遍历读取内容如下:\n");//队列层序法STL实现
	start_time = clock();
	BinaryTree_Print_ByQueue (root, false);
	end_time = clock();
	printf ("\n所用时间为:%d毫秒\n\n", end_time-start_time);

	printf ("(6)栈先序遍历读取内容如下:\n");//栈先序遍历
	start_time = clock();
	BinaryTree_Print_ByStack (root, 1, true);
	end_time = clock();
	printf ("\n所用时间为:%d毫秒", end_time-start_time);

	printf ("\n\n(7)栈中序遍历读取内容如下:\n");//栈中序遍历
	start_time = clock();
	BinaryTree_Print_ByStack (root, 2, true);
	end_time = clock();
	printf ("\n所用时间为:%d毫秒", end_time-start_time);

	printf ("\n\n(8)栈后序遍历读取内容如下:\n");//栈后序遍历
	start_time = clock();
	BinaryTree_Print_ByStack (root, 3, true);
	end_time = clock();
	printf ("\n所用时间为:%d毫秒", end_time-start_time);

	printf ("\n\n(9)栈先序STL遍历读取内容如下:\n");//栈STL先序遍历
	start_time = clock();
	BinaryTree_Print_ByStack (root, 1, false);
	end_time = clock();
	printf ("\n所用时间为:%d毫秒", end_time-start_time);

	printf ("\n\n(10)栈中序STL遍历读取内容如下:\n");//栈STL中序遍历
	start_time = clock();
	BinaryTree_Print_ByStack (root, 2, false);
	end_time = clock();
	printf ("\n所用时间为:%d毫秒", end_time-start_time);

	BinaryTree_Init(root);
	printf ("\n\n(11)栈后序STL遍历读取内容如下:\n");//栈STL后序遍历
	start_time = clock();
	BinaryTree_Print_ByStack (root, 3, false);
	end_time = clock();
	printf ("\n所用时间为:%d毫秒\n", end_time-start_time);

	return 0;
}

/***计算结点总数***/
int CountBinary (pBiNode T)//先序遍历计数
{
	pStack pstack;
	int count(0);


    pstack = Stack_Init ();//栈初始化
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

/***计算叶节点数***/

int CountBinaryLeaf (pBiNode T)//中序遍历计算叶节点数
{
pStack pstack;
int count(0);

pstack = Stack_Init ();//栈初始化
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

/***计算树高***/
int CountBinaryHeigh (pBiNode T)
{
    pLqueue plqueue;
	pBiNode temp(T);
	int depth(0), visited_unmber(0), queuein_number(0), last_visited_number(0);//visited_unmber(已经访问过的结点数)、queuein_number(已经进队列的结点数)
                                                            //last_visited_number(该层最后一个要访问的结点数)、depth(二叉树高)

    plqueue = Queue_Init();//初始化队列
    if (temp!=NULL)
	{
     Queue_In(plqueue,temp);
     ++queuein_number;//进队列结点数加1
     last_visited_number = queuein_number;//设置最后一个要访问的结点数
	 while (!Queue_isEmpty(&plqueue))
	 {
      temp = Queue_Out(&plqueue);
	  ++visited_unmber;//访问结点数加1
      if (temp->Lchild!=NULL)//如果有左孩子则进队列
	  {
		  Queue_In(plqueue,temp->Lchild);
          ++queuein_number;//进队列结点数加1
	  }
      if (temp->Rchild!=NULL)//如果有右孩子则进队列
	  {
       Queue_In(plqueue,temp->Rchild);
       ++queuein_number;//进队列结点数加1
	  }
      if (last_visited_number==visited_unmber)//执行到此说明上一层已经访问完毕
	  {                                       //depth深度加1，并且修正最后一个要访问的结点数

     ++depth;
     last_visited_number = queuein_number;
	 }

	 }
	}
	 return depth;

}

/***层序法创建完全二叉树***////////////////////////////////////////////////////////////////////////////
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
          if (T!=NULL && temp[front]!=NULL)//如果父母与子女都存在则插入子女
		  {
            if (rear%2==0)//根据完全二叉树的特点左子女为偶数
				temp[front]->Lchild = T;
			else//根据完全二叉树的特点右子女为奇数
				temp[front]->Rchild = T;
		  }
		  if (rear%2==1)//已经处理完了，fornt加1下一个结点作父母
		      front++;
		 }
		  c = getchar();
	 }
	return root;

	 }

/***递归先序、中序、后序遍历***/////////////////////////////////////////////////////////////////////////////////////
void BinaryTree_Print_ByDigui (pBiNode T, int tag)//递归效率低、占用栈内存大、易读性差，
{                                                 //只适合描述一种简单思想，不适合做算法
	if (tag==1)//先序输出
	{
		if (T==NULL)
		return;
		printf ("%c", T->data);
		BinaryTree_Print_ByDigui (T->Lchild, 1);
		BinaryTree_Print_ByDigui (T->Rchild, 1);
	}

	if (tag==2)//中序输出
	{
	if (T==NULL)
		return;
		BinaryTree_Print_ByDigui (T->Lchild, 2);
		printf ("%c", T->data);
		BinaryTree_Print_ByDigui (T->Rchild, 2);
	}

	if (tag==3)//后序输出
	{
	if (T==NULL)
		return;
		BinaryTree_Print_ByDigui (T->Lchild, 3);
		BinaryTree_Print_ByDigui (T->Rchild, 3);
		printf ("%c", T->data);
	}
}

/***队列层序法遍历输出二叉树内容***/
void BinaryTree_Print_ByQueue (pBiNode T, bool boolean)
{
  
	pLqueue plqueue;
	queue<pBiNode>queue_list;

	plqueue = Queue_Init ();//初始化队列
	Queue_In (plqueue, T);
	if (boolean)
	{
		while (!Queue_isEmpty (&plqueue))
		{
			T = Queue_Out (&plqueue);
			printf ("%c", T->data);
			if (T->Lchild!=NULL)//当左子女或右子女为"空"时就不再入列
			Queue_In (plqueue, T->Lchild);//左子女入队
			if (T->Rchild!=NULL)//注意条件次序问题
			Queue_In (plqueue, T->Rchild);//右子女入队

		}
	}

	if (!boolean)//STL实现
	{
		queue_list.push (T);
		while (!queue_list.empty())
		{
			T = queue_list.front();
			queue_list.pop();
			printf ("%c", T->data);
			if (T->Lchild!=NULL)//当左子女或右子女为"空"时就不再入列
			queue_list.push (T->Lchild);//左子女入队
			if (T->Rchild!=NULL)
			queue_list.push (T->Rchild);//右子女入队
		}
	}
}

/***标记初始化***/
void BinaryTree_Init(pBiNode T)
{
 if (T==NULL)
	 return ;
 T->mark = false;
 BinaryTree_Init(T->Lchild);
 BinaryTree_Init(T->Rchild);

}

/***栈先序、中序、后序输出二叉树结点内容***/
void BinaryTree_Print_ByStack (pBiNode T, int tag, bool boolean)
{
	pStack pstack;
	stack<pBiNode>stack_list;

	pstack = Stack_Init ();//栈初始化
	if (boolean)
	{
		if (tag==1)//先序遍历
		{
			while (T!=NULL)//注意条件次序问题
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
			while (!Stack_isEmpty (&pstack) || T!=NULL)///体会此条件的意思(只可意会,不可言传)
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

             Stack_Push(pstack,T);///左子女依次进栈
			 T = T->Lchild;
			}

			while (!Stack_isEmpty(&pstack))
			{

            T = Stack_GetTop(pstack);
			if (T->Rchild==NULL || T->Rchild->mark)///T没有有子女或者有子女已经被访问掉
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
                            if (T->Rchild!=NULL)///此处必须有这个判定条件才可以入栈
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
                while (!stack_list.empty() || T!=NULL)///体会此条件的意思(只可意会,不可言传)
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

            if (tag==3)///后序遍历
            {

                while (T!=NULL)
                {

                 stack_list.push(T);///左子女依次进栈
                 T = T->Lchild;
                }

                while (!stack_list.empty())
                {

                    T = stack_list.top();
                    if (T->Rchild==NULL || T->Rchild->mark)///T没有有子女或者有子女已经被访问掉
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

/***初始化链栈***/
pStack Stack_Init ()///带头结点的链栈
{
	pStack pstack = new Stack();///注意此处是在堆上申请的内存，函数执行完后不会被清除，所以可以返回地址
	pstack->next = NULL;

	return pstack;

}

/***判断是否为空栈***/
bool Stack_isEmpty (pStack* ppstack)
{
	if ((*ppstack)->next==NULL)
		return true;
	return false;
}

/***取得栈顶元素***/
pBiNode Stack_GetTop (pStack pstack)
{
if (pstack->next==NULL)
return NULL;
return pstack->next->data;
}

/***压栈***/
void Stack_Push (pStack pstack,pBiNode element)///压栈不需要对本指针操作，只需要压入即可
{
	pStack p1;
    p1 = new Stack();
	p1->data = element;
	p1->next = pstack->next;
	pstack->next = p1;
}

///弹栈时必须要对本指针进行操作，因为访问top都是头结点，弹栈时头结点必须随时改变
pBiNode Stack_Pop (pStack* ppstack)
{
	if (!Stack_isEmpty(ppstack))
	{
	pStack temp = (*ppstack)->next;
	(*ppstack)->next = temp->next;
	pBiNode p1 =temp->data;
	delete temp;
	return p1;               ///弹栈时返回top结点的二叉树地址
	}
	else
	return NULL;
}

/***释放链栈空间***
void Stack_Destroy (pStack pstack)//此处只要释放指针与参数指针共用的内存即可，不用对本指针做操作
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

/***初始化链队列***/
pLqueue Queue_Init ()//带头结点的链队列,初始化时一定要返回首地址
{
	pLqueue plqueue = new Lqueue();
	plqueue->front =new Queue();
	plqueue->front->next = NULL;
	plqueue->rear = plqueue->front;

	return plqueue;//返回了内存的地址，临时变量作右值赋值完成后临时变量会被编译器优化清除，而动态申请的内存依然存在
}

/***判断链队列是否为空***/
bool Queue_isEmpty (pLqueue* pplqueue)
{
	if ((*pplqueue)->front==(*pplqueue)->rear)
		return true;
	return false;
}

/***入队列***/
void Queue_In (pLqueue plqueue, pBiNode element)//入队列不需要对本指针操作
{
    plqueue->rear->next = new Queue;
	plqueue->rear = plqueue->rear->next;
	plqueue->rear->data = element;
	plqueue->rear->next = NULL;
}

/***出队列***/
pBiNode Queue_Out (pLqueue* pplqueue)
{
	pBiNode p1;
	if (!Queue_isEmpty (pplqueue))
	{
	pQueue temp = (*pplqueue)->front->next;
	(*pplqueue)->front->next = temp->next;
	if ((*pplqueue)->front->next == NULL)//此处一定要判断否则当只有一个结点并且出队列时ppqueue->rear会被删除
    (*pplqueue)->rear = (*pplqueue)->front;
	p1 = temp->data;
	delete temp;
	temp = NULL;

	return p1;
	}
	else
	return NULL;

}
/*只要通过返回赋值就无法对原指针进行操作（How?)
pBiNode* Queue_Out (pLqueue* pplqueue, bool boolean)//重载出队列函数，只为创建二叉树时方便对叶节点的左右结点做处理
{

	if (!Queue_isEmpty (pplqueue))
	{
	pQueue temp = (*pplqueue)->front->next;
	(*pplqueue)->front->next = temp->next;
	if ((*pplqueue)->front->next == NULL)//此处一定要判断否则当只有一个结点并且出队列时ppqueue->rear会被删除
    (*pplqueue)->rear = (*pplqueue)->front;
	delete temp;
	temp = NULL;

	return &((*pplqueue)->front->next->data);//对原指针做操作
	}
	else
	return NULL;

}
*/
/*
***释放链队列空间***
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
