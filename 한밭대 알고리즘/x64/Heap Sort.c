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
void heapSort(int* arr, int n) {
	//BuildHeap ����  (�迭�� ó���� �������̸� �� �� �ֵ��� �������� �ٲ�)

	int root;
	int c;


	for (int i = 1; i < n; i++) {
		c = i; //�ڽ��� 1���� �ϳ��� �˻�

		while (c != 0) {  //c�� 0�� �Ǿ������ �ݺ��� ����
			root = (c - 1) / 2;  //�θ��ϰ�
			if (arr[c] > arr[root]) { //�ڽ��� �θ𺸴� ũ�ٸ� ����
				swap(arr, c, root);
			}
			c = root;  //���� �θ� �ڽĿ� �־ ���� ���� �ö󰡰� ��
		}

	}
	//heapify ���� (���Ӱ� ������ ��带 �ٽ� �������� ����� �����ϴ� ����

	for (int i = n - 1; i > 0; i--) {  //�� �ڿ������� ������ �ϳ��� ����
		swap(arr, i, 0); //�� ������ ���(���� ���� ��)�� ù���� ���� �ٲ�

		int root = 0;
		int c = 1;

		while (1) {
			c = root * 2 + 1; //�ڽ� ���ϰ�

			if (c >= i) { //�ڽ��� ������ �Ѿ�ٸ� �ݺ����� ����
				break;
			}
			if (arr[c] < arr[c + 1] && c<i-1) {  //�ڽ� �߿��� ū ���� ã��
				c++;
			}
			if (arr[root] < arr[c]) { //�ڽ� �߿��� ū ���� �θ𺸴ٵ� ũ�ٸ� ����
				swap(arr, root, c);
			}

			root = c; //���� �ڽ��� �θ� �־ ���� �������� ��


		}
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
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	heapSort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}


}