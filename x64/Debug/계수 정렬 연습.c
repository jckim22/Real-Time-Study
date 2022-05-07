#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void countingSort(int* arr, int n, int k) {
	int* c = (int*)malloc(sizeof(int) * k);

	for (int i = 0; i < k; i++) {
		c[i] = 0; //c는 자연수의 범위만큼의 크기를 가진 배열 카운트는 0부터 시작하니 모두 0으로 초기화 해준다.
	}
	for (int i = 0; i < n; i++) {
		c[arr[i]]++;  //arr[i]의 값을 c의 인덱스 취급하여 하나씩 카운트 해준다.
	}
	for (int i = 0; i < k; i++) {
		if (c[i] != 0) {  //i가 한번 이라도 있어서 한번이라도 카운트 되었다면 들어옴
			for (int j = 0; j < c[i]; j++) { //카운트된 개수 만큼 출력
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
	

	for (int i = 0; i < n; i++) {
		arr[i] = rand() / (double)RAND_MAX * num;
	};
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	countingSort(arr, n, num);
	

}