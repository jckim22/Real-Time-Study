#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int sorted[100000]; //������ �迭���� �ӽ÷� ����� �迭
void merge(int* arr, int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;
	while (i <= middle && j <= n) {

		if (arr[i] > arr[j]) { //���� �迭�� �����Ͱ� ������ �迭�� �����ͺ��� ũ�ٸ� ���ʴ�� ����(��������)
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}

	if (i > middle) {  //���� �迭�� ���� �����ٸ� ������ �迭 ������ ���� ����
		for (int t = j; t <= n; t++) {
			sorted[k] = arr[t];

			k++;
		}

	}
	else {  //�ݴ��
		for (int t = i; t <= middle; t++) {
			sorted[k] = arr[t];

			k++;
		}
	}
	for (int t = m; t <= n; t++) {  //���� �迭�� ���ĵ� �迭�� �Ű���
		arr[t] = sorted[t];
	}
}
void mergeSort(int* arr, int m, int n){
	if (m >= n) { //1���� �ƴٸ� ��� ����
		return;
	}
	int middle = (m + n) / 2;

	mergeSort(arr, m, middle);  //������ ����
	mergeSort(arr, middle + 1, n);
	merge(arr, m,middle, n);
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
	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

