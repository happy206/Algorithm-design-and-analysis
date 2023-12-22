#include<iostream>
#include<cmath>
#include <functional>
#include<queue>
using namespace std;
//����Сֵ
int min(int A[], int n) {
	int min = INT_MAX;
	for (int i = 0; i <= n - 1; i++) {
		if (min >= A[i]) {
			min = A[i];
		}
	}
	return min;
}
//�ڵ�
struct Node {
	bool* t;
	int teacher;//��ǰ��ʦ���
	int time;//��ǰʱ��
	int bound;//��ǰ�޽�
	int number;//��ǰ�ѷ���Ŀγ�����
	int* sort;
};
//�ض��������
bool operator > (Node a, Node b) {
	return a.bound > b.bound;
}
//���޽�
int get_bound(int** table, int n, int time, int teacher) {
	int bound = time;
	for (int i = teacher + 1; i <= n - 1; i++) {
		bound += min(table[i], n);
	}
	return bound;
}
//��ʼ���ڵ�
void Initialize(int**table,int n,Node& node, int teacher , int time,int number) {
	node.t=new bool[n];
	for (int i = 0; i <= n - 1; i++) {
		node.t[i] = false;
	}
	node.sort = new int[n];
	for (int i = 0; i <= n - 1; i++) {
		node.sort[i] = -1;
	}
	node.teacher = teacher;
	node.time = time;
	node.number = number;
	node.bound = get_bound(table, n, time, teacher);
}
//�ڵ�֮��Ĵ�ֵ����ֱ���ø�ֵ���ţ���Ϊ�ṹ����ָ�룩
void transmit(Node& node, Node top,int n) {
	node.teacher = top.teacher;
	node.number = top.number;
	node.bound = top.bound;
	node.time = top.time;
	for (int i = 0; i <= n - 1; i++) {
		node.t[i] = top.t[i];
		node.sort[i] = top.sort[i];
	}
}
//�������
void solve(int** table, int n) {
	priority_queue<Node,vector<Node>,greater<Node>>heap;//��С��
	Node start;//��ʼ�ڵ�
	Initialize(table,n,start, -1, 0,0);//��ʼ��
	heap.push(start);
	while (!heap.empty()) {
		//�ҵ����Ž�
		if (heap.top().number == n) {
			cout << heap.top().time;
			cout << endl;
			for (int i = 0; i <= n - 1; i++) {
				cout << "��" << i+1<< "����ʦ����" << heap.top().sort[i] + 1 << "���γ�" << endl;
			}
			return;
		}
		int count = n - heap.top().number;//Ҫ��չ�Ľڵ���
		Node* next = new Node[count];
		int j = 0;
		for (int i = 0; i <= count-1; i++) {
			 //��heap.top()��ֵ����next[i]
			Initialize(table, n, next[i], -1, 0, 0);
			transmit(next[i], heap.top(),n);//bound��С��
			//���½ڵ�ֵ
			  next[i].teacher++;
			  for (; j<= n - 1; ) {
				  if (!next[i].t[j]) {
					  next[i].number++;
					  next[i].time += table[next[i].teacher][j];
					  next[i].bound = get_bound(table, n, next[i].time, next[i].teacher);
					  next[i].sort[next[i].teacher] = j;
					  next[i].t[j] = true;
					  j++;
					  break;
				  }
				  j++;
			  }
		}
		heap.pop();
		for (int i = 0; i <= count - 1; i++) {
			heap.push(next[i]);
		}
	}
}
int main() {
	//��ʦ�����Ϳγ�����
	int n;
	cin >> n;
	int** table = new int* [n];
	for (int i = 0; i <= n - 1; i++) {
		table[i] = new int[n];
	}
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= n - 1; j++) {
			cin >> table[i][j];
		}
	}
	solve(table, n);
	system("pause");
	return 0;
}