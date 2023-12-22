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
	bool t;//用来表示节点是否被访问过
	int count;//用来表示有几个节点和他相邻
	List() {
		head = tail = NULL;
		t = false;
		count = 0;
	}
	//链表插入函数
	void insert(int x) {
		Node* p = new Node(x);
		if (head == NULL) {
			head = tail = p;
			head->next = tail;
			tail->next = NULL;
			count++;
		}
		else {
			tail->next = p;
			tail = p;
			tail->next = NULL;
			count++;
		}
	}
	//排序
	void sort() {
		if (count <= 1)return;
		Node* p = new Node;
		//将链表中的数值赋值给数组
		p = head;
		int* A = new int[count];
		int k=0;
		while (p) {
			A[k] = p->data;
			k++;
			p = p->next;
		}
		//将数组排序
		for (int x = 0; x < count - 1; x++) {
			for (int y = x + 1; y <= count - 1; y++) {
				if (A[x] > A[y]) {
					int tmp = A[y];
					A[y] = A[x];
					A[x] = tmp;
				}
			}
		}
		//再将数组的值赋值给链表，实现链表排序
		p = head;
		k = 0;
		while (p) {
			p->data = A[k];
			k++;
			p = p->next;
		}
	}
};
//BFS算法函数
void BFS(int n, int m, int i,int A[],int B[],List*L) {
	List queue;//链表形式的队列，用来存储访问的节点
	queue.insert(i);
	Node* p = new Node;
	Node* q = new Node;
	p = L[i].head;
	L[i].t = true;
	cout << i<<" ";
	q = queue.head;
	while (q) {
		p = L[q->data].head;//遍历链表数组中的某一个链表中的节点
		for (; p; p = p->next) {
			if (L[p->data].t) {}
			else {
				//没被访问过，则执行下列操作
				queue.insert(p->data);
				L[p->data].t = true;
				cout << p->data<<" ";
			}
		}
		q = q->next;//q遍历队列中的节点
	}
}
//DFS算法函数
void DFS(int n, int m, int i,int A[],int B[],List*L) {
	//栈，来存储节点
	int top = -1;
	int* Stack = new int[n];
	L[i].t = true;
	cout << i << " ";
	Stack[++top] = i;
	int tmp = i;
	Node* p = new Node;
	while (true) {
		bool T = false;
		p = L[tmp].head;
		while (p) {
			if (!L[p->data].t) {
				T = true;//代表与这个节点相连的节点有没被访问过的
				break;
			}
			p = p->next;
		}
		if (T) {
			//又没被访问过的，即可以顺着它再往下找，所以进栈
			Stack[++top] = p->data;
			L[p->data].t = true;
			cout << p->data << " ";
			tmp = p->data;
		}
		else {
			//没有没被访问过的，则将它出栈，访问上一个
			top--;
			//top<0,说明第一个访问的节点也没有可访问的节点了，DFS遍历结束
			if (top < 0) {
				break;
			}
			else {
				tmp = Stack[top];
			}
		}
	}
}
int main() {
	//n为节点数、m为边数、i为起始节点
	int n, m, i;
	cin >> n >> m >> i;
	//记录边的两个节点
	int* A = new int[m];
	int* B = new int[m];
	//链表数组，用邻接链表的形式存储图
	List* L = new List[n];
	for (int k = 0; k <= m - 1; k++) {
		cin >> A[k] >> B[k];
	}
	for (int k = 0; k <= m - 1; k++) {
		L[A[k]].insert(B[k]);
		L[B[k]].insert(A[k]);
	}
	//将邻接链表中的index排序，以便符合题目要求
	for (int k = 0; k <= m - 1; k++) {
		L[k].sort();
	}
	BFS(n, m, i,A,B,L);
	cout << endl;
	for (int k = 0; k <= m - 1; k++) {
		L[k].t=false;
	}
	DFS(n, m, i,A,B,L);
	system("pause");
	return 0;
}