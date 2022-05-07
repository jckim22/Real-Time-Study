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
int partition(int* arr, int m, int n) {
	int pebut = m; //pebut은 맨 처음 숫자
	int i = m + 1;  //왼쪽 출발점
	int j = n;     //오른쪽 출발점
	

	while (i < j) {  //엇갈릴 때 까지 반복
		while (arr[i] < arr[pebut]) { //피버보다 큰 값을 찾음
			i++;
		}
		while (arr[j] > arr[pebut]) {  //피벗보다 작은 값을 찾음
			j--;
		}
		if (i > j) {   //만약 엇갈렸다면 (마지막 반복이라면) 피벗과 j의 값을 교환
			swap(arr, pebut, j); 
		}
		else {  //엇갈리지 않았다면 i와 j의 값을 교환
			swap(arr, i, j);
		}
	}
	for (int i = m; i < n+1; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("partion : %d\n", j);
	return j;
}
int select(int* arr,int m,int n,int search) {
	if (m == n) {
		return arr[m]; //원소가 하나라면 그것이 찾는 값이기에 리턴
	}
	int p = partition(arr, m, n); //pebut index를 담아줌
	

	int k = p - m + 1;   //pebut이 몇번째 작은 값인지 담아줌
	printf("k=%d\nsearch=%d\n", k,search);
	if (search < k) {  //왼쪽으로 범위 좁힘
		return select(arr, m, p - 1, search);
	}
	else if (search == k) {  //찾는 것과 피벗이 동일한 위치면 리턴
		return arr[p];
	}
	else{
		return select(arr, p + 1, n, search-k);  //오른쪽으로 범위 좁힘
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
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	search = select(arr, 0, n-1, num);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	printf("%d 번째 작은 수:%d", num, search);



}