#include<iostream>
using namespace std;
//�����������
//mΪ�������п�ͷ��������nΪ��������ĩβ������
int binary_search_low_to_high(int A[], int m, int n, int x) {
	if (m == n && A[(m + n) / 2] != x) {
		return -1;//��ζ��û�������
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
//�����������
//mΪ�������п�ͷ��������nΪ��������ĩβ������
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
	cout << "����������ĳ���" << endl;
	cout << "n= ";
	int n;
	cin >> n;
	if (n <= 0) {
		cout << "���벻����";
		system("pause");
		return 0;
	}
	cout << "����������" << endl;
	cout << "A[]= ";
	int* A = new int[n];
	for (int i = 0; i <= n - 1; i++) {
		cin >> A[i];
	}
	cout << "������x" << endl;
	cout << "x= ";
	int x;
	cin >> x;
	if (n > 1 && A[1] <= A[0]) {
		if (binary_search_high_to_low(A, 0, n - 1, x) == -1) {
			cout << "û���������";
		}
		else {
			cout << "the index of x in array A is " << binary_search_high_to_low(A, 0, n - 1, x);
		}
	}
	else {
		if (binary_search_low_to_high(A, 0, n - 1, x) == -1) {
			cout << "û���������";
		}
		else {
			cout << "the index of x in array A is " << binary_search_low_to_high(A, 0, n - 1, x);
		}
	}
	system("pause");
	return 0;
}