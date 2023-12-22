#include<iostream>
#include<time.h>
using namespace std;
int maxstring(char* A, char* B, int n, int m,int**C) {
	for (int i = 0; i <= n ; i++) {
		C[i][0] = 0;
	}
	for (int j = 0; j <= m ; j++) {
		C[0][j] = 0;
	}
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= m ; j++) {
			if (A[i - 1] == B[j - 1]) {
				C[i][j] = C[i - 1][j - 1]+1;
			}
			else {
				if (C[i][j - 1] > C[i - 1][j]) {
					C[i][j] = C[i][j - 1];
				}
				else {
					C[i][j] = C[i-1][j];
				}
			}
		}
	}
	//打印最长子序列
	char* max = new char[C[n][m]+1];
	max[C[n][m]] = '\0';
	int index = C[n][m]-1;
	int i = n;
	int j = m;
	while (true) {
		if (A[i-1] == B[j-1]) {
			max[index] = A[i-1];
			i--;
			j--;
			index--;
		}
		else {
			if (C[i - 1][j] > C[i][j - 1]) {
				i--;
				continue;
			}
			if (C[i - 1][j] < C[i][j - 1]) {
				j--;
				continue;
			}
			if (C[i - 1][j] == C[i][j - 1]) {
				if (i > 1) {
					i--;
				}
				else {
					j--;
				}
			}
		}
		if (index<0) {
			break;
		}
		
	}
	cout << max << "    ";
	return C[n][m];
}
int main() {
	int n, m;
	cin >> n >> m;
	char* A = new char[n];
	char* B = new char[m];
	cin >> A >> B;
	int** C = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		C[i] = new int[m + 1];
	}
	clock_t start_time, end_time;
	double sum_time = 0;
	cout << maxstring(A, B, n, m,C) << endl;
	cout << "下面开始按上面的样例运行10次，并输出每次的运行时间：" << endl;
	for (int i = 1; i <= 10; i++) {
		start_time = clock();//获取开始执行时间
		cout << "第" << i << "次动态规划算法运行结果:";
		cout << maxstring(A, B, n, m, C) << "   ";
		end_time = clock();
		cout << "第" << i << "次动态规划算法运行时间:";
		cout << end_time - start_time << endl;
		sum_time += end_time - start_time;
	}
	cout << "10次平均运行时间为 " << sum_time / 10;
	system("pause");
	return 0;
}