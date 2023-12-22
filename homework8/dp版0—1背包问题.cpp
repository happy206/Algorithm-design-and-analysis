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
	//��������
	int C;
	cin >> C;
	//��Ʒ����
	int n;
	cin >> n;
	//����ռ䡢��ֵ
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
	cout << "���濪ʼ���������������10�Σ������ÿ�ε�����ʱ�䣺" << endl;
	//ʵ��ʮ�Σ�ȡƽ��ʱ��
	clock_t sum_time = 0;
	for (int k = 1; k <= 10; k++) {
		start_time = clock();//��ȡ��ʼִ��ʱ��
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
		cout << "��"<<k<<"�ζ�̬�滮����ʱ��Ϊ ";
		cout << end_time - start_time << endl;
		sum_time += end_time - start_time;
	}
	cout << "10��ƽ������ʱ��Ϊ " << sum_time / 10;
	system("pause");
	return 0;
}