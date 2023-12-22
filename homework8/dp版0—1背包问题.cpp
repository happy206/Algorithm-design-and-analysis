#include<iostream>
#include<time.h>
using namespace std;
int bag(int** V,int v[],int w[], int n, int C) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= C; j++) {
			if (j < w[i-1]) {
				V[i][j] = V[i - 1][j];
			}
			else {
				if (V[i - 1][j] > V[i - 1][j - w[i-1]] + v[i-1]) {
					V[i][j] = V[i - 1][j];
				}
				else {
					V[i][j] = V[i - 1][j - w[i-1]] + v[i-1];
				}
			}
		}
	}
	return V[n][C];
}
int main() {
	//背包容量
	int C;
	cin >> C;
	//物品数量
	int n;
	cin >> n;
	//输入空间、价值
	int* w = new int[n];
	int* v = new int[n];
	for (int i = 0; i <= n - 1; i++) {
		cin >> w[i]>> v[i];
	}
	clock_t start_time, end_time;
	int** V = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		V[i] = new int[C + 1];
	}
	for (int i = 0; i <= n; i++) {
		V[i][0] = 0;
	}
	for (int i = 0; i <= C; i++) {
		V[0][i] = 0;
	}
	cout << bag(V, v, w, n, C) << endl;
	cout << "下面开始按上面的样例运行10次，并输出每次的运行时间：" << endl;
	//实验十次，取平均时间
	clock_t sum_time = 0;
	for (int k = 1; k <= 10; k++) {
		start_time = clock();//获取开始执行时间
		int** V1 = new int* [n + 1];
		for (int i = 0; i <= n; i++) {
			V1[i] = new int[C + 1];
		}
		for (int i = 0; i <= n; i++) {
			V1[i][0] = 0;
		}
		for (int i = 0; i <= C; i++) {
			V1[0][i] = 0;
		}
		bag(V, v, w, n, C);
		end_time = clock();
		cout << "第"<<k<<"次动态规划运行时间为 ";
		cout << end_time - start_time << endl;
		sum_time += end_time - start_time;
	}
	cout << "10次平均运行时间为 " << sum_time / 10;
	system("pause");
	return 0;
}