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
int heapSort(int* arr,int n) {
	//heap ���·� build�ϴ� ����
	for (int i = 1; i <= n; i++) { //��ü������ 1��° �ε������� ������ �ε������� �ݺ�
		int c = i; //������ �׻� i�� ����
		do {
			int root = (c - 1) / 2; //�θ��ϰ�

			if (arr[root] < arr[c]) { //�θ� �ڽĺ��� ������ ��ȯ
				swap(arr, root, c);
			}

			c = root; //�� ���� �ö󰡸鼭 ������ �ִ����� �ش�Ǵ��� Ȯ��
		} while (c != 0); //0���� �ö󰡼� Ȯ�������� �ݺ��� ����

	}
	

	//���⼭���ʹ� Ư���� ��常 �������ִ� heapify ����
	for (int i = n; i > 0; i--) { //������ ���� ���ʷ� ���̸鼭 �ٲٱ� ���� i�� n���� �����ؼ� 1ĭ�� ����
		swap(arr, 0, i);  //���� ū ���� 0��° �ε����̱� ������ �� ���� �ٲ۴�

		int root = 0;
		int c = 1;

		do{
			c = root * 2 + 1; //�ڽ� ���ϰ�
			if (c >= i) { //���� �ڽ��� ���� �� ���̶�� �������ִ� (i) ���� ũ�ų� ���ٸ�(������ ���Ұ� 2���� ����) ������ ���� ���̹Ƿ� �ݺ����� ����
				break;
			}
			if (arr[c] < arr[c + 1]&&c<i-1) { //�ڽ��߿��� ū ���� ã�� ���̸� ������ ���� �ʰ� �Ѵ� i�� ���̴ϱ� �ִ� i-1���� ������ �� �ְ�
				c++;
			}
			if (arr[root] < arr[c]) { //ã�� ū �ڽ��� �θ𺸴� ũ�ٸ� �����Ѵ�. (���⼭ c<i��� ������ �����ϴ� ���� ���Ұ� 2���� ���� ����
										//������ break���� c>i�� �ƴ� c>=i�� ����� ������ ���� 2���� �� break�ż� ���� ���� ���ص���
				swap(arr, root, c);
			}

			root = c;
		} while (1);


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
	heapSort(arr, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}



}