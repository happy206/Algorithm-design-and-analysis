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
	int depth;//�ڵ����
	bool t;//������ʾ�ڵ��Ƿ񱻷��ʹ�
	List() {
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
	int n, m, i;
	cin >> n >> m;
	i = 0;
	int* A = new int[m];
	int* B = new int[m];
	List* L = new List[n];//�������飬���ڽ��������ʽ�洢ͼ
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
	List queue;//������ʽ�Ķ��У������洢���ʵĽڵ�
	L[i].depth = 0;//���ڵ����Ϊ��
	queue.insert(i);
	Node* p = new Node;
	Node* q = new Node;
	p = L[i].head;
	L[i].t = true;
	q = queue.head;
	while (q) {
		p = L[q->data].head;//�������������е�ĳһ�������еĽڵ�
		for (; p; p = p->next) {
			if (L[p->data].t) {}
			else {
				//û�����ʹ�����ִ�����в���
				queue.insert(p->data);
				L[p->data].t = true;
				L[p->data].depth = L[q->data].depth + 1;//�ӽڵ���ȵ��ڸ��ڵ����ȣ�1
			}
		}
		q = q->next;//q���������еĽڵ�
	}
	//BFSͬ�����б����Ƕ���ͼ
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