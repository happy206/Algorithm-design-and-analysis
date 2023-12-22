#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n;
	cout << "请输入点的个数" << endl;
	cout << "n=";
	cin >> n;
	double* A = new double[n];
	double* B = new double[n];
	cout << "请输入点的坐标" << endl;
	for (int i = 0; i <= n - 1; i++) {
		cin >> A[i] >> B[i];
	}
	double a1=sqrt((A[0]-A[1])* (A[0] - A[1])+ (B[0] - B[1]) * (B[0] - B[1])), a2;//存储距离
	int x=0, y=1;//存储坐标
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			a2 = sqrt((A[i] - A[j]) * (A[i] - A[j]) + (B[i] - B[j]) * (B[i] - B[j]));
			if (a2 < a1) {
				a1 = a2;
				x = i;
				y = j;
			}//遇到更小的就交换

		}
	}
	cout << "(" << A[x] << "," << B[x] << ") 和" << "(" << A[y] << "," << B[y] << ")";
	system("pause");
	return 0;
}