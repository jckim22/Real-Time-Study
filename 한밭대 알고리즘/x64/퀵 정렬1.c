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
	int pebut = start; //pebut���� �� �� ������ ����
	int i = start + 1; //pebut�� �����ϰ� ���ʺ��� �ö�(pebut�� ���� ū �� ã��)
	int j = end;      //�����ʺ��� ������(pebut�� ���� ���� �� ã��)
	if (start >= end) { //���Ұ� �� ���� ���(����ϴٰ� ���������� ���ҵǾ� �ڸ��� ã�ԵǸ� ����)
		return;
	}
	while (i < j) { //i�� ��� Ŀ�� ���̰� j�� ��� �ٱ� ������ ���� �������� �ȴ�. �� �� �ݺ����� ������ �ȴ�(�ǹ��� �ڸ��� �Ű��ֱ� ����)
		while (arr[i] <= arr[pebut]) { 
			i++;
		}
		while (arr[j] >= arr[pebut] && j >pebut) {//���� 1�� pebut�̶�� �����ϸ� j�� ��� �ٸ鼭 pebut�ε������� ���� ����
			j--;
		}
		if (i < j) {
			swap(arr, i, j);
		}
		else {
			swap(arr, pebut, j); //�̶� j�� ��ġ�� pebut�� �� ������ �ڸ��̴�
		}
	}
	quickSort(arr, start, j - 1); //���� j�� �������� ���� ������
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