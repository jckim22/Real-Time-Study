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
		int j = i-1; //���� ���ĵ� �� �ٷ� �� ����(�̹� ���ĵǾ� �־����)
		int newItem = arr[i]; //���� ���ĵ� ��
		while (j >= 0 && newItem < arr[j]) //j�� 0���� ũ�ų� ���� ���� ���ĵ� ���� ������ �̹� ���ĵ� �迭 �� �� ū ���� �־����
		{
			arr[j + 1] = arr[j]; //��ĭ�� �̷�� ���� ���� j�� ���� ��°�� ���� j ���� �־��ش�
			
			j--; //j�� �������� ��ĭ ���
			cnt++;
			for (int j = 0; j < n; j++) {
				printf("%d ", arr[j]);
			}
			printf("\n");
		}
		arr[j + 1] = newItem; //while�� ���ƴٸ� j--�� �������� ����Ʊ� ������ ���ϵ� ��ġ�� newItem�� ���Եȴ�.
	
		
		
	}
	printf("�� Ƚ��:%d\n", cnt);
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