#include<iostream>
#include<string>
#include<cmath>
using namespace std;
void max(char* A, char* B, int n, int m) {
	//用来模拟2^n个情况
	int* k = new int[n];
	for (int i = 0; i <= n - 1; i++) {
		k[i] = 0;
	}
	//用来存储A的所有子序列
	char* tmp = new char[n + 1];
	//是否进位
	bool up = false;
	//子序列最长的长度
	int max = 0;
	//最长子序列
	char* maxstring = new char[m + 1];
	for (int i = 1; i <= pow(2, n); i++) {
		//将A的所有子序列赋给tmp
		int index = 0;
		for (int j = 0; j <= n - 1; j++) {
			//每执行一次，让数组k所代表的二进制数+1
			if (up) {
				if (k[j] == 0) {
					k[j] = 1;
					up = false;
				}
				else {
					k[j] = 0;
				}
			}
			if (i == 1) {
				tmp[index] = '\0';
				break;
			}
			else {
				if (k[j] == 0) {
					continue;
				}
				else {
					tmp[index] = A[j];
					index++;
				}
			}
		}
		tmp[index] = '\0';
		//检查tmp是否是B的子序列
		int length = strlen(tmp);
		bool exist = true;
		int p = 0;
		for (int h = 0; h <= index - 1; h++) {
			bool keep = false;
			for (; p <= m - 1; p++) {
				if (B[p] == tmp[h]) {
					keep = true;
					if (h == index - 1) {
						exist = true;
						break;
					}
					else {
						p++;
						break;
					}
				}
			}
			if (!keep) {
				exist = false;
				break;
			}
		}
		if (exist) {
			if (max <= length) {
				max = length;
				for (int h = 0; h <= index - 1; h++) {
					maxstring[h] = tmp[h];
				}
				maxstring[index] = '\0';
			}
		}
		up = true;
	}
	if (max == 0) {
		maxstring[0] = '\0';
	}
	cout << max << "   ";
	cout << maxstring ;
}
int main() {
	int n, m;
	cin >> n >> m;
	char* A = new char[n+1];
	cin >> A;
	char* B = new char[m+1];
	cin >> B;
	max(A, B, n, m);
	cout << endl;
	clock_t start_time, end_time;
	double sum_time = 0;
	cout << "下面开始按上面的样例运行10次，并输出每次的运行时间：" << endl;
	for (int i = 1; i <= 10; i++) {
		start_time = clock();//获取开始执行时间
		cout << "第" << i << "次穷举算法运行结果:";
		max(A, B, n, m);
		end_time = clock();
		cout << "         第" << i << "次穷举算法运行时间:";
		cout << end_time - start_time << endl;
		sum_time += end_time - start_time;
	}
	cout << "10次平均运行时间为 " << sum_time / 10;
	system("pause");
	return 0;
}