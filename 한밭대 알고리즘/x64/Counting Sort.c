#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void countingSort(int* arr,int* barr, int n, int k) {
	int* cnt = (int*)malloc(sizeof(int) * k);
	
	for (int i = 0; i < k; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cnt[arr[i]]++;
	}
	int c = 0; //���� �ε����� ��Ÿ���� ����
	for (int i = 0; i <= k; i++) {
		if (cnt[i] != 0) { //�ѹ��̶� ī��Ʈ �Ǿ��ٸ� ����
			for (int j = 0; j < cnt[i]; j++) {
				barr[c] = i;  
				c++;     //���� �ε���
			}
		}
	}
}

int main() {
	srand((unsigned int)time(NULL));
	int n, num;

	scanf_s("%d %d", &n, &num);

	int* arr = (int*)malloc(sizeof(int) * n);
	int* barr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = rand() / (double)RAND_MAX * num;
	};
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	countingSort(arr,barr, n, num);

	for (int i = 0; i < n; i++) {
		printf("%d ", barr[i]);
	}


}