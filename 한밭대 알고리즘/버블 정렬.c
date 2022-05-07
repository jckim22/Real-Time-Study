#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

void swap(int* arr, int i, int iNext) {
	int tmp;
	tmp = arr[i];
	arr[i] = arr[iNext];
	arr[iNext] = tmp;
}
void BubbleSort(int* arr, int n) {
	int cnt = 0;
	for (int i = n - 1; i > 0; i--) {  //n-1번째 인덱스가 1번인덱스가 될 때 까지 반복
		for (int j = 0; j < i; j++) {  //마지막 인덱스까지 비교해서 큰 값이 맨 오른쪽으로 천천히 올라오게 함
			if (arr[j] > arr[j + 1]) {
				swap(arr, j, j + 1);
			}
			cnt++;
		}
	}
	printf("총 횟수 : %d\n", cnt);
}
int main() {
	srand((unsigned int)time(NULL));
	int n;

	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = rand() / (double)RAND_MAX * 1000;
		printf("%d ", arr[i]);
	}
	printf("\n");
	BubbleSort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}