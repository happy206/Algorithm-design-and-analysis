#include<iostream>
using namespace std;
int main() {
	int n;
	cout << "请输入第一个数组的数量：" << endl;
	cout << "n= ";
	cin >> n;
	int* A = new int[n];
	cout << "请输入第一个数组：" << endl;
	cout << "A[]= ";
	for (int i = 0; i <= n - 1; i++) {
		cin >> A[i];
	}
	int m;
	cout << "请输入第二个数组的数量：" << endl;
	cout << "m= ";
	cin >> m;
	int* B = new int[m];
	cout << "请输入第二个数组：" << endl;
	cout << "B[]= ";
	for (int i = 0; i <= m - 1; i++) {
		cin >> B[i];
	}
	int* P = new int[n + m];
	cout << "下面将按升序合并两个数组" << endl;
	//A是升序数组，B也是升序数组
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
				}//如果j=m-1，说明B数组的数全到P数组了，所以接下来只需把A的数放到P中即可
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
	//A是升序数组，B是降序数组
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
	//A是降序数组，B是升序数组
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
	//A是降序数组，B也是降序数组
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