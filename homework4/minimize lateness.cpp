#include<iostream>
using namespace std;
//���ֵ����
int max(int a, int b) {
	if (a < b)return b;
	return a;
}
int main() {
	int n;
	cin >> n;
	int* T = new int[n];//���������Ҫ��ʱ��
	int* D = new int[n];//ddl
	int* F = new int[n];//�������ʱ��ʱ��
	for (int i = 0; i <= n - 1; i++) {
		cin >> T[i] >> D[i];
	}
	//����
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
	//����ÿ����������ʱ��ʱ��
	for (int i = 0; i <= n - 1; i++) {
		F[i] = start+T[i];
		start += T[i];//ÿ��һ������start��Ҫ���������������Ҫ��ʱ��
	}
	//max(0, F[i] - D[i])Ϊlateness
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