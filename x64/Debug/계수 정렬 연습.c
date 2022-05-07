#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void countingSort(int* arr, int n, int k) {
	int* c = (int*)malloc(sizeof(int) * k);

	for (int i = 0; i < k; i++) {
		c[i] = 0; //c�� �ڿ����� ������ŭ�� ũ�⸦ ���� �迭 ī��Ʈ�� 0���� �����ϴ� ��� 0���� �ʱ�ȭ ���ش�.
	}
	for (int i = 0; i < n; i++) {
		c[arr[i]]++;  //arr[i]�� ���� c�� �ε��� ����Ͽ� �ϳ��� ī��Ʈ ���ش�.
	}
	for (int i = 0; i < k; i++) {
		if (c[i] != 0) {  //i�� �ѹ� �̶� �־ �ѹ��̶� ī��Ʈ �Ǿ��ٸ� ����
			for (int j = 0; j < c[i]; j++) { //ī��Ʈ�� ���� ��ŭ ���
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