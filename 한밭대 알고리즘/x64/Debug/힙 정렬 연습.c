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
	//heap 상태로 build하는 과정
	for (int i = 1; i <= n; i++) { //전체적으로 1번째 인덱스부터 마지막 인덱스까지 반복
		int c = i; //시작은 항상 i로 시작
		do {
			int root = (c - 1) / 2; //부모구하고

			if (arr[root] < arr[c]) { //부모가 자식보다 작으면 교환
				swap(arr, root, c);
			}

			c = root; //한 층씩 올라가면서 위에는 최대힙이 해당되는지 확인
		} while (c != 0); //0까지 올라가서 확인했으면 반복문 나옴

	}
	

	//여기서부터는 특정한 노드만 수정해주는 heapify 과정
	for (int i = n; i > 0; i--) { //마지막 값을 차례로 줄이면서 바꾸기 위해 i를 n으로 시작해서 1칸씩 줄임
		swap(arr, 0, i);  //가장 큰 값은 0번째 인덱스이기 때문에 맨 끝과 바꾼다

		int root = 0;
		int c = 1;

		do{
			c = root * 2 + 1; //자식 구하고
			if (c >= i) { //만약 자식이 현재 맨 끝이라고 지정돼있는 (i) 보다 크거나 같다면(같을땐 원소가 2개인 상태) 범위를 넘은 것이므로 반복문을 나감
				break;
			}
			if (arr[c] < arr[c + 1]&&c<i-1) { //자식중에서 큰 것을 찾고 끝이면 범위를 넘지 않게 한다 i가 끝이니까 최대 i-1까지 증가할 수 있게
				c++;
			}
			if (arr[root] < arr[c]) { //찾은 큰 자식이 부모보다 크다면 스왑한다. (여기서 c<i라는 범위를 지정하는 경우는 원소가 2개인 상태 때문
										//위에서 break문에 c>i가 아닌 c>=i를 해줬기 때문에 원소 2개일 때 break돼서 범위 지정 안해도됨
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