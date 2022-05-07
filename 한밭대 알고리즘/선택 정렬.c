#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
int theLargest(int* arr, int last) {
	int largest = 0;
	for (int i = 1; i <= last; i++) { //i�� 1���� main���� ���� last �ε����� �� ������ ��,largest�� 0�̱⿡ i�� 1���� ����
		if (arr[i] >= arr[largest]) {
			largest = i; //�� ũ�ٸ� largest�� ���� �ε����� �ʱ�ȭ��
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
	for (int i = n - 1; i > 0; i--) { //n-1��° �ε����� 1���ε����� �� �� ���� �ݺ�
		largest = theLargest(arr, i); //i(n-1,n-2,'''''1)�� last������ ������
		swap(arr, i, largest);
	}
}

int main() {
	srand((unsigned int)time(NULL));
	int n;

	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n); //���� �迭 ����

	for (int i = 0; i < n; i++) {
		arr[i] = rand() / (double)RAND_MAX * 1000;
	}
	SelectionSort(arr, n); 
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}





}