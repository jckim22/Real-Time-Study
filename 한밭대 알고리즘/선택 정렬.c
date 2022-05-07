#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
int theLargest(int* arr, int last) {
	int largest = 0;
	for (int i = 1; i <= last; i++) { //i가 1부터 main에서 받은 last 인덱스가 될 때까지 비교,largest가 0이기에 i는 1부터 시작
		if (arr[i] >= arr[largest]) {
			largest = i; //더 크다면 largest에 현재 인덱스로 초기화함
		}

	}
	return largest;
}
void swap(int* arr, int i, int largest) {
	int tmp;
	tmp = arr[i];
	arr[i] = arr[largest];
	arr[largest] = tmp;
}
void SelectionSort(int* arr, int n) {
	int largest; 
	for (int i = n - 1; i > 0; i--) { //n-1번째 인덱스가 1번인덱스가 될 때 까지 반복
		largest = theLargest(arr, i); //i(n-1,n-2,'''''1)를 last값으로 보내줌
		swap(arr, i, largest);
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
	SelectionSort(arr, n); 
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}





}