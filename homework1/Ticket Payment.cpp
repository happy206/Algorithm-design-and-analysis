#include<iostream>
using namespace std;
int main() {
	int  n, m, a, b;
	cin >> n >> m >> a >> b;
	double value = (double)b / (double)m;//��m�γ���ƽ������
	if (value >= n) {
		cout << n * a;
	}
	else {
		int i = 0;
		for (;;) {
			if (n > m) {
				i++;
				n = n - m;
			}//�ڲ��˷ѵ�ǰ���£�ȫ��m�γ��ĳ�Ʊ
			else {
				break;
			}
		}
		if (n * a <= b) {
			cout << i * b + n * a;
		}
		else {
			cout << i * b + b;
		}//���bС����ʹ�ò�����ô�������ҲҪ��m�γ�Ʊ
	}



}