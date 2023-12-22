#include<iostream>
using namespace std;
bool reasonable(int* A, int index,int number) {
	bool t = true;
	for (int i = 0; i < index; i++) {
		if (A[i] == number) {
			t = false;
			break;
		}
	}
	return t;
}
void print(int* A, int n) {
	for (int i = 0; i <= n - 1; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
int main() {
	int n;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i <= n - 1; i++) {
		A[i] = 0;
	}
	int k = 0;
	while (true) {
		while (true) {
			A[k] += 1;
			int a = A[k];
			if (A[k] > n) {
				break;
			}
			bool t = reasonable(A, k, A[k]);
			if ( k == n - 1&& t) {
				print(A, n);
			}
			if (k != n - 1&&t) {
				k++;
			}
		}
		A[k] = 0;
		int b = A[k];
		k--;
		if (k < 0)break;
	}
	system("pause");
	return 0;
}