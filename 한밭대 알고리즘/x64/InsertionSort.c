#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
void swap(int* arr, int a, int b) {
	int tmp;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void insertionSort(int* arr, int n) {
	//왼쪽은 항상 정렬이 되어있기 때문에 나보다 작은 값을 만나면 그때 반복을 끝내면 된다.
	
	for (int i = 0; i < n - 1; i++ ) {  //모래 지옥 처럼 하나씩 끌고 와서 삽입한다. j+1이 삽입할 수
		int j = i;
		while (arr[j] > arr[j + 1]) {
			swap(arr, j, j + 1);
			j--; //이미 정렬된 배열 안쪽으로 끌고 오기
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
	insertionSort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}