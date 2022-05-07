#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

typedef struct BST BST;
typedef struct BST { //노드의 구조
	int data; //key값
	BST* left; //왼쪽 자식
	BST* right; //오른쪽 자식
}BST;

BST* new_node(int key) { //새로운 노드 생성
	BST* new_node = (BST*)malloc(sizeof(BST*));
	new_node->data = key;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}
BST* SearchNode(BST* parent, int key) {  
	if (parent == NULL || parent->data == key) {  //부모가 NULL이거나 부모의 데이터가 키값일 때
		return parent;  //부모를 리턴
	}
	if (key < parent->data) {
		return SearchNode(parent->left, key);  //키값이 왼쪽 보다 작을때 왼쪽 자식으로 감
	}
	else {
		return SearchNode(parent->right, key); //반대로
	}
}
BST* InsertNode(BST* parent, int key) {
	if (parent == NULL) {     //3.계속 내려가다가 자식 값이 NULL이게 되면 
		return new_node(key); //4.새로운 노드를 리턴하여 그 자식에 대입
	} 
	if (key < parent->data) {    //1.삽입하려는 key값이 현재 parent의 데이터보다 작다면 
		parent->left = InsertNode(parent->left, key);  //2.parent의 왼쪽 자식을 다시 parent로 받게됨 (이진 트리는 작은 것이 왼쪽이기 때문)
		return parent;  //5.재귀가 다시 감아지면서 원래 노드에 같은 노드가 다시 들어가기 때문에 트리에는 아무 영향 없음
	}
	else {//반대로 key값이 현재 parent 보다 크거나 같다면
		parent->right = InsertNode(parent->right, key); //parent의 오른쪽을 다시 parent로 재귀하게됨
		return parent;
	}
}
BST* SearchParentNode(BST* parent, int key) {
	
	if (parent->right == NULL) { 
		if (parent->left->data == key) { //parent의 왼쪽 자식의 데이터가 key값이면
			return parent; //그 부모를 리턴
		}
	}
	else if (parent->left == NULL) {
		if (parent->right->data == key) { //반대로 오른쪽 자식의 데이터가 key값이면ㄷ
			return parent;  //그 부모를 리턴
		}
	}
	else {
		if (parent->right->data == key || parent->left->data == key) { //양쪽 자식이 다 있을 때 둘 중하나가 key값이면 
			return parent;  //부모를 리턴
		}
	}
	
	if (key < parent->data) {
		return SearchParentNode(parent->left, key);
	}
	else {
		return SearchParentNode(parent->right, key);
	}
}

//이 밑에 방식은 삭제할 노드의 부모노드가 필요없는 Delete방식
//key값을 복사하는 형태에 알고리즘이다

/*
BST* delete_node(BST* parent, int key) {  
	if (key < parent->data) 			// 키가 루트보다 작으면 왼쪽 서브 트리에 있음
		parent->left = delete_node(parent->left, key);
	else if (key > parent->data) 		// 키가 루트보다 크면 오른쪽 서브 트리에 있음
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
	if (rNode->left ==NULL && rNode->right == NULL) { //case 1 : 삭제하려는 노드의 자식이 없을 때
		return NULL;
	}
	else if (rNode->left == NULL && rNode->right != NULL) { //case 2: 자식이 하나 있을 때
		return rNode->right;
	}
	else if (rNode->left != NULL && rNode->right == NULL) {
		return rNode->left;
	}
	else { //case3: 자식이 둘 다 있을 때
		BST* s;
		BST* p;
		s = rNode->right;
		while (s->left != NULL) {
			p = s;
			s = s->left;
		}
		rNode->data = s->data;
		if (s == rNode->right) {//s가 rNode 오른쪽 자식 일때
			rNode = s->right;
		}
		else {  //대부분은 이 경우
			p->left = s->right;
		}
		return rNode;
	}
}
BST* treeDelete(BST* parent, int key) {
	BST* r = SearchNode(parent,key); //삭제할 노드
	BST* rp = SearchParentNode(parent, key); //삭제할 노드의 부모노드
	if (r == parent) { //r이 루트 노드인 경우
		parent = DeleteNode(parent);  //루트 노드를 삭제
	}
	else if (r == rp->left) {  //삭제하려는 노드가 그 부모의 왼쪽이면
		rp->left = DeleteNode(r); //노드를 삭제하고 그 부모 왼쪽에 이어줌
		free(r);
		printf("left\n");
	}
	else if(r==rp->right) {//삭제하려는 노드가 그 부모의 오른쪽이면
		rp->right = DeleteNode(r);//노드를 삭제하고 그 부모 오른쪽에 이어줌
		free(r);
		printf("right\n");
	}

}

void print(BST* root) {//알아보기 쉽게 하기 위하여 작은 것부터 정렬된 상태로 볼 수 있는 중위 순환 사용
	if (root == NULL) {
		return 0;
	}

	
	print(root->left);
	printf("%d ", root->data);
	print(root->right);
}
int main() {
	srand((unsigned int)time(NULL));
	BST* root = new_node(500); //root->data값은 보기 최대한 좋은 트리를 위하여 설정한 난수의 중앙값으로 함
	int key,command;

	for (int i = 0; i < 20; i++) {
		InsertNode(root,rand() / (double)RAND_MAX * 1000);
	}
	while (1) {
		printf("명령 입력:");
		scanf("%d", &command);

		if (command == 1) {
			print(root);
		}
		else if (command == 2) {
			
			printf("찾는 키값:");
			scanf("%d", &key);

			BST* SearchN = SearchNode(root, key);
			BST* SearchPN = SearchParentNode(root, key);
			if (SearchN == NULL) {
				printf("찾는 기값이 없음\n");
			}
			else {
				printf("찾는 키값:%d\n찾는 키값의 부모의 키값:%d\n", SearchN->data,SearchPN->data);
			}
		}
		else if (command == 3) {
			printf("삭제하려는 키값");
			scanf("%d", &key);

			treeDelete(root, key);

		}
		else {
			break;
		}
	}
	
}