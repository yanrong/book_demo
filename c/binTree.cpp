#include <stdio.h>
#include <stack>
using std::stack;

typedef int data_t;
typedef struct binary_tree_node_t{
	pbin_tree *lchild,rchild,
	data_t data;
}bin_tree,*pbin_tree;

void pre_order_noncursive(pbin_tree root)
{
	stack<pbin_tree> s_tree;
	pbin_tree ptree = root;
	//if tree is an empty or all node has been visited,exit 
	while(ptree || !s_tree.empty())
	{
		while(ptree)//add all left child to stack and print it.
		{
			std::cout<<ptree->data<<" ";
			/*access root (subtree node,left tree node can be sub-tree's root node)*/
			s_tree.push(ptree);
			ptree = ptree->lchild;//get left child 
		}

		if(!s_tree.empty())
		{
			ptree = s_tree.top();//last left node (the most left leaf)
			s_tree.pop();//discard it,it has been accessed 
			ptree = ptree->rchild;//add right tree to 
		}
	}
}

void pre_order_noncursive_2nd(pbin_tree root)
{
	stack<pbin_tree> s_tree;
	//pbin_tree ptree = root;
	pbin_tree pttree;
	//got root,push into stack as top elements
	s_tree.push(root);
	// if not all node visited 
	while(!s_tree.empty())
	{
		pttree = s_tree.top();
		cout<< pttree->data<< " ";

		s_tree.pop(); //left child has visited, pop it 

		if(pttree->rchild) s_tree.push(pttree->rchild);
		if(pttree->lchild) s_tree.push(pttree->lchild);
	}
}


void in_order_noncursive(pbin_tree root)
{
	stack<pbin_tree> s_tree;
	pbin_tree *ptree = root;

	while(ptree || !s_tree.empty())
	{
		while(ptree) //add all left node to stack
		{
			s_tree.push(ptree);
			ptree = ptree->lchild;
		}

		if(!s_tree.empty()) //if not all tree's node visited
		{
			ptree = s_tree.top(); // the first time,get last node (leaf without two childs)
			cout<< ptree->data<<" "; // access node
			//IMPORTANT!!!!
			/**
			pop the last node(leaf) that has been visited, take the previous left node
			before the last as top elements,that neither doesn't have child, do nothing
			to stack,the process access tree ad inorder

			i got the puzzlement that when whole left tree(or sub-tree)visited,now stack top
			element must be root ,just visited it ,and pop it,and visit right child 
			**/
			s_tree.pop(); // if visited , dicard it
			ptree = ptree->rchild; //whole left tree has been visited, now visited right tree 
		}
	}
}


void post_order_nonrecursive(pbin_tree root)
{
	stack<pbin_tree> s_tree;
	pbin_tree ptree = root;
	pbin_tree previsited = NULL; //previous node that has been visited

	while(ptree || !s_tree.empty())
	{
		while(ptree) // add whole left sub-tree
		{
			s_tree.push(ptree);
			ptree = ptree->lchild;
		}

		ptree = s_tree.top(); // get top that same as most left node(leaf)

		//if node's right child is vold or has been visited,visited it (inorder rule)
		if(!ptree->rchild || ptree->rchild == previsited)
		{
			cout<< ptree->data<<" ";
			previsited = ptree;

			s_tree.pop();
			ptree = NULL;
		}
		else pttree = ptree->rchild;
	}
}

void post_order_nonrecursive(pbin_tree root) //using two stack 
{
	stack<pbin_tree> s_tree1 s_tree2;
	pbin_tree ptree ;
	s_tree1.push(root); //add root to stack ,make sure root is last visited when pop stack
	while(!s_tree1.empty())
	{
		ptree = s_tree1.top(); //s_tree1 hold left child
		s_tree1.pop(); // pop right child 

		s_tree2.push(ptree); //s_tree2 hold right child 
		/*
		1.Push the root node to the first stack.
		2.Pop a node from the first stack, and push it to the second stack.
		3.Then push its left child followed by its right child to the first stack.
		4.Repeat step 2) and 3) until the first stack is empty.
		5.Once done, the second stack would have all the nodes ready to be traversed
 		in post-order. Pop off the nodes from the second stack one by one and you’re done.
		*/
		if(ptree->lchild) s_tree1.push(ptree->lchild);
		if(ptree->rchild) s_tree1.push(ptree->rchild);
	}

	while(!s_tree2.empty())
	{
		cout<<s_tree2.top()->data<<" ";
		s_tree2.pop();
	}
}

void level_order(pbin_tree broot)
{
	pbin_tree queue[100];//queue for storage
	pbin_tree root = broot;
	if(!root) return;

	int front=rear=0;
	//add root in queue head
	queue[rear++] = root;

	while(front != root) //if queue is not full
	{
		cout<<queue[front]->data<<" "; //access queue front data
		if(queue[front]->lchild)  //if left child is exited, push at the end
		{
			queue[rear++] = queue[front]->lchild;
		}
		if(queue[front]->rchild) // the same operation to right child
		{
			queue[rear++] = queue[front]->rchild;
		}
		//we access front and add it's two child,dicard it
		front++;
	}
}


int depth_tree(pbin_tree root)
{
	//actually got bigger bwtween left and right height, puls root(1).
	return (depth_tree(root->lchild) > depth_tree(root->rchild)?
	?depth_tree(root->lchild):depth_tree(root->rchild))+1;
}