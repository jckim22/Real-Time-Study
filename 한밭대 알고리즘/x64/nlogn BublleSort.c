#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

void swap(int* arr, int i, int iNext) {
	int tmp;
	tmp = arr[i];
	arr[i] = arr[iNext];
	arr[iNext] = tmp;
}
void BubbleSort(int* arr, int n) {
	int cnt=0;
	
	for (int i = n - 1; i > 0; i--) {  //n-1번째 인덱스가 1번인덱스가 될 때 까지 반복
		int sorted = 1;				   //sorted에 true값을 넣음
		for (int j = 0; j < i; j++) {  //마지막 인덱스까지 비교해서 큰 값이 맨 오른쪽으로 천천히 올라오게 함
			if (arr[j] > arr[j + 1]) {
				swap(arr, j, j + 1);
				sorted = 0;			   //한번이라도 swap이 되면 아직 정렬이된 것이 아니기에 sorted에 false값을 넣음
				cnt++;
			}
			
		}
		if (sorted) { //sorted가 true 값이라면 swap연산이 한번도 실행되지 않았다는 것이고 정렬이 되었다는 뜻, 반복문을 빠져나와 정렬을 끝냄
			break;
		}
	}
	printf("총 횟수 : %d\n", cnt);
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
	BubbleSort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}