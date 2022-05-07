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
void heapify(int* arr, int n) {
	for (int i = n; i > 0; i--) {//맨 끝에 정렬할 것이기 때문에 맨 끝부터 점차 아래로 내려옴
		swap(arr, 0, i); //맨 위 숫자(인덱스 0)과 맨 끝 숫자(정렬할 숫자) 를 교환함

		int root = 0; //부모는 항상 0(맨 위)부터 시작
		int c = 1;

		while(1) { //한번 바뀌어도 그 다음에 힙구조가 성립이 안될 수 있기에 while로 반복해줌
			c = root * 2 + 1;//자식 노드를 구해주고
			if (c >= i) {//만약 구한 자식이 현재 맨 끝인덱스인 i보다 크거나 같다면 범위를 초과한 것임으로 반복문을 나감
				break;
			}

			if (arr[c] < arr[c + 1] && c < i - 1) { //자식 중에서 큰 값을 골라주고 맨 뒤에 있는 정렬된 배열에 미치지 못하게 범위 설정
				c++;
			}
			if (arr[root] < arr[c])//찾은 자식값이 부모보다 크다면 스왑
				swap(arr, root, c);
			root = c; //자식 인덱스가 부모가 되어서 아래로 점점 내려감
		}
	}
}
void heapSort(int* arr, int n) {
	//heap build 과정
	for (int i = 1; i <= n; i++) { //모든 노드를 확인하기 위해 큰 for문으로 1회전 돌림 1인덱스 부터 확인
		int c = i; //0은 항상 부모노드이기 때문에 첫번째 자식 노드인 1번째 인덱스부터 시작
		
		do{ 
			int root = (c - 1) / 2;
			if (arr[root] < arr[c]) {
				swap(arr, root, c);
			}
			c = root; //부모 인덱스가 자식이 되어서 위로 점점 올라감
		} while (c != 0);//c는 계속해서 위로 올라가기 떄문에 0(최대 큰 수)이 될 때가 있다 그 떄 반복문을 나온다
	}

	//특정한 노드를 힙구조로 수정하는 히피파이 과정
	heapify(arr, n);
}

int main() {
	srand((unsigned int)time(NULL));
	int n, max;

	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = rand() / (double)RAND_MAX * 1000;
	}
	heapSort(arr, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}



}