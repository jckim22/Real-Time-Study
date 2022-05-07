#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

void swap(int* arr, int a, int b) {
	int tmp;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
void BubbleSort(int* arr, int n) {
	//하나가 선택되어서 계속 올라가는게 아니라 두개씩 비교하다 보면 가장 큰 수가 오른쪽으로 가게 됨
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr, j, j + 1);
			}
		}
	}
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