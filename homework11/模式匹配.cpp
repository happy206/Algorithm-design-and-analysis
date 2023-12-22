#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
//���ٻ�ȡģ
long long Quick_Multiply(long long a, long long b, long long mod) {
	long long result = 0;
	while (b) {
		if (b & 1) {
			result = (result + a) % mod;
		}
		a = (a * 2) % mod;
		b >>= 1;
	}
	return result % mod;
}
//������ȡģ
long long Quick_Power(long long a, long long n, long long mod) {
	long long result = 1;
	while (n) {
		if (n & 1) {
			result = Quick_Multiply(result, a, mod);//result=(result*a)%mod
		}
		a = Quick_Multiply(a, a, mod);//a=(a*a)%mod
		n >>= 1;
	}
	return result % mod;
}
//�������ߵ�ֵ
int max(int count[], int n) {
	int index = 0;
	for (int i = 1; i <= n - 1; i++) {
		if (count[i] >= count[index]) {
			index = i;
		}
	}
	return index;
}
// �ж�һ�����Ƿ�Ϊ����
bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

// ��С��M�������������ѡ��һ������
int selectRandomPrime(int M) {
	vector<int> primes; // �洢������
	for (int i = 2; i < M; ++i) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}
	// ʹ�������������ѡ��һ������
	int index = rand() % (primes.size()-1);
	return primes[index];
}
//����Ȩֵ
//������Сд��26����ĸ�������ҽ��������26������
//����26�Ƚϴ������ÿ���ģ������26^n����ֹ���
long long Weight(char* Y, int m,int p) {
	long Wp = 0;
	int n = 0;
	for (int i = m-1; i >=0 ; i--) {
		Wp += (Y[i] - 97)*Quick_Power(26,n,p);
		n++;
	}
	return Wp;
}
//����ģp
long long mod(long long &a, long long p) {
	a = a % p;
	if (a < 0) {
		a += p;
	}
	return a;
}
int match(char* X,int n,char* Y,int m,int M) {
		int p = selectRandomPrime(M);
		long long Wy = Weight(Y, m,p);
		long long Wx = Weight(X, m,p);
		int index = 0;
		for (; index < n - m + 1; index++) {
			if (mod(Wy, p) == mod(Wx, p)) {
				return index;
			}
			Wx = 26 * Wx + (X[index + m]-97) - Quick_Power(26,m,p) * (X[index] - 97);
		}
	return -1;
}
int main() {
	cout << "��Ҫ�����볤���ַ�����" << endl;
	cout << "���ֻ������100���ȵ��ַ�����" << endl;
	char* X = new char[100];
	char* Y = new char[100];
	cin >> X;
	cin >> Y;
	srand(time(0));
	int n = strlen(X);
	int m = strlen(Y);
	int M = 2 * n * n;
	int* count = new int[n - m + 1];
	for (int i = 0; i <= n-m; i++) {
		count[i] = 0;
	}
	//����10�Σ���С������
	for (int i = 1; i <= 10; i++) {
		count[match(X, n, Y, m, M)]++;
	}
	cout << max(count, n - m + 1) << endl;
	system("pause");
	return 0;
}