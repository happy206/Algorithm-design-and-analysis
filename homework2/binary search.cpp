#include<iostream>
using namespace std;
//升序数组查找
//m为数字序列开头的索引，n为数字序列末尾的索引
int binary_search_low_to_high(int A[], int m, int n, int x) {
	if (m == n && A[(m + n) / 2] != x) {
		return -1;//意味着没有这个数
	}
	if (A[(m + n) / 2] == x) {
		return (m + n) / 2;
	}
	else {
		if (A[(m + n) / 2] > x) {
			if ((m + n) / 2 - 1 < m) {
				binary_search_low_to_high(A, m, m, x);
			}
			else {
				binary_search_low_to_high(A, m, (m + n) / 2 - 1, x);
			}
		}
		else {
			binary_search_low_to_high(A, (m + n) / 2 + 1, n, x);
		}
	}
}
//降序数组查找
//m为数字序列开头的索引，n为数字序列末尾的索引
int binary_search_high_to_low(int A[], int m, int n, int x) {
	if (m == n && A[(m + n) / 2] != x) {
		return -1;
	}
	if (A[(m + n) / 2] == x) {
		return (m + n) / 2;
	}
	else {
		if (A[(m + n) / 2] < x) {
			if ((m + n) / 2 - 1 < m) {
				binary_search_high_to_low(A, m, m, x);
			}
			else {
				binary_search_high_to_low(A, m, (m + n) / 2 - 1, x);
			}
		}
		else {
			binary_search_high_to_low(A, (m + n) / 2 + 1, n, x);
		}
	}
}
int main() {
	cout << "请输入数组的长度" << endl;
	cout << "n= ";
	int n;
	cin >> n;
	if (n <= 0) {
		cout << "输入不合理！";
		system("pause");
		return 0;
	}
	cout << "请输入数组" << endl;
	cout << "A[]= ";
	int* A = new int[n];
	for (int i = 0; i <= n - 1; i++) {
		cin >> A[i];
	}
	cout << "请输入x" << endl;
	cout << "x= ";
	int x;
	cin >> x;
	if (n > 1 && A[1] <= A[0]) {
		if (binary_search_high_to_low(A, 0, n - 1, x) == -1) {
			cout << "没有这个数！";
		}
		else {
			cout << "the index of x in array A is " << binary_search_high_to_low(A, 0, n - 1, x);
		}
	}
	else {
		if (binary_search_low_to_high(A, 0, n - 1, x) == -1) {
			cout << "没有这个数！";
		}
		else {
			cout << "the index of x in array A is " << binary_search_low_to_high(A, 0, n - 1, x);
		}
	}
	system("pause");
	return 0;
}