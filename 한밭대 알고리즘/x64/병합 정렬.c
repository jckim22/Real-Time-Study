#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

int sorted[100000];

void merge(int* arr, int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n) {
		if (arr[i] <= arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	for (int t = m; t <= n; t++) {
		arr[t] = sorted[t];
	}
}
void mergeSort(int* arr, int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(arr, m, middle);
		mergeSort(arr, middle + 1, n);
		merge(arr, m, middle, n);
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
	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}



}