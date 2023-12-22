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
//�ýṹ���ʾ��
struct Edge {
	int begin, end;//��㡢�յ�
	int weight;//Ȩ��
};
//���鼯�������ڵ�
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
//�Ƿ񹹳ɻ�·
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
//��������(���ڽ��������ߣ�
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
	cout << "�ó���ɹ����е�ǰ��Ϊ���ڵ���Ŵ�1��ʼ�����������" << endl;
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
	//����
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
				//�ҵ��䲢�鼯�ĸ��ڵ�
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