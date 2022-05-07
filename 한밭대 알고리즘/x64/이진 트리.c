#include <stdio.h>
#include <malloc.h>
#include <malloc.h>

typedef struct BST_node {

	struct BST_node* left;
	struct BST_node* right;
	int key;


} BST_node;


BST_node* createNode(int newKey) {
	BST_node* new_node = (BST_node*)malloc(sizeof(BST_node));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->key = newKey;

	return new_node;

}

BST_node* treeInsert(BST_node* parent, int newKey) {



	if (parent == NULL) {
		BST_node* InNode = createNode(newKey);

		return InNode;

	}

	if (newKey < parent->key) {
		parent->left = treeInsert(parent->left, newKey);

		return parent;

	}

	else {
		parent->right = treeInsert(parent->right, newKey);

		return parent;

	}

}

BST_node* treeSearch(BST_node* root, int Skey) {
	if (root == NULL) {
		return NULL;
	}

	if (root->key == Skey) {
		return root;
	}

	if (Skey < root->key) {
		return treeSearch(root->left, Skey);
	}

	else {
		return treeSearch(root->right, Skey);
	}

}

BST_node* treeParentSearch(BST_node* root, int Skey) {
	if (root == NULL) {
		return NULL;
	}

	if (root->left->key == Skey || root->right->key == Skey) {
		return root;
	}

	if (Skey < root->key) {
		return treeSearch(root->left, Skey);
	}

	else {
		return treeSearch(root->right, Skey);
	}

}

BST_node* deleteNode(BST_node* rNode) {

	if (rNode->left == rNode->right == NULL) {
		return NULL;
	}

	else if (rNode->left == NULL && rNode->right != NULL) {
		return rNode->right;
	}

	else if (rNode->left != NULL && rNode->right == NULL) {
		return rNode->left;
	}

	else {

		BST_node* s;
		BST_node* p;

		s = rNode->right;

		while (s->left != NULL) {

			p = s;

			s = s->left;

		}

		rNode->key = s->key;

		if (s == rNode->right) {

			rNode = s->right;

		}

		else {

			p->left = s->right;

		}

		return rNode;

	}

}

void treeDelete(BST_node* root, BST_node* rNode, BST_node* pNode) {

	if (rNode == root) {

		root = deleteNode(root);

	}

	else if (rNode == pNode->left) {

		pNode->left = deleteNode(rNode);

	}

	else {

		pNode->right = deleteNode(rNode);

	}

}



void print(BST_node* root) {

	if (root == NULL)

		return;

	print(root->left);
	printf("%d ", root->key);
	print(root->right);

}

int main() {

	BST_node* root = createNode(30);

	int newKey;
	int command;
	int Skey;

	while (1) {
		scanf("%d", &command);

		if (command == 1) {
			printf("새로운 노드 키:");
			scanf("%d", &newKey);
			treeInsert(root, newKey);

		}

		else if (command == 2) {

			BST_node* Snode;

			printf("삭제하려는 노드의 키:");
			scanf("%d", &Skey);

			Snode = treeSearch(root, Skey);

			if (Snode == NULL) {
				printf("찾는 데이터가 없음\n");
			}

			else {
				treeDelete(root, Snode, treeParentSearch(root, Skey));
			}

		}

		else {
			break;
		}

	}

	print(root);



}