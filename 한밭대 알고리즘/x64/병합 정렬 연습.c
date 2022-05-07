#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

int cnt = 0;

int sorted[100000];

void merge(int* arr,int m,int middle,int n) {
	cnt++;
	int i = m; //왼쪽 배열 시작값
	int j = middle + 1;  //오른쪽 배열 시작값
	int k = m; //담아둘 배열 시작값

	while (i <= middle && j <= n) {//왼쪽 배열이 끝까지 가기전 혹은 오른쪽 배열이 끝까지 가기 전 까지 반복
		if (arr[i] <= arr[j]) { //왼쪽배열 값이 오른쪽 배열 값보다 작다면
			sorted[k] = arr[i]; //정렬 배열에 작은 값을 담고
			i++;  //왼쪽배열 하나 담았으니 다음칸으로 이동
		}
		else  //반대로
		{
			sorted[k] = arr[j];
			j++;
		}
		k++;//한번 담았으니 정렬 배열도 다음 칸으로 이동
	}
	if (i > middle) {  //i가 먼저 끝났다면 middle보다 클 것임으로
		for (int t = j; t <= n; t++) {
			sorted[k] = arr[t];  //나머지 넣어줌
			k++;
		}
	}
	else {  //반대
		for (int t = i; t <= middle; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	printf("%d번째 재귀일 때 sorted(임시)배열 :",cnt);
	for (int t = m; t <= n; t++) {
		printf("%d ", sorted[t]);
	}
	printf("\n");
	for (int t = m; t <= n; t++) {  //임시 저장했던 배열을 원래 배열로 옮겨줌
		arr[t] = sorted[t];
	}
	printf("%d번째 재귀일 때 arr(원본)배열 :",cnt);
	for (int t = m; t <= n; t++) {
		printf("[%d] : %d ",t, arr[t]);
	}
	printf("\n");
}
void mergeSort(int* arr, int m, int n) {
	if (m < n) { //시작 인덱스가 끝 인덱스보다 작다는 것, 즉 원소가 1개보다 많다는 것
		int middle = (m + n) / 2;
		mergeSort(arr, m, middle);
		mergeSort(arr, middle +1, n);
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
	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", sorted[i]);
	}



}