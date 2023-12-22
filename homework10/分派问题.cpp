#include<iostream>
#include<cmath>
#include <functional>
#include<queue>
using namespace std;
//求最小值
int min(int A[], int n) {
	int min = INT_MAX;
	for (int i = 0; i <= n - 1; i++) {
		if (min >= A[i]) {
			min = A[i];
		}
	}
	return min;
}
//节点
struct Node {
	bool* t;
	int teacher;//当前老师编号
	int time;//当前时间
	int bound;//当前限界
	int number;//当前已分配的课程数量
	int* sort;
};
//重定义运算符
bool operator > (Node a, Node b) {
	return a.bound > b.bound;
}
//求限界
int get_bound(int** table, int n, int time, int teacher) {
	int bound = time;
	for (int i = teacher + 1; i <= n - 1; i++) {
		bound += min(table[i], n);
	}
	return bound;
}
//初始化节点
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
//节点之间的传值（不直接用赋值符号，因为结构体有指针）
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
//解决函数
void solve(int** table, int n) {
	priority_queue<Node,vector<Node>,greater<Node>>heap;//最小堆
	Node start;//初始节点
	Initialize(table,n,start, -1, 0,0);//初始化
	heap.push(start);
	while (!heap.empty()) {
		//找到最优解
		if (heap.top().number == n) {
			cout << heap.top().time;
			cout << endl;
			for (int i = 0; i <= n - 1; i++) {
				cout << "第" << i+1<< "个老师分配" << heap.top().sort[i] + 1 << "个课程" << endl;
			}
			return;
		}
		int count = n - heap.top().number;//要扩展的节点数
		Node* next = new Node[count];
		int j = 0;
		for (int i = 0; i <= count-1; i++) {
			 //将heap.top()的值赋给next[i]
			Initialize(table, n, next[i], -1, 0, 0);
			transmit(next[i], heap.top(),n);//bound最小的
			//更新节点值
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
	//老师数量和课程数量
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