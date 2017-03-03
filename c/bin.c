typedef struct Bitree
{
	char data;
	struct Bitree *lchild, *rchild;
}Bitree;

// 新节点
Bitree *new(char data)
{
	Bitree *a = (Bitree *)malloc(sizeof(Bitree));
	a->data = data;
	a->lchild = NULL;
	a->rchild = NULL;
	return a;
}

// 中序遍历二叉树的递归算法
void inorder(Bitree *t)
{
	if (t)
	{
		inorder(t->lchild);
		printf("%c ", t->data);
		inorder(t->rchild);
	}
}

// 前序遍历二叉树的递归算法
void preorder(Bitree *t)
{
	if (t)
	{
		printf("%c ", t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

// 后序遍历二叉树的递归算法
void postorder(Bitree *t)
{
	if (t)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("%c ", t->data);
	}
}


// 前序遍历二叉树的非递归算法
void preorder2(Bitree *t)
{
	Bitree *s[32];	// s是指针数组，数组中元素为二叉树节点的指针
	int top = -1;
	while (t!=NULL || top != -1)
	{
		// 压栈直到左子树为空
		while (t != NULL)
		{
			printf("%c ", t->data);
			s[++top] = t;
			t = t->lchild;
		}
		if (top != -1)
		{
			t = s[top--];	// 出栈
			t = t->rchild;	// 指向该节点的右孩子，回到while循环压栈
		}
	}
}

// 中序遍历二叉树的非递归算法
void inorder2(Bitree *t)
{
	Bitree *s[32];	// s是指针数组，数组中元素为二叉树节点的指针
	int top = -1;
	while (t!=NULL || top != -1)
	{
		// 压栈直到左子树为空
		while (t != NULL)
		{
			s[++top] = t;
			t = t->lchild;
		}
		if (top != -1)
		{
			t = s[top--];	// 出栈
			printf("%c ", t->data);
			t = t->rchild;	// 指向该节点的右孩子，回到while循环压栈
		}
	}
}

// 后序遍历二叉树的非递归算法
void postorder2(Bitree *t)
{
	Bitree *s[32];	// s是指针数组，数组中元素为二叉树节点的指针
	int tag[32];	// s中相对位置的元素的tag: 0或1
	int top = -1;
	while (t!=NULL || top != -1)
	{
		// 压栈直到左子树为空
		while (t != NULL)
		{
			s[++top] = t;
			tag[top] = 0;
			t = t->lchild;
		}
		// 当栈非空，并且栈顶元素tag为1时，出栈并访问
		while (top!=-1 && tag[top]==1)
		{
			printf("%c ", s[top--]->data);
		}
		// 当栈非空时，将栈顶tag置1，并指向栈顶元素的右孩子
		if (top != -1)
		{
			tag[top] = 1;
			t = s[top]->rchild;
		}
	}
}

int main()
{
	// 申请空间构造一棵二叉树
	Bitree *a = new('A');
	Bitree *b = new('B');
	Bitree *c = new('C');
	Bitree *d = new('D');
	Bitree *e = new('E');
	Bitree *f = new('F');
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	c->rchild = f;

	// 递归算法
	printf("preorder: ");
	preorder(a);
	printf("/n");
	
	printf("inorder: ");
	inorder(a);
	printf("/n");
		
	printf("postorder: ");
	postorder(a);
	printf("/n");
	
	printf("/n");
	
	// 非递归算法
	printf("preorder2: ");
	preorder2(a);
	printf("/n");
	
	printf("inorder2: ");
	inorder2(a);
	printf("/n");
	
	printf("postorder2: ");
	postorder2(a);
	printf("/n");
	
	free(a); free(b); free(c); free(d); free(e); free(f);
	
	return 0;
}