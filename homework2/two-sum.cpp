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
	bool t = false;
	int n;
	cout << "请输入数组的长度" << endl;
	cout << "n=";
	cin >> n;
	int T;
	cout << "请输入目标数" << endl;
	cout << "T=";
	cin >> T;
	int* A = new int[n];
	cout << "请输入数组A" << endl;
	cout << "A[]=";
	for (int i = 0; i <= n - 1; i++) {
		cin >> A[i];
	}
	int type;
	cout << "请输入算法类型： " << endl;
	cout << "输入 1 用 O(n2) 算法" << endl;
	cout << "输入 2 用 O(nlogn) 算法" << endl;
	cout << "输入 3 用 O(n) 算法" << endl;
	cout << "type=";
	cin >> type;
	if (type != 1 && type != 2 && type != 3) {
		cout << "没有该类型！";
		system("pause");
		return 0;
	}
	cout << "下面输出和为" << T << "的两个数" << endl;
	// O(n2) 算法
	if (type == 1) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i+1; j <= n - 1; j++) {
				if (A[i] + A[j] == T) {
					cout << "("<<A[i] << "," << A[j]<<")" << endl;
					t = true;
				}
			}
		}
		if (!t) {
			cout << "不存在！" << endl;
		}
		system("pause");
		return 0;
	}
	// O(nlogn) 算法

	if (type == 2) {
		//数组为升序的情况
		if (n > 1 && A[0] < A[1]) {
			for (int i = 0; i < n - 1; i++) {
				int a = binary_search_low_to_high(A, i + 1, n - 1, T - A[i]);
				if (a!=-1&& A[a]!=A[i]) {
					cout << "(" << A[i] << "," << A[a] << ")" << endl;
					t = true;
				}
			}
		}
		//数组为降序的情况
		else {
			for (int i = 0; i < n - 1; i++) {
				int a = binary_search_high_to_low(A, i + 1, n - 1, T - A[i]);
				if (a != -1 && A[a] != A[i]) {
					cout << "(" << A[i] << "," << A[a] << ")" << endl;
					t = true;
				}
			}
		}
		if (!t) {
			cout << "不存在！" << endl;
		}
		system("pause");
		return 0;
	}
	// O(n) 算法  
	if (type == 3) {
		//数组为升序
		if (n > 1 && A[0] < A[1]) {
			for (int i = 0, j = n - 1; i<j;) {
				if (i == j)break;
				if (A[i] + A[j] == T) {
					cout << "(" << A[i] << "," << A[j] << ")" << endl;
					t = true;
					i++;
					j--;
				}
				if (A[i] + A[j] > T) {
					j--;
				}
				if (A[i] + A[j] < T) {
					i++;
				}
			}
		}
		//数组为降序
		if (n == 1 || (n > 1 && A[0] > A[1])) {
			for (int i = 0, j = n - 1; i<j;) {
				if (i == j)break;
				if (A[i] + A[j] == T) {
					cout << "(" << A[i] << "," << A[j] << ")" << endl;
					t = true;
					i++;
					j--;
				}
				if (A[i] + A[j] > T) {
					i++;
				}
				if (A[i] + A[j] < T) {
					j--;
				}
			}
		}
		if (!t) {
			cout << "不存在！" << endl;
		}
		system("pause");
		return 0;
	}
}