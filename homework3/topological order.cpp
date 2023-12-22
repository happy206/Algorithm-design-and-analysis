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
	bool t;//������ʾ�ڵ��Ƿ񱻷��ʹ�
	List() {
		out = 0;
		in = 0;
		head = tail = NULL;
		t = false;
	}
	//������뺯��
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
	//nΪ�ڵ�����mΪ������iΪ��ʼ�ڵ�
	int n, m;
	cin >> n >> m ;
	int* A = new int[m];
	int* B = new int[m];
	//�������飬���ڽ��������ʽ�洢ͼ
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
				//�ǵ�һ���ҵ����Ϊ0�Ľڵ�
				if (first) {
					first = false;
					tmp = k;
				}
				//���ǵ�һ���ҵ�������Ҫ�Ƚ�index
				else {
					if (k < tmp) {
						tmp = k;
					}
				}
				T = true;
			}
		}
		//˵�����������Ϊ��ĵ㣬����ѭ��
		if (!T) {
			break;
		}
		Node* p = new Node;
		p = L[tmp].head;
		//���ʹ�����Ҫ��Ϊtrue
		L[tmp].t = true;
		cout << tmp << " ";
		//������ڵ�ɾ������֮�����Ľڵ�����Ҫ��1
		while (p) {
			L[p->data].in--;
			p = p->next;
		}
	}
	system("pause");
	return 0;
}