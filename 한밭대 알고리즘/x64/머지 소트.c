#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int sorted[100000];

void merge(int* arr, int m,int middle, int n) {
	int first = m;
	int second = middle + 1;
	int tmp = m;


	while (first <= middle && second <= n) {
		if (arr[first] < arr[second]) {
			sorted[tmp] = arr[first];
			first++;
		}
		else {
			sorted[tmp] = arr[second];
			second++;
		}
		tmp++;
	}
	if (first > middle) {
		for (int j = second; j <=n; j++) {
			sorted[tmp] = arr[j];
			tmp++;
		}

	}
	else {
		for (int i = first; i <= middle; i++) {
			sorted[tmp] = arr[i];
			tmp++;
		}
	}

	for (int i = m; i <= n; i++) {
		arr[i] = sorted[i];
	}
}
void mergeSort(int* arr, int m, int n) {
	if (m >= n) {
		return;
	}
	int middle = (m + n) / 2;

	mergeSort(arr, m, middle);
	mergeSort(arr, middle + 1, n);
	merge(arr, m, middle, n);

}
int main() {
	srand((unsigned int)time(NULL));
	int n, max;

	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = rand() / (double)RAND_MAX * 1000;
	}

	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}



}