#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
//快速积取模
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
//快速幂取模
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
//求概率最高的值
int max(int count[], int n) {
	int index = 0;
	for (int i = 1; i <= n - 1; i++) {
		if (count[i] >= count[index]) {
			index = i;
		}
	}
	return index;
}
// 判断一个数是否为素数
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

// 从小于M的素数集中随机选择一个素数
int selectRandomPrime(int M) {
	vector<int> primes; // 存储素数集
	for (int i = 2; i < M; ++i) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}
	// 使用随机数生成器选择一个素数
	int index = rand() % (primes.size()-1);
	return primes[index];
}
//计算权值
//由于是小写的26个字母，所以我将它想象成26进制数
//由于26比较大，所以用快速模幂来算26^n，防止溢出
long long Weight(char* Y, int m,int p) {
	long Wp = 0;
	int n = 0;
	for (int i = m-1; i >=0 ; i--) {
		Wp += (Y[i] - 97)*Quick_Power(26,n,p);
		n++;
	}
	return Wp;
}
//计算模p
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
	cout << "需要先输入长的字符串！" << endl;
	cout << "最大只能输入100长度的字符串！" << endl;
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
	//测试10次，减小错误率
	for (int i = 1; i <= 10; i++) {
		count[match(X, n, Y, m, M)]++;
	}
	cout << max(count, n - m + 1) << endl;
	system("pause");
	return 0;
}