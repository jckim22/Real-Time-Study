#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int sorted[100000]; //정렬한 배열들을 임시로 담아줄 배열
void merge(int* arr, int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;
	while (i <= middle && j <= n) {

		if (arr[i] > arr[j]) { //왼쪽 배열의 데이터가 오른쪽 배열의 데이터보다 크다면 차례대로 정렬(내림차순)
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}

	if (i > middle) {  //왼쪽 배열이 먼저 끝났다면 오른쪽 배열 나머지 값들 대입
		for (int t = j; t <= n; t++) {
			sorted[k] = arr[t];

			k++;
		}

	}
	else {  //반대로
		for (int t = i; t <= middle; t++) {
			sorted[k] = arr[t];

			k++;
		}
	}
	for (int t = m; t <= n; t++) {  //원래 배열에 정렬된 배열을 옮겨줌
		arr[t] = sorted[t];
	}
}
void mergeSort(int* arr, int m, int n){
	if (m >= n) { //1개가 됐다면 재귀 끝냄
		return;
	}
	int middle = (m + n) / 2;

	mergeSort(arr, m, middle);  //반으로 나눔
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

