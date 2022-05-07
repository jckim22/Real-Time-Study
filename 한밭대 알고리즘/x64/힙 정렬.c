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
	for (int i = n; i > 0; i--) {//�� ���� ������ ���̱� ������ �� ������ ���� �Ʒ��� ������
		swap(arr, 0, i); //�� �� ����(�ε��� 0)�� �� �� ����(������ ����) �� ��ȯ��

		int root = 0; //�θ�� �׻� 0(�� ��)���� ����
		int c = 1;

		while(1) { //�ѹ� �ٲ� �� ������ �������� ������ �ȵ� �� �ֱ⿡ while�� �ݺ�����
			c = root * 2 + 1;//�ڽ� ��带 �����ְ�
			if (c >= i) {//���� ���� �ڽ��� ���� �� ���ε����� i���� ũ�ų� ���ٸ� ������ �ʰ��� �������� �ݺ����� ����
				break;
			}

			if (arr[c] < arr[c + 1] && c < i - 1) { //�ڽ� �߿��� ū ���� ����ְ� �� �ڿ� �ִ� ���ĵ� �迭�� ��ġ�� ���ϰ� ���� ����
				c++;
			}
			if (arr[root] < arr[c])//ã�� �ڽİ��� �θ𺸴� ũ�ٸ� ����
				swap(arr, root, c);
			root = c; //�ڽ� �ε����� �θ� �Ǿ �Ʒ��� ���� ������
		}
	}
}
void heapSort(int* arr, int n) {
	//heap build ����
	for (int i = 1; i <= n; i++) { //��� ��带 Ȯ���ϱ� ���� ū for������ 1ȸ�� ���� 1�ε��� ���� Ȯ��
		int c = i; //0�� �׻� �θ����̱� ������ ù��° �ڽ� ����� 1��° �ε������� ����
		
		do{ 
			int root = (c - 1) / 2;
			if (arr[root] < arr[c]) {
				swap(arr, root, c);
			}
			c = root; //�θ� �ε����� �ڽ��� �Ǿ ���� ���� �ö�
		} while (c != 0);//c�� ����ؼ� ���� �ö󰡱� ������ 0(�ִ� ū ��)�� �� ���� �ִ� �� �� �ݺ����� ���´�
	}

	//Ư���� ��带 �������� �����ϴ� �������� ����
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