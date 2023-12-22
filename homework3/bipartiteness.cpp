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
	int depth;//节点深度
	bool t;//用来表示节点是否被访问过
	List() {
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
	int n, m, i;
	cin >> n >> m;
	i = 0;
	int* A = new int[m];
	int* B = new int[m];
	List* L = new List[n];//链表数组，用邻接链表的形式存储图
	for (int k = 0; k <= m - 1; k++) {
		cin >> A[k] >> B[k];
	}
	if (n < 2) {
		cout << "No";
		system("pause");
		return 0;
	}
	for (int k = 0; k <= m - 1; k++) {
		L[A[k]].insert(B[k]);
		L[B[k]].insert(A[k]);
	}
	List queue;//链表形式的队列，用来存储访问的节点
	L[i].depth = 0;//父节点深度为零
	queue.insert(i);
	Node* p = new Node;
	Node* q = new Node;
	p = L[i].head;
	L[i].t = true;
	q = queue.head;
	while (q) {
		p = L[q->data].head;//遍历链表数组中的某一个链表中的节点
		for (; p; p = p->next) {
			if (L[p->data].t) {}
			else {
				//没被访问过，则执行下列操作
				queue.insert(p->data);
				L[p->data].t = true;
				L[p->data].depth = L[q->data].depth + 1;//子节点深度等于父节点的深度＋1
			}
		}
		q = q->next;//q遍历队列中的节点
	}
	//BFS同层若有边则不是二分图
	for (int k = 0; k <= m - 1; k++) {
		if(L[A[k]].depth == L[B[k]].depth){
			cout << "No";
			system("pause");
			return 0;
		}
	}
	cout << "Yes";
	system("pause");
	return 0;
}