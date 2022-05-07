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
int partition(int* arr, int m, int n) {
	int pebut = m; //pebut�� �� ó�� ����
	int i = m + 1;  //���� �����
	int j = n;     //������ �����
	

	while (i < j) {  //������ �� ���� �ݺ�
		while (arr[i] < arr[pebut]) { //�ǹ����� ū ���� ã��
			i++;
		}
		while (arr[j] > arr[pebut]) {  //�ǹ����� ���� ���� ã��
			j--;
		}
		if (i > j) {   //���� �����ȴٸ� (������ �ݺ��̶��) �ǹ��� j�� ���� ��ȯ
			swap(arr, pebut, j); 
		}
		else {  //�������� �ʾҴٸ� i�� j�� ���� ��ȯ
			swap(arr, i, j);
		}
	}
	for (int i = m; i < n+1; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("partion : %d\n", j);
	return j;
}
int select(int* arr,int m,int n,int search) {
	if (m == n) {
		return arr[m]; //���Ұ� �ϳ���� �װ��� ã�� ���̱⿡ ����
	}
	int p = partition(arr, m, n); //pebut index�� �����
	

	int k = p - m + 1;   //pebut�� ���° ���� ������ �����
	printf("k=%d\nsearch=%d\n", k,search);
	if (search < k) {  //�������� ���� ����
		return select(arr, m, p - 1, search);
	}
	else if (search == k) {  //ã�� �Ͱ� �ǹ��� ������ ��ġ�� ����
		return arr[p];
	}
	else{
		return select(arr, p + 1, n, search-k);  //���������� ���� ����
	}
}
int main() {
	srand((unsigned int)time(NULL));
	int n, num, search;

	scanf_s("%d %d", &n, &num);

	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = rand() / (double)RAND_MAX * 1000;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	search = select(arr, 0, n-1, num);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	printf("%d ��° ���� ��:%d", num, search);



}