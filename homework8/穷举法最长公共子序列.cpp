#include<iostream>
#include<string>
#include<cmath>
using namespace std;
void max(char* A, char* B, int n, int m) {
	//����ģ��2^n�����
	int* k = new int[n];
	for (int i = 0; i <= n - 1; i++) {
		k[i] = 0;
	}
	//�����洢A������������
	char* tmp = new char[n + 1];
	//�Ƿ��λ
	bool up = false;
	//��������ĳ���
	int max = 0;
	//�������
	char* maxstring = new char[m + 1];
	for (int i = 1; i <= pow(2, n); i++) {
		//��A�����������и���tmp
		int index = 0;
		for (int j = 0; j <= n - 1; j++) {
			//ÿִ��һ�Σ�������k������Ķ�������+1
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
		//���tmp�Ƿ���B��������
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
	cout << "���濪ʼ���������������10�Σ������ÿ�ε�����ʱ�䣺" << endl;
	for (int i = 1; i <= 10; i++) {
		start_time = clock();//��ȡ��ʼִ��ʱ��
		cout << "��" << i << "������㷨���н��:";
		max(A, B, n, m);
		end_time = clock();
		cout << "         ��" << i << "������㷨����ʱ��:";
		cout << end_time - start_time << endl;
		sum_time += end_time - start_time;
	}
	cout << "10��ƽ������ʱ��Ϊ " << sum_time / 10;
	system("pause");
	return 0;
}