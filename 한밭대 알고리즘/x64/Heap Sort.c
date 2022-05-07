#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
void swap(int* arr, int i, int j) {
	int tmp;
	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
void heapSort(int* arr, int n) {
	//BuildHeap 과정  (배열을 처음에 히피파이를 할 수 있도록 힙구조로 바꿈)

	int root;
	int c;


	for (int i = 1; i < n; i++) {
		c = i; //자식은 1부터 하나씩 검사

		while (c != 0) {  //c가 0이 되어버리면 반복문 나옴
			root = (c - 1) / 2;  //부모구하고
			if (arr[c] > arr[root]) { //자식이 부모보다 크다면 스왑
				swap(arr, c, root);
			}
			c = root;  //현재 부모를 자식에 넣어서 점차 위로 올라가게 함
		}

	}
	//heapify 과정 (새롭게 변형된 노드를 다시 힙구조로 만들어 수정하는 과정

	for (int i = n - 1; i > 0; i--) {  //맨 뒤에서부터 범위를 하나씩 줄임
		swap(arr, i, 0); //맨 마지막 노드(가장 작은 수)를 첫번쨰 노드와 바꿈

		int root = 0;
		int c = 1;

		while (1) {
			c = root * 2 + 1; //자식 구하고

			if (c >= i) { //자식이 범위를 넘어섰다면 반복문을 나감
				break;
			}
			if (arr[c] < arr[c + 1] && c<i-1) {  //자식 중에서 큰 값을 찾음
				c++;
			}
			if (arr[root] < arr[c]) { //자식 중에서 큰 값이 부모보다도 크다면 스왑
				swap(arr, root, c);
			}

			root = c; //현재 자식을 부모에 넣어서 점차 내려가게 함


		}
	}
}

int main() {
	srand((unsigned int)time(NULL));
	int n, max;

	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = rand() / (double)RAND_MAX * 1000;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	heapSort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}


}