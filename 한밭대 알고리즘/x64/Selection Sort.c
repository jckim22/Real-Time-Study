#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
void swap(int* arr, int i, int j) {
	int tmp;
	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
void SelectionSort(int* arr, int n) {
	
	for (int j = n; j > 0; j--) {
		int largest = 0;
		for (int i = 1; i <= j; i++) {
			if (arr[i] > arr[largest]) {
				largest = i;
			}
		}
		swap(arr, j, largest);
	}
}


int main() {
	srand((unsigned int)time(NULL));
	int n;

	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n); //동적 배열 선언

	for (int i = 0; i < n; i++) {
		arr[i] = rand() / (double)RAND_MAX * 1000;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	SelectionSort(arr, n-1);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}





}