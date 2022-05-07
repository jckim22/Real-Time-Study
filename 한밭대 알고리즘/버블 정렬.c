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
	for (int i = n - 1; i > 0; i--) {  //n-1��° �ε����� 1���ε����� �� �� ���� �ݺ�
		for (int j = 0; j < i; j++) {  //������ �ε������� ���ؼ� ū ���� �� ���������� õõ�� �ö���� ��
			if (arr[j] > arr[j + 1]) {
				swap(arr, j, j + 1);
			}
			cnt++;
		}
	}
	printf("�� Ƚ�� : %d\n", cnt);
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