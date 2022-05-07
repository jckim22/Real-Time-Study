/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct RBTnode {
	struct RBTnode* parent;
	struct RBTnode* left;
	struct RBTnode* right;
	int data;
	enum {RED,BLACK} color;


}RBT;
RBT* createNode(int data) {
	RBT* newNode = (RBT*)malloc(sizeof(RBT*));
	
	newNode->parent = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	newNode->color = BLACK;

	return newNode;
}

int main() {

}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef int Elementtype;

typedef struct tagRBTNode {
	struct tagRBTNode* right;
	struct tagRBTNode* left;
	struct tagRBTNode* parent;
	Elementtype data;
	enum { Red, Black } color;
}RBTNode;

static RBTNode* Nil;

RBTNode* RBTSearchNode(RBTNode* Tree, Elementtype Target)
{
	if (Tree == Nil)
	{
		return Nil;
	}
	if (Tree->data > Target)
	{
		return RBTSearchNode(Tree->left, Target);
	}
	else if (Tree->data < Target)
	{
		return RBTSearchNode(Tree->right, Target);
	}
	else {
		return Tree;
	}
}
RBTNode* RBTSearchminNode(RBTNode* Tree)
{
	if (Tree == Nil)
	{
		return Nil;
	}
	if (Tree->left == Nil)
	{
		return Tree;
	}
	else
	{
		return RBTSearchminNode(Tree->left);
	}
}
RBTNode* RBTCreateNode(Elementtype newdata)
{
	RBTNode* Newnode = (RBTNode*)malloc(sizeof(RBTNode));
	Newnode->parent = NULL;
	Newnode->right = NULL;
	Newnode->left = NULL;
	Newnode->data = newdata;
	Newnode->color = Black;

	return Newnode;
}
void RBTInsertNodeHelper(RBTNode** Tree, RBTNode* Newnode)
{
	if (*Tree == NULL)
	{
		*Tree = Newnode;
	}
	if ((*Tree)->data < Newnode->data)
	{
		if ((*Tree)->right == Nil)
		{
			(*Tree)->right = Newnode;
			Newnode->parent = *Tree;
		}
		else {
			RBTInsertNodeHelper(&(*Tree)->right, Newnode);
		}
	}
	else if ((*Tree)->data > Newnode->data)
	{
		if ((*Tree)->left == Nil)
		{
			(*Tree)->left = Newnode;
			Newnode->parent = *Tree;
		}
		else {
			RBTInsertNodeHelper(&(*Tree)->left, Newnode);
		}
	}
}
void RBTRotateRight(RBTNode** root, RBTNode* parent)
{
	RBTNode* leftChild = parent->left;

	parent->left = leftChild->right;

	if (leftChild->right != Nil)
		leftChild->right->parent = parent;

	leftChild->parent = parent->parent;

	if (parent->parent == NULL)
		(*root) = leftChild;
	else
	{
		if (parent == parent->parent->left)
			parent->parent->left = leftChild;
		else
			parent->parent->right = leftChild;
	}
	leftChild->right = parent;
	parent->parent = leftChild;
}
void RBTRotateLeft(RBTNode** root, RBTNode* parent)
{
	RBTNode* rightChild = parent->right;

	parent->right = rightChild->left;

	if (rightChild->left != Nil)
		rightChild->left->parent = parent;

	rightChild->parent = parent->parent;

	if (parent->parent == NULL)
		(*root) = rightChild;
	else
	{
		if (parent == parent->parent->right)
			parent->parent->right = rightChild;
		else
			parent->parent->left = rightChild;
	}
	rightChild->left = parent;
	parent->parent = rightChild;
}

void RBTRebuildAfterInsert(RBTNode** root, RBTNode* node)
{
	
	while (node != (*root) && node->parent->color == Red)
	{
		if (node->parent == node->parent->parent->left)
		{
	
			RBTNode* uncle = node->parent->parent->right;
			if (uncle->color == Red)
			{
	
				node->parent->color = Black;
				uncle->color = Black;
				node->parent->parent->color = Red;
				node = node->parent->parent;
			}
			else
			{
	
				if (node == node->parent->right)
				{
					node = node->parent;
					RBTRotateLeft(root, node);
				}
				node->parent->color = Black;
				node->parent->parent->color = Red;
				RBTRotateRight(root, node->parent->parent);
			}
		}
		else 
		{
			
			RBTNode* uncle = node->parent->parent->left;
			if (uncle->color == Red)
			{
			
				node->parent->color = Black;
				uncle->color = Black;
				node->parent->parent->color = Red;
			}
			else
			{
			
				if (node == node->parent->left)
				{
					node = node->parent;
					RBTRotateRight(root, node);
				}
				node->parent->color = Black;
				node->parent->parent->color = Red;
				RBTRotateLeft(root, node->parent->parent);
			}
		}
	}
	(*root)->color = Black;
}
void RBTInsertNode(RBTNode** Tree, RBTNode* Newnode)
{
	RBTInsertNodeHelper(Tree, Newnode);
	Newnode->color = Red;
	Newnode->right = Nil;
	Newnode->left = Nil;
	RBTRebuildAfterInsert(Tree, Newnode);
}


void RBTRebuildAfterRemove(RBTNode** root, RBTNode* Successor)
{
	RBTNode* Sibling = NULL;
	while (Successor->parent != NULL && Successor->color == Black)
	{
		if (Successor == Successor->parent->left)
		{
			Sibling = Successor->parent->right;
			if (Sibling->color == Red)
			{
				Sibling->color = Black;
				Successor->parent->color = Red;
				RBTRotateLeft(root, Successor->parent);
				Sibling = Successor->parent->right;
			}
			else
			{
				if (Sibling->left->color == Black && Sibling->right->color == Black)
				{
					Sibling->color = Red;
					Successor = Successor->parent;
				}
				else
				{
					if (Sibling->left->color == Red)
					{
						Sibling->left->color = Black;
						Sibling->color = Red;
					}
					RBTRotateRight(root, Sibling);
					Sibling = Successor->parent->right;
				}
				Sibling->color = Successor->parent->color;
				Successor->parent->color = Black;
				Sibling->right->color = Black;
				RBTRotateLeft(root, Successor->parent);
				Successor = (*root);
			}
		}
		else
		{
			Sibling = Successor->parent->left;
			if (Sibling->color == Red)
			{
				Sibling->color = Black;
				Successor->parent->color = Red;
				RBTRotateRight(root, Successor->parent);
				Sibling = Successor->parent->left;
			}
			else {
				if (Sibling->color == Black && Sibling->left->color == Black)
				{
					Sibling->color = Red;
					Successor = Successor->parent;
				}
				else
				{
					if (Sibling->right->color == Red)
					{
						Sibling->right->color = Black;
						Sibling->color = Red;
						RBTRotateLeft(root, Sibling);
						Sibling = Successor->parent->left;
					}
					Sibling->color = Successor->parent->color;
					Successor->parent->color = Black;
					Sibling->left->color = Black;
					RBTRotateRight(root, Successor->parent);
					Successor = (*root);
				}
			}
		}
	}
	Successor->color = Black;
}

void RBTprintTree(RBTNode* Node, int depth, int blackcount)
{
	int i = 0;
	char c = 'X';
	int v = -1;
	char cnt[100];
	if (Node == NULL || Node == Nil)
	{
		return;
	}
	if (Node->color == Black)
	{
		blackcount++;
	}
	if (Node->parent != NULL)
	{
		v = Node->parent->data;
		if (Node->parent->left == Node)
		{
			c = 'L';
		}
		else {
			c = 'R';
		}
	}
	if (Node->left == Nil && Node->right == Nil)
	{
		sprintf(cnt, "--------- %d", blackcount);
	}
	else
	{
		sprintf(cnt, "");
	}
	for (i = 0; i < depth; i++)
	{
		printf(" ");
	}
	printf("%d %s[%c, %d] %s\n", Node->data, (Node->color == Red) ? "Red" : "Black", c, v, cnt);
	RBTprintTree(Node->left, depth + 1, blackcount);
	RBTprintTree(Node->right, depth + 1, blackcount);
}

int main()
{
	RBTNode* Tree = NULL;
	RBTNode* Node = NULL;
	Nil = RBTCreateNode(0);
	Nil->color = Black;
	while (1)
	{
		int cmd = 0;
		int param = 0;
		char buffer[10];
		printf("Enter Commend : \n");
		printf("(1) Create a Node, (2) Search a Node\n");
		printf("(3) Display Tree, (4) quit\n");
		printf("commend number: ");
		fgets(buffer, sizeof(buffer) - 1, stdin);
		sscanf(buffer, "%d", &cmd);

		if (cmd < 1 || cmd >5)
		{
			printf("Invalid commend number.\n");
			continue;
		}
		else if (cmd == 3)
		{
			RBTprintTree(Tree, 0, 0);
			printf("\n");
			continue;
		}
		else if (cmd == 4) {
			break;
		}
		printf("Enter parameter (1~200) : \n");
		fgets(buffer, sizeof(buffer - 1), stdin);
		sscanf(buffer, "%d", &param);
		if (param < 1 || param >200)
		{
			printf("Invalid parameter. %d\n", param);
			continue;
		}
		switch (cmd)
		{
		case 1:
			RBTInsertNode(&Tree, RBTCreateNode(param));
			break;
		case 2:
			Node = RBTSearchNode(Tree, param);
			if (Node == NULL)
			{
				printf("Not Found node : %d\n", param);
			}
			else
			{
				printf("Found node : %d(Color: %s)\n", Node->data, (Node->color == Red) ? "Red" : "Black");
			}
			break;
		}
		printf("\n");
	}
	return 0;
}