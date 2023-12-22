#include<iostream>
#include<limits.h>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	int distance;
	Node(int m, int n) {
		distance = n;
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
	bool t;//用来表示节点是否被加入到已知最短距离的集合
	List() {
		head = tail = NULL;
		t = false;
	}
	//链表插入函数
	void insert(int x, int distance) {
		Node* p = new Node(x, distance);
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
	cout << "程序运行成功条件：节点序列从1开始!" << endl;
	//n为节点数、e为边数、s为起始节点
	int n, e, s;
	s = 0;
	cin >> n >> e ;
	int* A = new int[e];//边的起点
	int* B = new int[e];//边的终点
	int* C = new int[e];//边的权值
	List* L = new List[n];//链表数组，用邻接链表的形式存储图
	for (int k = 0; k <= e - 1; k++) {
		cin >> A[k] >> B[k] >> C[k];
		A[k] -= 1;
		B[k] -= 1;
		L[A[k]].insert(B[k], C[k]);
	}
	int count = 1;//记录进入最小生成树的节点个数
	L[s].t = true;
	int* D = new int[n];//存储最小权重
	D[s] = 0;
	int* tmp = new int[n];//存储暂时最小权重
	for (int k = 0; k <= n - 1; k++) {
		if (k == s) {
			tmp[k] = 0;
		}
		else {
			tmp[k] = INT_MIN;//用来表示还未连通
		}
	}
	Node* p = new Node();
	int index = s;//记录最新加入集合的节点
	while (true) {
		if (count == n)break;
		p = L[index].head;
		//更新权重集合
		while (p) {
			if (tmp[p->data] != INT_MIN) {
				if (p->distance + D[index] < tmp[p->data]) {
					tmp[p->data] = p->distance ;
					p = p->next;
				}
				else {
					p = p->next;
				}
			}
			else {
				tmp[p->data] = p->distance ;
				p = p->next;
			}
		}
		//找出应进入集合的点
		bool first = true;
		int shorter;
		for (int k = 0; k <= n - 1; k++) {
			if (tmp[k] <= 0) {
				if (k == n - 1) {
					D[index] = shorter;
					count++;
					L[index].t = true;
				}
				continue;
			}
			if (L[k].t) {
				if (k == n - 1) {
					D[index] = shorter;
					count++;
					L[index].t = true;
				}
				continue;
			}
			if (first) {
				shorter = tmp[k];
				index = k;
				first = false;
			}
			if (shorter > tmp[k]) {
				shorter = tmp[k];
				index = k;
			}
			if (k == n - 1) {
				D[index] = shorter;
				count++;
				L[index].t = true;
			}
		}
	}
	int sum = 0;
	for (int k = 0; k <= n - 1; k++) {
		sum += D[k];
	}
	cout << sum;
	system("pause");
	return 0;
}