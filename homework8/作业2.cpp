#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}
//字符串转数字
void exchange(int& a, char* s) {
	a = 0;
	for (int i = 0; i <= strlen(s) - 1; i++) {
		if (s[i] == '0') {
			a = a * 10 + 0;
			continue;
		}
		if (s[i] == '1') {
			a = a * 10 + 1;
			continue;
		}
		if (s[i] == '2') {
			a = a * 10 + 2;
			continue;
		}
		if (s[i] == '3') {
			a = a * 10 + 3;
			continue;
		}
		if (s[i] == '4') {
			a = a * 10 + 4;
			continue;
		}
		if (s[i] == '5') {
			a = a * 10 + 5;
			continue;
		}
		if (s[i] == '6') {
			a = a * 10 + 6;
			continue;
		}
		if (s[i] == '7') {
			a = a * 10 + 7;
			continue;
		}
		if (s[i] == '8') {
			a = a * 10 + 8;
			continue;
		}
		if (s[i] == '9') {
			a = a * 10 + 9;
			continue;
		}
	}
}
//数字转字符串
char* change(int a) {
	char* tmp1= new char[10];
	char* tmp2 = new char[10];
	if (a == 0) {
		tmp2[0] = '0';
		tmp2[1] = '\0';
		return tmp2;
	}
	int n = 0;
	for (int i = 0;; i++) {
		n = a % 10;
		if (a == 0) {
			tmp1[i] = '\0';
			break;
		}
		if (n == 0) {
			tmp1[i] = '0';
			a = a / 10;
			continue;
		}
		if (n == 1) {
			tmp1[i] = '1';
			a = a / 10;
			continue;
		}
		if (n == 2) {
			tmp1[i] = '2';
			a = a / 10;
			continue;
		}
		if (n == 3) {
			tmp1[i] = '3';
			a = a / 10;
			continue;
		}
		if (n == 4) {
			tmp1[i] = '4';
			a = a / 10;
			continue;
		}
		if (n == 5) {
			tmp1[i] = '5';
			a = a / 10;
			continue;
		}
		if (n == 6) {
			tmp1[i] = '6';
			a = a / 10;
			continue;
		}
		if (n == 7) {
			tmp1[i] = '7';
			a = a / 10;
			continue;
		}
		if (n == 8) {
			tmp1[i] = '8';
			a = a / 10;
			continue;
		}
		if (n == 9) {
			tmp1[i] = '9';
			a = a / 10;
			continue;
		}
	}
	for (int i = strlen(tmp1)-1,j=0; i >=0; i--,j++) {
		tmp2[j] = tmp1[i];
	}
	tmp2[strlen(tmp1)] = '\0';
	return tmp2;
}
//把空格分割的第一字符串分割出来
char* cut(char* s) {
	int length = strlen(s);
	char* tmp = new char[length];
	for (int i = 0; i <= length; i++) {
		if (s[i] != ' ') {
			if (s[i] == '\0') {
				tmp[i] = s[i];
				break;
			}
			tmp[i] = s[i];
		}
		else {
			tmp[i] = '\0';
			break;
		}
	}
	return tmp;
}
//cut之后剩下的字符串
char* cutleft(char* s) {
	int length = strlen(s);
	char* tmp = new char[length];
	if (length == 0) {
		tmp[0] = '\0';
		return tmp;
	}
	bool can = false;
	for (int i = 0,j=0; i <= length; i++) {
		if (can) {
			tmp[j] = s[i];
			j++;
		}
		if (!can && s[i] == ' ') {
			can = true;
		}
	}
	return tmp;
}
//求Fi(a,b)
void F(int a, int b,int*ta,int*tb,int*ka,int*kb,int index,int***min) {
	int*** P = new int** [a + 1];
	for (int i = 0; i <= a; i++) {
		P[i] = new int* [b + 1];
	}
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			P[i][j] = new int[2];
		}
	}
	for (int i = 0; i <= 1; i++) {
			P[0][0][i] = 0;
	}
	for (int i = 1; i <= a; i++) {
			P[i][0][1] = INT_MAX;
			P[i][0][0] = ta[index] + ka[index] * i * i;
	}
	for (int i = 1; i <= b; i++) {
		P[0][i][0] = INT_MAX;
		P[0][i][1] = tb[index] + kb[index] * i * i;
	}
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			int min0 = 0;
			int min1 = 0;
			bool first0 = true;
			bool first1 = true;
			for (int w0 = 1,w1=1;w0<=i||w1<=j; ) {
				if (w0 <= i) {
					if (first0) {
						if (P[i - w0][j][1] == INT_MAX) {
							w0++;
							continue;
						}
						min0 = P[i - w0][j][1] + ta[index] + ka[index] * w0 * w0;
						first0 = false;
					}
					else {
						if (P[i - w0][j][1] == INT_MAX) {
							w0++;
							continue;
						}
						if ((P[i - w0][j][1] + ta[index] + ka[index] * w0 * w0) <= min0) {
							min0 = P[i - w0][j][1] + ta[index] + ka[index] * w0 * w0;
						}
					}
					w0++;
				}
				if (w1 <= j) {
					if (first1) {
						if (P[i][j - w1][0] == INT_MAX) {
							w1++;
							continue;
						}
						min1 = P[i][j - w1][0] + tb[index] + kb[index] * w1 * w1;
						first1 = false;
					}
					else {
						if (P[i][j - w1][0] == INT_MAX) {
							w1++;
							continue;
						}
						if (P[i][j - w1][0] + tb[index] + kb[index] * w1 * w1 <= min1) {
							min1 = P[i][j - w1][0] + tb[index] + kb[index] * w1 * w1;
						}
					}
					w1++;
				}
			}
			P[i][j][0] = min0;
			P[i][j][1] = min1;
		}
	}
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			if (P[i][j][0] > P[i][j][1]) {
				min[index][i][j] = P[i][j][1];
			}
			else {
				min[index][i][j] = P[i][j][0];
			}
		}
	}
}
int main() {
	FILE* in;
	fopen_s(&in,"hpc.in.txt", "r");
	//读取文件第一行，为na，nb赋值
	int na=0, nb=0;
	char rowfirst[10];
	if (fgets(rowfirst, 10, in) != NULL) {
		char* tmp = cut(rowfirst);
		char* leave = cutleft(rowfirst);
		exchange(na, tmp);
		tmp = cut(leave);
		exchange(nb, tmp);
	}
	//读取文件第二行，为p赋值
	int p=0;
    char rowsecond[4];
	if (fgets(rowsecond, 4, in) != NULL) {
		exchange(p, rowsecond);
	}
	//从文件第三行开始，读取p行，为ta、tb、ka、kb赋值
	char** row = new char* [p];
	int* ta = new int[p];
	int* tb = new int[p];
	int* ka = new int[p];
	int* kb = new int[p];
	for (int i = 0; i <= p-1; i++) {
		row[i] = new char[50];
	}
	for (int i = 0; i <= p-1; i++) {
		if (fgets(row[i], 50, in) != NULL) {
			char* leave = row[i];
			for (int j = 0; j <= 3; j++) {
				char* tmp = cut(leave);
				leave = cutleft(leave);
				switch (j) {
				case 0:
					exchange(ta[i], tmp);
					break;
				case 1:
					exchange(tb[i], tmp);
					break;
				case 2:
					exchange(ka[i], tmp);
					break;
				case 3:
					exchange(kb[i], tmp);
					break;
				}
			}
		}
	}
	//min[i][j][k]即为Fi(a,b),即第i个节点被分配a个A任务和b个B任务的最短运行时间
	int*** min = new int** [p];
	for (int i = 0; i <= p - 1; i++) {
		min[i] = new int* [na + 1];
	}
	for (int i = 0; i <= p - 1; i++) {
		for (int j = 0; j <= na; j++) {
			min[i][j] = new int[nb + 1];
		}
	}
	for (int i = 0; i <= p - 1; i++) {
		F(na, nb, ta, tb, ka, kb, i, min);
	}
	int*** C = new int** [p];
	for (int i = 0; i <= p-1; i++) {
		C[i] = new int* [na + 1];
	}
	for (int i = 0; i <= p-1; i++) {
		for (int j = 0; j <= na; j++) {
			C[i][j] = new int[nb+1];
		}
	}
	//C[0][j][k]代表给前一个节点分配j个a任务和k个b任务的最短时间
	for (int j = 0; j <= na; j++) {
		for (int k = 0; k <= nb; k++) {
			C[0][j][k] = min[0][j][k];
		}
	}
	for (int i = 1; i <= p - 1; i++) {
		C[i][0][0] = 0;
	}
	for (int i = 1; i <= p - 1; i++) {
		for (int j = 0; j <= na; j++) {
			for (int k = 0; k <= nb; k++) {
				int tmp = 0;
				bool first = true;
				for (int w1 = 0; w1 <=j; w1++) {
					for (int w2 = 0; w2 <=k; w2++) {
						if (first) {
							//因为是并行运行，所有要取max
							tmp = max(C[i-1][j - w1][k - w2], min[i][w1][w2]);
							first = false;
						}
						else {
							if (max(C[i-1][j - w1][k - w2], min[i][w1][w2]) < tmp) {
								tmp = max(C[i-1][j - w1][k - w2], min[i][w1][w2]);
							}
						}
					}
				}
				C[i][j][k] = tmp;
			}
		}
	}
	//将结果输出到文件中
	FILE* out;
	fopen_s(&out, "hpc.out.txt", "w");
	fputs(change(C[p - 1][na][nb]), out);
	system("pause");
	return 0;
}