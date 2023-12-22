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
			if (S[i] > S[j]) {
				int tmp1 = F[i];
				int tmp2 = S[i];
				F[i] = F[j];
				F[j] = tmp1;
				S[i] = S[j];
				S[j] = tmp2;
			}
		}
	}
	int num = 1;//教室数量
	list* C = new list[n];//教室集合
	for (int i = 0; i <= n - 1; i++) {
		bool T = true;
		for (int j = 0; j <= num - 1; j++) {
			if (C[j].head == NULL) {
				//只需将完成时间加入其中就行
				//因为只需比较后加入课程的开始时间和已经加入的课程的完成时间
				//即可知道是否兼容
				C[j].insert(F[i]);
				T = false;//因为有教室可用，所以不用增加教室了
			}
			else {
				Node* p = new Node();
				p = C[j].tail;
				//只需和这个教室开始时间最晚的课程的完成时间进行比较即可
				if (S[i] < p->data) {
					continue;
				}
				else {
					//遇到兼容的教室，直接进去就行，后续的不用了
					C[j].insert(F[i]);
					T = false;//因为有教室可用，所以不用增加教室了
					break;
				}
			}
		}
		//需要增加教室
		if (T) {
			num++;
			C[num - 1].insert(F[i]);//课程进入最新的教室即可
		}
	}
	cout << num;
	system("pause");
	return 0;
}