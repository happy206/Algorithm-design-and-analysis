#include<iostream>
#include<time.h>
#include<cmath>
using namespace std;
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
		cin >> w[i] >> v[i];
	}
	//����ģ��2^n�����
	int* A = new int[n];
	clock_t start_time, end_time;
	for (int i = 0; i <= n - 1; i++) {
		A[i] = 0;
	}
	int sum_w = 0;
	int sum_v = 0;
	int max = 0;
	bool up =false;
	for (int i = 0; i <= pow(2, n); i++) {
			for (int j = 0; j <= n - 1; j++) {
				//ÿִ��һ�Σ�������A������Ķ�������+1
				if (up) {
					if (A[j] == 0) {
						A[j] = 1;
						up = false;
					}
					else {
						A[j] = 0;
					}
				}
				if (A[j] != 0) {
					if (sum_w + w[j] <= C) {
						sum_w += w[j];
						sum_v += v[j];
					}
				}
				if (j == n - 1) {
					if (max < sum_v) {
						max = sum_v;
					}
				}
			}
			sum_w = 0;
			sum_v = 0;
			up = true;
	}
	cout << max << endl;
	cout << "���濪ʼ���������������10�Σ������ÿ�ε�����ʱ�䣺" << endl;
	clock_t sum_time = 0;
	for (int k = 1; k <= 10; k++) {
		start_time = clock();//��ȡ��ʼִ��ʱ��
		for (int i = 0; i <= n - 1; i++) {
			A[i] = 0;
		}
		 sum_w = 0;
		 sum_v = 0;
		 max = 0;
		 up = false;
		for (int i = 0; i <= pow(2, n); i++) {
			for (int j = 0; j <= n - 1; j++) {
				//ÿִ��һ�Σ�������A������Ķ�������+1
				if (up) {
					if (A[j] == 0) {
						A[j] = 1;
						up = false;
					}
					else {
						A[j] = 0;
					}
				}
				if (A[j] != 0) {
					if (sum_w + w[j] <= C) {
						sum_w += w[j];
						sum_v += v[j];
					}
				}
				if (j == n - 1) {
					if (max < sum_v) {
						max = sum_v;
					}
				}
			}
			sum_w = 0;
			sum_v = 0;
			up = true;
		}
		end_time = clock();
		cout << "��"<<k<<"������ʱ��Ϊ: ";
		cout << end_time - start_time << endl;
		sum_time += end_time - start_time;
	}
	cout << "10��ƽ������ʱ��Ϊ " << sum_time / 10;
	system("pause");
	return 0;
}