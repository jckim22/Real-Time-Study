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
void quickSort(int* arr,int start,int end) {
	int pebut = start; //pebut값은 맨 앞 값으로 지정
	int i = start + 1; //pebut값 제외하고 왼쪽부터 올라감(pebut값 보다 큰 값 찾기)
	int j = end;      //오른쪽부터 내려옴(pebut값 보다 작은 값 찾기)
	if (start >= end) { //원소가 한 개인 경우(재귀하다가 마지막까지 분할되어 자리를 찾게되면 리턴)
		return;
	}
	while (i < j) { //i는 계속 커질 것이고 j는 계속 줄기 때문에 둘이 엇갈리게 된다. 그 때 반복문을 나가게 된다(피벗을 자리로 옮겨주기 위해)
		while (arr[i] <= arr[pebut]) { 
			i++;
		}
		while (arr[j] >= arr[pebut] && j >pebut) {//만약 1이 pebut이라고 가정하면 j가 계속 줄면서 pebut인덱스까지 가기 때문
			j--;
		}
		if (i < j) {
			swap(arr, i, j);
		}
		else {
			swap(arr, pebut, j); //이때 j의 위치가 pebut이 들어갈 적절한 자리이다
		}
	}
	quickSort(arr, start, j - 1); //따라서 j를 기준으로 반을 나눈다
	quickSort(arr, j + 1, end);

}
int main() {
	srand((unsigned int)time(NULL));
	int n, max;

	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = rand() / (double)RAND_MAX * 1000;
	}
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}



}