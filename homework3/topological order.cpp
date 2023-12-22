#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int m) {
		data = m;
		next = NULL;
	}
	Node() {};
};
class List {
public:
	Node* head;
	Node* tail;
	int out;
	int in;
	bool t;//用来表示节点是否被访问过
	List() {
		out = 0;
		in = 0;
		head = tail = NULL;
		t = false;
	}
	//链表插入函数
	void insert(int x) {
		Node* p = new Node(x);
		if (head == NULL) {
			head = tail = p;
			head->next = tail;
			tail->next = NULL;
		}
		else {
			tail->next = p;
			tail = p;
			tail->next = NULL;
		}
	}
};
int main() {
	//n为节点数、m为边数、i为起始节点
	int n, m;
	cin >> n >> m ;
	int* A = new int[m];
	int* B = new int[m];
	//链表数组，用邻接链表的形式存储图
	List* L = new List[n];
	for (int k = 0; k <= m - 1; k++) {
		cin >> A[k] >> B[k];
	}
	for (int k = 0; k <= m - 1; k++) {
		L[A[k]].insert(B[k]);
		L[A[k]].out++;
		L[B[k]].in++;
	}
	int tmp = 0;
	while (true) {
		bool first = true;
		bool T = false;
		for (int k = 0; k <= n - 1; k++) {
			if (L[k].in == 0&&!L[k].t) {
				//是第一次找到入度为0的节点
				if (first) {
					first = false;
					tmp = k;
				}
				//不是第一次找到，则需要比较index
				else {
					if (k < tmp) {
						tmp = k;
					}
				}
				T = true;
			}
		}
		//说明不存在入度为零的点，跳出循环
		if (!T) {
			break;
		}
		Node* p = new Node;
		p = L[tmp].head;
		//访问过，则要变为true
		L[tmp].t = true;
		cout << tmp << " ";
		//把这个节点删掉，与之相连的节点的入度要减1
		while (p) {
			L[p->data].in--;
			p = p->next;
		}
	}
	system("pause");
	return 0;
}