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
	bool t = false;
	int n;
	cout << "����������ĳ���" << endl;
	cout << "n=";
	cin >> n;
	int T;
	cout << "������Ŀ����" << endl;
	cout << "T=";
	cin >> T;
	int* A = new int[n];
	cout << "����������A" << endl;
	cout << "A[]=";
	for (int i = 0; i <= n - 1; i++) {
		cin >> A[i];
	}
	int type;
	cout << "�������㷨���ͣ� " << endl;
	cout << "���� 1 �� O(n2) �㷨" << endl;
	cout << "���� 2 �� O(nlogn) �㷨" << endl;
	cout << "���� 3 �� O(n) �㷨" << endl;
	cout << "type=";
	cin >> type;
	if (type != 1 && type != 2 && type != 3) {
		cout << "û�и����ͣ�";
		system("pause");
		return 0;
	}
	cout << "���������Ϊ" << T << "��������" << endl;
	// O(n2) �㷨
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
			cout << "�����ڣ�" << endl;
		}
		system("pause");
		return 0;
	}
	// O(nlogn) �㷨

	if (type == 2) {
		//����Ϊ��������
		if (n > 1 && A[0] < A[1]) {
			for (int i = 0; i < n - 1; i++) {
				int a = binary_search_low_to_high(A, i + 1, n - 1, T - A[i]);
				if (a!=-1&& A[a]!=A[i]) {
					cout << "(" << A[i] << "," << A[a] << ")" << endl;
					t = true;
				}
			}
		}
		//����Ϊ��������
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
			cout << "�����ڣ�" << endl;
		}
		system("pause");
		return 0;
	}
	// O(n) �㷨  
	if (type == 3) {
		//����Ϊ����
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
		//����Ϊ����
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
			cout << "�����ڣ�" << endl;
		}
		system("pause");
		return 0;
	}
}