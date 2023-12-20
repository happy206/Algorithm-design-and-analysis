#include<iostream>
using namespace std;
int main() {
	int  n, m, a, b;
	cin >> n >> m >> a >> b;
	double value = (double)b / (double)m;//乘m次车的平均车费
	if (value >= n) {
		cout << n * a;
	}
	else {
		int i = 0;
		for (;;) {
			if (n > m) {
				i++;
				n = n - m;
			}//在不浪费的前提下，全用m次车的车票
			else {
				break;
			}
		}
		if (n * a <= b) {
			cout << i * b + n * a;
		}
		else {
			cout << i * b + b;
		}//如果b小，则即使用不到那么多次数，也要用m次车票
	}



}