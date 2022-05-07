#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
void swap(int* arr, int i, int j) {
	int tmp;
	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
int partition(int* arr, int m, int n) {
	if (m >= n) {
		return;
	}

	int pebut = m;
	int i = m + 1;
	int j = n;
	int tmp;

	while (i <= j) {
		while (arr[i] <= arr[pebut]) {
			i++;
		}
		while (arr[j] >= arr[pebut] && j > m) {
			j--;
		}
		if (i > j) {
			swap(arr, j, pebut);
		}
		else {
			swap(arr, i, j);
		}
	}
	return j;
}
int select(int* arr, int p, int r, int i) {
	if (p = r) {
		return arr[p];
	}
	int q = partition(arr, p, r);
	int k = q - p + 1;
	if (i < k) {
		return select(arr, p, q - 1, i);
	}
	else if (i = k) {
		return arr[q];
	}
	else {
		return select(arr, q + 1, r, i - k);
	}
}
int main() {
	srand((unsigned int)time(NULL));
	int n, num, search;

	scanf_s("%d %d", &n, &num);

	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = rand() / (double)RAND_MAX * 1000;
	}
	search = select(arr, 0, n-1, num);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	printf("%d 번째 작은 수:%d", num, search);



}