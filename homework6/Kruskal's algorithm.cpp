#include<iostream>
#include<limits.h>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node() {
		next = NULL;
	};
};
//用结构体表示边
struct Edge {
	int begin, end;//起点、终点
	int weight;//权重
};
//并查集搜索父节点
int parent(Node*n) {
	Node* p = new Node();
	p = n;
	if (p->next== NULL) {
		return  p->data;
	}
	while (true) {
		p = p->next;
		if (p->next == NULL) {
			return p->data;
		}
	}
}
//是否构成回路
bool iscircle(Node* m, Node* n) {
	int a = parent(m);
	int b = parent(n);
	if (a == -1 || b == -1 || a != b) {
		return true;
	}
	else {
		return false;
	}
}
//交换函数(用于交换两个边）
void exchange(Edge* a,Edge* b) {
	int x = a->begin;
	int y = a->end;
	int z = a->weight;
	a->begin = b->begin;
	a->end = b->end;
	a->weight = b->weight;
	b->begin = x;
	b->end = y;
	b->weight = z;
}
int main() {
	cout << "该程序成功运行的前提为：节点序号从1开始，且序号连续" << endl;
	int n, e;
	cin >> n>>e;
	Edge* edge = new Edge[e];
	for (int i = 0; i <= e - 1; i++) {
		cin >> edge[i].begin >> edge[i].end >> edge[i].weight;
	}
	Node* node = new Node[n];
	for (int i = 0; i <= n - 1; i++) {
		node[i].data = i + 1;
	}
	//排序
	for (int i = 0; i < e - 1; i++) {
		for (int j = i + 1; j <= e - 1; j++) {
			if (edge[i].weight > edge[j].weight) {
				exchange(&edge[i], &edge[j]);
			}
		}
	}
	int sum = 0;
	Node* tmp = new Node();
	for (int i = 0; i <= n - 1; i++) {
		if (iscircle(&node[edge[i].begin-1], &node[edge[i].end-1])){
			sum += edge[i].weight;
			tmp = &node[edge[i].end - 1];
			while (true) {
				//找到其并查集的父节点
				if (tmp->next == NULL) {
					tmp->next = &node[edge[i].begin - 1];
					break;
				}
				tmp = tmp->next;
			}
		}
	}
	cout << sum;
	system("pause");
	return 0;
}