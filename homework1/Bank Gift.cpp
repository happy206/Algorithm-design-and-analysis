#include<iostream>
using namespace std;
int main() {
	char A[13];
	cin >> A;
	int i = 0;
	//��������Ƚ������λ���Ĵ�С
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
		}//Ϊ0��ʱ�򣬸��Ų����
		else {
			cout << A;
		}
	}
	else {
		cout << A;
	}//������������򲻱�
}