#include<iostream>
using namespace std;
int main() {
	int n;
	cout << "�������һ�������������" << endl;
	cout << "n= ";
	cin >> n;
	int* A = new int[n];
	cout << "�������һ�����飺" << endl;
	cout << "A[]= ";
	for (int i = 0; i <= n - 1; i++) {
		cin >> A[i];
	}
	int m;
	cout << "������ڶ��������������" << endl;
	cout << "m= ";
	cin >> m;
	int* B = new int[m];
	cout << "������ڶ������飺" << endl;
	cout << "B[]= ";
	for (int i = 0; i <= m - 1; i++) {
		cin >> B[i];
	}
	int* P = new int[n + m];
	cout << "���潫������ϲ���������" << endl;
	//A���������飬BҲ����������
	if ((n > 1 && A[1] > A[0]) && (m > 1 && B[1] > B[0])) {
		for (int i = 0, j = 0,k=0;k<=m+n-1 ;k++) {
			if (A[i] > B[j]) {
				P[k] = B[j];
				if (j < m - 1) {
					j++;
				}
				else {
					for (k+=1; k <= m + n - 1; k++) {
						P[k] = A[i];
						i++;
					}
				}//���j=m-1��˵��B�������ȫ��P�����ˣ����Խ�����ֻ���A�����ŵ�P�м���
		    }
			else {
				P[k] = A[i];
				if (i < n - 1) {
					i++;
				}
				else {
					for (k += 1; k <= m + n - 1; k++) {
						P[k] = B[j];
						j++;
					}
				}
			}
		}
		for (int i = 0; i <= m + n - 1; i++) {
			cout << P[i] << " ";
		}
	}
	//A���������飬B�ǽ�������
	if ((n > 1 && A[1] > A[0]) && ((m > 1 && B[1] <= B[0])||m==1)) {
		for (int i = 0, j = m-1,k=0;k<=m+n-1 ;k++) {
			if (A[i] > B[j]) {
				P[k] = B[j];
				if (j > 0) {
					j--;
				}
				else {
					for (k += 1; k <= m + n - 1; k++) {
						P[k] = A[i];
						i++;
					}
				}
			}
			else {
				P[k] = A[i];
				if (i < n - 1) {
					i++;
				}
				else {
					for (k += 1; k <= m + n - 1; k++) {
						P[k] = B[j];
						j--;
					}
				}
			}
		}
		for (int i = 0; i <= m + n - 1; i++) {
			cout << P[i] << " ";
		}
	}
	//A�ǽ������飬B����������
    if (((n > 1 && A[1] <= A[0])||n==1) && (m > 1 && B[1] > B[0])) {
	    for (int i = n-1, j = 0,k=0; k<=m+n-1;k++) {
			if (A[i] > B[j]) {
				P[k] = B[j];
				if (j < m - 1) {
					j++;
				}
				else {
					for (k += 1; k <= m + n - 1; k++) {
						P[k] = A[i];
						i--;
					}
				}
			}
			else {
				P[k] = A[i];
				if (i > 0) {
					i--;
				}
				else {
					for (k += 1; k <= m + n - 1; k++) {
						P[k] = B[j];
						j++;
					}
				}
			}
	    }
		for (int i = 0; i <= m + n - 1; i++) {
			cout << P[i] << " ";
		}
    }
	//A�ǽ������飬BҲ�ǽ�������
	if (((n > 1 && A[1] <= A[0]) || n == 1) && ((m > 1 && B[1] <= B[0]) || m == 1)) {
		for (int i = n-1, j = m-1,k=0; k<=m+n-1;k++) {
			if (A[i] > B[j]) {
				P[k] = B[j];
				if (j > 0) {
					j--;
				}
				else {
					for (k += 1; k <= m + n - 1; k++) {
						P[k] = A[i];
						i--;
					}
				}
			}
			else {
				P[k] = A[i];
				if (i > 0) {
					i--;
				}
				else {
					for (k += 1; k <= m + n - 1; k++) {
						P[k] = B[j];
						j--;
					}
				}
			}
		}
		for (int i = 0; i <= m + n - 1; i++) {
			cout << P[i] << " ";
		}
	}
	system("pause");
	return 0;
}