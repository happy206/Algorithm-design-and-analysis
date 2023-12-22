#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int x) {
		data = x;
		next = NULL;
	}
	Node() {
		next = NULL;
	}
};
class list {
public:
	Node* head;
	Node* tail;
	list() {
		head = tail = NULL;
	}
	void insert(int x) {
		Node* p = new Node(x);
		if (head == NULL) {
			head = tail = p;
			head->next = tail;
			tail->next = NULL;
			return;
		}
		else {
			tail->next = p;
			tail = p;
			tail->next = NULL;
		}
	}
};
int main() {
	int n;
	cin >> n;
	int* S = new int[n];//开始时间
	int* F = new int[n];//完成时间
	for (int i = 0; i <= n - 1; i++) {
		cin >> S[i] >> F[i];
	}
	//排序
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			if (F[i] > F[j]) {
				int tmp1= F[i];
				int tmp2 = S[i];
				F[i] = F[j];
				F[j] = tmp1;
				S[i] = S[j];
				S[j] = tmp2;
			}
		}
	}
	int num = 0;
	list A, B;//job集合，A存开始时间，B存完成时间
	for (int i = 0; i <= n - 1; i++) {
		if (num == 0) {
			A.insert(S[i]);
			B.insert(F[i]);
			num++;
		}
		else {
			Node* p = new Node;
			p= B.head;
			bool T = true;
			while (p) {
				if (S[i] < p->data) {
					//如果不兼容则跳出循环
					T = false;
					break;
				}
				else {
					p=p->next;
				}
			}
			if (T) {
				//如果兼容则加入集合
				A.insert(S[i]);
				B.insert(F[i]);
				num++;
			}

		}
	}
	cout << num;
	system("pause");
	return 0;
}