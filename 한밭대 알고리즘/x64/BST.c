#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

typedef struct BST BST;
typedef struct BST { //����� ����
	int data; //key��
	BST* left; //���� �ڽ�
	BST* right; //������ �ڽ�
}BST;

BST* new_node(int key) { //���ο� ��� ����
	BST* new_node = (BST*)malloc(sizeof(BST*));
	new_node->data = key;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}
BST* SearchNode(BST* parent, int key) {  
	if (parent == NULL || parent->data == key) {  //�θ� NULL�̰ų� �θ��� �����Ͱ� Ű���� ��
		return parent;  //�θ� ����
	}
	if (key < parent->data) {
		return SearchNode(parent->left, key);  //Ű���� ���� ���� ������ ���� �ڽ����� ��
	}
	else {
		return SearchNode(parent->right, key); //�ݴ��
	}
}
BST* InsertNode(BST* parent, int key) {
	if (parent == NULL) {     //3.��� �������ٰ� �ڽ� ���� NULL�̰� �Ǹ� 
		return new_node(key); //4.���ο� ��带 �����Ͽ� �� �ڽĿ� ����
	} 
	if (key < parent->data) {    //1.�����Ϸ��� key���� ���� parent�� �����ͺ��� �۴ٸ� 
		parent->left = InsertNode(parent->left, key);  //2.parent�� ���� �ڽ��� �ٽ� parent�� �ްԵ� (���� Ʈ���� ���� ���� �����̱� ����)
		return parent;  //5.��Ͱ� �ٽ� �������鼭 ���� ��忡 ���� ��尡 �ٽ� ���� ������ Ʈ������ �ƹ� ���� ����
	}
	else {//�ݴ�� key���� ���� parent ���� ũ�ų� ���ٸ�
		parent->right = InsertNode(parent->right, key); //parent�� �������� �ٽ� parent�� ����ϰԵ�
		return parent;
	}
}
BST* SearchParentNode(BST* parent, int key) {
	
	if (parent->right == NULL) { 
		if (parent->left->data == key) { //parent�� ���� �ڽ��� �����Ͱ� key���̸�
			return parent; //�� �θ� ����
		}
	}
	else if (parent->left == NULL) {
		if (parent->right->data == key) { //�ݴ�� ������ �ڽ��� �����Ͱ� key���̸餧
			return parent;  //�� �θ� ����
		}
	}
	else {
		if (parent->right->data == key || parent->left->data == key) { //���� �ڽ��� �� ���� �� �� ���ϳ��� key���̸� 
			return parent;  //�θ� ����
		}
	}
	
	if (key < parent->data) {
		return SearchParentNode(parent->left, key);
	}
	else {
		return SearchParentNode(parent->right, key);
	}
}

//�� �ؿ� ����� ������ ����� �θ��尡 �ʿ���� Delete���
//key���� �����ϴ� ���¿� �˰����̴�

/*
BST* delete_node(BST* parent, int key) {  
	if (key < parent->data) 			// Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� ����
		parent->left = delete_node(parent->left, key);
	else if (key > parent->data) 		// Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� ����
		parent->right = delete_node(parent->right, key);
	else if (key == parent->data) {
		if (parent->left == NULL &&parent->right==NULL) {
			free(parent);
			return NULL;
		}
		else if (parent->left == NULL) {
			BST* tmp = parent->right;
			free(parent);
			return tmp;
		}
		else if (parent->right == NULL) {
			BST* tmp = parent->left;
			free(parent);
			return tmp;
		}
		BST* tmp = parent->right;
		while (tmp->left != NULL) {
			tmp = tmp->left;
		}
		parent->data = tmp->data;
		parent->right = delete_node(parent->right, tmp->data);
	}
	return parent;
}
*/

BST* DeleteNode(BST* rNode) {
	if (rNode->left ==NULL && rNode->right == NULL) { //case 1 : �����Ϸ��� ����� �ڽ��� ���� ��
		return NULL;
	}
	else if (rNode->left == NULL && rNode->right != NULL) { //case 2: �ڽ��� �ϳ� ���� ��
		return rNode->right;
	}
	else if (rNode->left != NULL && rNode->right == NULL) {
		return rNode->left;
	}
	else { //case3: �ڽ��� �� �� ���� ��
		BST* s;
		BST* p;
		s = rNode->right;
		while (s->left != NULL) {
			p = s;
			s = s->left;
		}
		rNode->data = s->data;
		if (s == rNode->right) {//s�� rNode ������ �ڽ� �϶�
			rNode = s->right;
		}
		else {  //��κ��� �� ���
			p->left = s->right;
		}
		return rNode;
	}
}
BST* treeDelete(BST* parent, int key) {
	BST* r = SearchNode(parent,key); //������ ���
	BST* rp = SearchParentNode(parent, key); //������ ����� �θ���
	if (r == parent) { //r�� ��Ʈ ����� ���
		parent = DeleteNode(parent);  //��Ʈ ��带 ����
	}
	else if (r == rp->left) {  //�����Ϸ��� ��尡 �� �θ��� �����̸�
		rp->left = DeleteNode(r); //��带 �����ϰ� �� �θ� ���ʿ� �̾���
		free(r);
		printf("left\n");
	}
	else if(r==rp->right) {//�����Ϸ��� ��尡 �� �θ��� �������̸�
		rp->right = DeleteNode(r);//��带 �����ϰ� �� �θ� �����ʿ� �̾���
		free(r);
		printf("right\n");
	}

}

void print(BST* root) {//�˾ƺ��� ���� �ϱ� ���Ͽ� ���� �ͺ��� ���ĵ� ���·� �� �� �ִ� ���� ��ȯ ���
	if (root == NULL) {
		return 0;
	}

	
	print(root->left);
	printf("%d ", root->data);
	print(root->right);
}
int main() {
	srand((unsigned int)time(NULL));
	BST* root = new_node(500); //root->data���� ���� �ִ��� ���� Ʈ���� ���Ͽ� ������ ������ �߾Ӱ����� ��
	int key,command;

	for (int i = 0; i < 20; i++) {
		InsertNode(root,rand() / (double)RAND_MAX * 1000);
	}
	while (1) {
		printf("��� �Է�:");
		scanf("%d", &command);

		if (command == 1) {
			print(root);
		}
		else if (command == 2) {
			
			printf("ã�� Ű��:");
			scanf("%d", &key);

			BST* SearchN = SearchNode(root, key);
			BST* SearchPN = SearchParentNode(root, key);
			if (SearchN == NULL) {
				printf("ã�� �Ⱚ�� ����\n");
			}
			else {
				printf("ã�� Ű��:%d\nã�� Ű���� �θ��� Ű��:%d\n", SearchN->data,SearchPN->data);
			}
		}
		else if (command == 3) {
			printf("�����Ϸ��� Ű��");
			scanf("%d", &key);

			treeDelete(root, key);

		}
		else {
			break;
		}
	}
	
}