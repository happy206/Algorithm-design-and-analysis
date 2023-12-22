#include<iostream>
using namespace std;
//合并数组
void Merge(int A[], int n, int begin,int mid, int end) {
	int* B = new int[n];
	int i = begin;
	int j = mid + 1;
	for (int k = 0; k <= n - 1; k++) {
		if (i > mid&&j<=end) {
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
	for (int k = 0,h=begin; k <= n - 1; k++,h++) {
		A[h] = B[k];
	}
}
//归并排序
void mergesort(int A[],int n,int begin,int end) {
	if (n % 2 == 0) {
		mergesort(A, n / 2, begin,begin +n / 2-1);
		mergesort(A, n / 2, begin+n/2 , end);
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
int main() {
	int n;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i <= n - 1; i++) {
		cin >> A[i];
	}
	mergesort(A, n, 0, n - 1);
	for (int i = 0; i <= n - 1; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}