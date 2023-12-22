#include<iostream>
#include<cmath>
using namespace std;
//合并数组
void Merge(double A[], double B[],int n, int begin, int mid, int end) {
	double* C = new double[n];
	double* D = new double[n];
	int i = begin;
	int j = mid + 1;
	for (int k = 0; k <= n - 1; k++) {
		if (i > mid && j <= end) {
			C[k] = A[j];
			D[k] = B[j];
			j++;
			continue;
		}
		if (j > end && i <= mid) {
			C[k] = A[i];
			D[k] = B[i];
			i++;
			continue;
		}
		if (A[i] <= A[j]) {
			C[k] = A[i];
			D[k] = B[i];
			i++;
		}
		else {
			C[k] = A[j];
			D[k] = B[j];
			j++;
		}
	}
	for (int k = 0, h = begin; k <= n - 1; k++, h++) {
		A[h] = C[k];
		B[h] = D[k];
	}
}
//归并排序
void mergesort(double A[],double B[], int n, int begin, int end) {
	if (n % 2 == 0) {
		mergesort(A,B, n / 2, begin, begin + n / 2 - 1);
		mergesort(A,B, n / 2, begin + n / 2, end);
		Merge(A,B, n, begin, begin + n / 2 - 1, end);
	}
	else {
		if (n == 1) {
			return;
		}
		mergesort(A,B, n / 2, begin, begin + n / 2 - 1);
		mergesort(A,B, n / 2 + 1, begin + n / 2, end);
		Merge(A,B, n, begin, begin + n / 2 - 1, end);
	}
}
//算七个点之间的最小距离
double shortest(double A[], double B[], int n,int begin,int end) {
	double a1 = (A[0] - A[1]) * (A[0] - A[1]) + (B[0] - B[1]) * (B[0] - B[1]), a2;//存储距离
	for (int i = begin; i <end; i++) {
		for (int j = i + 1; j <= end; j++) {
			a2 = (A[i] - A[j]) * (A[i] - A[j]) + (B[i] - B[j]) * (B[i] - B[j]);
			if (a2 < a1) {
				a1 = a2;
			}

		}
	}
	return a1;
}
//寻找最小距离点对
double Find(double x[], double y[], int n,int begin,int end) {
	if (n % 2 == 0) {
		if (n == 2) {
			double a = (x[begin] - x[end]) * (x[begin] - x[end]);
			double b = (y[begin] - y[end]) * (y[begin] - y[end]);
			return a + b;
		}
		else {
			double a = Find(x, y, n/2, begin, begin+n/2-1);
			double b = Find(x, y, n / 2, begin + n / 2, end);
			double c = (a > b) ? b : a;
			double* midx = new double[n];
			double* midy = new double[n];
			int count = 0;
			for (int i = 0; i <= n - 1; i++) {
				if (fabs(x[i] - x[begin + n / 2 - 1]) < c) {
					double o = x[i];
					double u = y[i];
					midx[i] = x[i];
					midy[i] = y[i];
					count++;
				}
			}
			if (count < 2) {
				return c;
			}
			else {
				mergesort(midy, midx, count, 0, count - 1);
				if (count <= 7) {
					double min = shortest(midx, midy, count, 0, count - 1);
					return (min > c) ? c : min;
				}
				else {
					for (int i = 0; i <= count - 7; i++) {
						double p = shortest(midx, midy, 7, i, i + 6);
						c = (c > p) ? p : c;
					}
					return c;
				}
			}
		}
	}
	else {
		if (n == 3) {
			double min;
			double a = (x[begin] - x[begin+1]) * (x[begin] - x[begin + 1]);
			double b = (y[begin] - y[begin+1]) * (y[begin] - y[begin + 1]);
			double c = (x[begin] - x[begin + 2]) * (x[begin] - x[begin + 2]);
			double d = (y[begin] - y[begin + 2]) * (y[begin] - y[begin + 2]);
			double e = (x[begin+1] - x[begin + 2]) * (x[begin + 1] - x[begin + 2]);
			double f = (y[begin+1] - y[begin + 2]) * (y[begin + 1] - y[begin + 2]);
			min = (a + b > c + d) ? (c + d) : (a + b);
			min = (min > e + f) ? (e + f) : min;
			return min;
		}
		else {
			double a = Find(x, y, n / 2, begin, begin + n / 2 - 1);
			double b = Find(x, y, n / 2 + 1, begin + n / 2, end);
			double c = (a > b) ? b : a;
			double* midx = new double[n];
			double* midy = new double[n];
			int count = 0;
			for (int i = 0; i <= n - 1; i++) {
				if (fabs(x[i] - x[begin + n / 2 - 1]) < c) {
					double o = x[i];
					double u = y[i];
					midx[i] = x[i];
					midy[i] = y[i];
					count++;
				}
			}
			if (count < 2) {
				return c;
			}
			else {
				mergesort(midy, midx, count, 0, count - 1);
				if (count <= 7) {
					double min = shortest(midx, midy, count, 0, count - 1);
					return (min > c) ? c : min;
				}
				else {
					for (int i = 0; i <= count - 7; i++) {
						double p = shortest(midx, midy, 7, i, i + 6);
						c = (c > p) ? p : c;
					}
					return c;
				}
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	double* X = new double[n];
	double* Y = new double[n];
	for (int i = 0; i <= n - 1; i++) {
		cin >> X[i] >> Y[i];
	}
	if (n == 1) {
		cout << 0;
		cout << endl;
		return 0;
	}
	mergesort(X, Y, n, 0, n - 1);
	cout << Find(X, Y, n, 0, n - 1);
	system("pause");
	return 0;
}