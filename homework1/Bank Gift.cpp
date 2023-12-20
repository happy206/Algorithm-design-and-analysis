#include<iostream>
using namespace std;
int main() {
	char A[13];
	cin >> A;
	int i = 0;
	//负数，则比较最后两位数的大小
	if (A[0] == '-') {
		for (;; i++) {
			if (A[i + 1] == '\0') {
				if (A[i] >= A[i - 1]) {
					A[i] = '\0';
					break;
				}
				else {
					A[i - 1] = A[i];
					A[i] = '\0';
					break;
				}
			}
		}
		if (A[1] == '0') {
			cout << 0;
		}//为0的时候，负号不输出
		else {
			cout << A;
		}
	}
	else {
		cout << A;
	}//如果是正数，则不变
}