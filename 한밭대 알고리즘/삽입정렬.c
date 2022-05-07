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
	int cnt = 0;
	
	for (int i = 1; i <=n-1; i++) {
		int j = i-1; //새로 정렬될 수 바로 전 범위(이미 정렬되어 있어야함)
		int newItem = arr[i]; //새로 정렬될 수
		while (j >= 0 && newItem < arr[j]) //j가 0보다 크거나 같고 새로 정렬될 수가 이전에 이미 정렬된 배열 중 더 큰 수가 있어야함
		{
			arr[j + 1] = arr[j]; //한칸씩 미루기 위해 현재 j의 다음 번째에 현재 j 수를 넣어준다
			
			j--; //j를 왼쪽으로 한칸 댕김
			cnt++;
			for (int j = 0; j < n; j++) {
				printf("%d ", arr[j]);
			}
			printf("\n");
		}
		arr[j + 1] = newItem; //while을 거쳤다면 j--가 마지막에 진행됐기 때문에 삽일될 위치에 newItem이 삽입된다.
	
		
		
	}
	printf("총 횟수:%d\n", cnt);
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