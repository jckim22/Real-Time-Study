#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

void countingSort(int* arr,int* Barr, int n, int bound) {
	int* cnt = (int*)malloc(sizeof(int) * bound);
	for (int i = 0; i < bound; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cnt[arr[i]]++;
	}
	for (int i = 0; i < bound; i++) {
		if (cnt[i] != 0) {
			for (int j = 0; j < cnt[i]; j++) {
				printf("%d ", i);
			}
		}
	}
}

int main() {
	srand((unsigned int)time(NULL));
	int n, num;

	scanf_s("%d %d", &n, &num);

	int* arr = (int*)malloc(sizeof(int) * n);
	int* Barr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = rand() / (double)RAND_MAX * num;
	};
	countingSort(arr,Barr, n, num);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	



}