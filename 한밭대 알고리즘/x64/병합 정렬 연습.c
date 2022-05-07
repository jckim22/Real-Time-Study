#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

int cnt = 0;

int sorted[100000];

void merge(int* arr,int m,int middle,int n) {
	cnt++;
	int i = m; //���� �迭 ���۰�
	int j = middle + 1;  //������ �迭 ���۰�
	int k = m; //��Ƶ� �迭 ���۰�

	while (i <= middle && j <= n) {//���� �迭�� ������ ������ Ȥ�� ������ �迭�� ������ ���� �� ���� �ݺ�
		if (arr[i] <= arr[j]) { //���ʹ迭 ���� ������ �迭 ������ �۴ٸ�
			sorted[k] = arr[i]; //���� �迭�� ���� ���� ���
			i++;  //���ʹ迭 �ϳ� ������� ����ĭ���� �̵�
		}
		else  //�ݴ��
		{
			sorted[k] = arr[j];
			j++;
		}
		k++;//�ѹ� ������� ���� �迭�� ���� ĭ���� �̵�
	}
	if (i > middle) {  //i�� ���� �����ٸ� middle���� Ŭ ��������
		for (int t = j; t <= n; t++) {
			sorted[k] = arr[t];  //������ �־���
			k++;
		}
	}
	else {  //�ݴ�
		for (int t = i; t <= middle; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	printf("%d��° ����� �� sorted(�ӽ�)�迭 :",cnt);
	for (int t = m; t <= n; t++) {
		printf("%d ", sorted[t]);
	}
	printf("\n");
	for (int t = m; t <= n; t++) {  //�ӽ� �����ߴ� �迭�� ���� �迭�� �Ű���
		arr[t] = sorted[t];
	}
	printf("%d��° ����� �� arr(����)�迭 :",cnt);
	for (int t = m; t <= n; t++) {
		printf("[%d] : %d ",t, arr[t]);
	}
	printf("\n");
}
void mergeSort(int* arr, int m, int n) {
	if (m < n) { //���� �ε����� �� �ε������� �۴ٴ� ��, �� ���Ұ� 1������ ���ٴ� ��
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