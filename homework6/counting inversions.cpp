#include<iostream>
using namespace std;
//合并数组
void Merge(int A[], int n, int begin, int mid, int end) {
	int* B = new int[n];
	int i = begin;
	int j = mid + 1;
	for (int k = 0; k <= n - 1; k++) {
		if (i > mid && j <= end) {
			B[k] = A[j];
			j++;
			continue;
		}
		if (j > end && i <= mid) {
			B[k] = A[i];
			i++;
			continue;
		}
		if (A[i] <= A[j]) {
			B[k] = A[i];
			i++;
		}
		else {
			B[k] = A[j];
			j++;
		}
	}
	for (int k = 0, h = begin; k <= n - 1; k++, h++) {
		A[h] = B[k];
	}
}
//归并排序
void mergesort(int A[], int n, int begin, int end) {
	if (n % 2 == 0) {
		mergesort(A, n / 2, begin, begin + n / 2 - 1);
		mergesort(A, n / 2, begin + n / 2, end);
		Merge(A, n, begin, begin + n / 2 - 1, end);
	}
	else {
		if (n == 1) {
			return;
		}
		mergesort(A, n / 2, begin, begin + n / 2 - 1);
		mergesort(A, n / 2 + 1, begin + n / 2, end);
		Merge(A, n, begin, begin + n / 2 - 1, end);
	}
}
//计算分别来自两部分的inversions
int total(int list[], int n, int begin, int mid, int end) {
	//先给两部分排序
	mergesort(list, mid - begin + 1, begin, mid);
	mergesort(list, end - mid, mid + 1, end);
	int i = begin;
	int j = mid + 1;
	int sum = 0;
	for (int k = 0; k <= n - 1; k++) {
		if (i > mid && j <= end) {
			j++;
			continue;
		}
		if (j > end && i <= mid) {
			i++;
			continue;
		}
		if (list[i] <= list[j]) {
			i++;
		}
		else {
			sum += mid - i + 1;
			j++;
		}
	}
	return sum;
}
//counting inversions
int count(int list[], int n,int begin,int end) {
	if (n % 2 == 0) {
		int a=count(list, n / 2, begin, begin + n / 2 - 1);
		int b=count(list, n / 2, begin + n / 2, end);
		return a + b + total(list, n, begin, begin + n / 2 - 1, end);
	}
	else {
		if (n == 1) {
			return 0;
		}
		int a= count(list, n / 2, begin, begin + n / 2 - 1);
		int b = count(list, n / 2 + 1, begin + n / 2, end);
		return a + b + total(list, n, begin, begin + n / 2 - 1, end);
	}
}
int main() {
	int n;
	cin >> n;
	int* list = new int[n];
	for (int i = 0; i <= n - 1; i++) {
		cin >> list[i];
	}
	cout << count(list, n, 0, n - 1);
	cout << endl;
	system("pause");
	return 0;
}