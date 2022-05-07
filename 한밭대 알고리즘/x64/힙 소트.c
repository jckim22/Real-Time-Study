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
	


	for (int i = 1; i <= n; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;

			if (arr[c] > arr[root]) {
				swap(arr, c, root);
			}
			c = root;

		} while (c != 0);
	}
	//heapify
	for (int i = 0; i <= n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i = n; i > 0; i--) {
		swap(arr, 0, i);
		int root = 0;
		int c = 1;
		while(1) {  //위에서 아래로
			c = root * 2 + 1;
			if (c >= i) {
				break;
			}
			if (arr[c] < arr[c + 1] && c < i-1) {
				c++;
			}
			if (arr[c] > arr[root]) {
				swap(arr, c, root);
			}
			root = c;
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
	heapSort(arr, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}


}