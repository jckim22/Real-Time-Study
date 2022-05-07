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
void quicksort(int* arr,int m, int n) {
	int pebut = m;
	int i = m+1;
	int j = n;

	if (m >= n) {
		return;
	}

	while (i < j) {
		while (arr[i] < arr[pebut]) {
			i++;
		}
		while (arr[j] > arr[pebut] && j > pebut) {
			j--;
		}
		if (i < j) {
			swap(arr, i, j);
		}
		else {
			swap(arr, pebut, j);
		}
	}

	quicksort(arr, m, j - 1);
	quicksort(arr, j + 1, n);


}

int main() {
	srand((unsigned int)time(NULL));
	int n, max;

	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = rand() / (double)RAND_MAX * 1000;
	}
	quicksort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}



}