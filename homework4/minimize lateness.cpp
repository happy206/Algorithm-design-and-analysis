#include<iostream>
using namespace std;
//最大值函数
int max(int a, int b) {
	if (a < b)return b;
	return a;
}
int main() {
	int n;
	cin >> n;
	int* T = new int[n];//任务完成需要的时间
	int* D = new int[n];//ddl
	int* F = new int[n];//任务完成时的时间
	for (int i = 0; i <= n - 1; i++) {
		cin >> T[i] >> D[i];
	}
	//排序
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			if (D[i] > D[j]) {
				int tmp1 = T[i];
				int tmp2 = D[i];
				T[i] = T[j];
				T[j] = tmp1;
				D[i] = D[j];
				D[j] = tmp2;
			}
		}
	}
	int start = 0;
	//计算每个任务的完成时的时间
	for (int i = 0; i <= n - 1; i++) {
		F[i] = start+T[i];
		start += T[i];//每加一个任务，start就要加这个任务的完成需要的时间
	}
	//max(0, F[i] - D[i])为lateness
	int lateness = max(0, F[0] - D[0]);
	for (int i = 1; i <= n - 1; i++) {
		if (lateness < max(0, F[i] - D[i])) {
			lateness = max(0, F[i] - D[i]);
		}
	}
	cout << lateness;
	system("pause");
	return 0;
}