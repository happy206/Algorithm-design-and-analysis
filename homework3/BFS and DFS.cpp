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
	bool t;//������ʾ�ڵ��Ƿ񱻷��ʹ�
	int count;//������ʾ�м����ڵ��������
	List() {
		head = tail = NULL;
		t = false;
		count = 0;
	}
	//������뺯��
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
	//����
	void sort() {
		if (count <= 1)return;
		Node* p = new Node;
		//�������е���ֵ��ֵ������
		p = head;
		int* A = new int[count];
		int k=0;
		while (p) {
			A[k] = p->data;
			k++;
			p = p->next;
		}
		//����������
		for (int x = 0; x < count - 1; x++) {
			for (int y = x + 1; y <= count - 1; y++) {
				if (A[x] > A[y]) {
					int tmp = A[y];
					A[y] = A[x];
					A[x] = tmp;
				}
			}
		}
		//�ٽ������ֵ��ֵ������ʵ����������
		p = head;
		k = 0;
		while (p) {
			p->data = A[k];
			k++;
			p = p->next;
		}
	}
};
//BFS�㷨����
void BFS(int n, int m, int i,int A[],int B[],List*L) {
	List queue;//������ʽ�Ķ��У������洢���ʵĽڵ�
	queue.insert(i);
	Node* p = new Node;
	Node* q = new Node;
	p = L[i].head;
	L[i].t = true;
	cout << i<<" ";
	q = queue.head;
	while (q) {
		p = L[q->data].head;//�������������е�ĳһ�������еĽڵ�
		for (; p; p = p->next) {
			if (L[p->data].t) {}
			else {
				//û�����ʹ�����ִ�����в���
				queue.insert(p->data);
				L[p->data].t = true;
				cout << p->data<<" ";
			}
		}
		q = q->next;//q���������еĽڵ�
	}
}
//DFS�㷨����
void DFS(int n, int m, int i,int A[],int B[],List*L) {
	//ջ�����洢�ڵ�
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
				T = true;//����������ڵ������Ľڵ���û�����ʹ���
				break;
			}
			p = p->next;
		}
		if (T) {
			//��û�����ʹ��ģ�������˳�����������ң����Խ�ջ
			Stack[++top] = p->data;
			L[p->data].t = true;
			cout << p->data << " ";
			tmp = p->data;
		}
		else {
			//û��û�����ʹ��ģ�������ջ��������һ��
			top--;
			//top<0,˵����һ�����ʵĽڵ�Ҳû�пɷ��ʵĽڵ��ˣ�DFS��������
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
	//nΪ�ڵ�����mΪ������iΪ��ʼ�ڵ�
	int n, m, i;
	cin >> n >> m >> i;
	//��¼�ߵ������ڵ�
	int* A = new int[m];
	int* B = new int[m];
	//�������飬���ڽ��������ʽ�洢ͼ
	List* L = new List[n];
	for (int k = 0; k <= m - 1; k++) {
		cin >> A[k] >> B[k];
	}
	for (int k = 0; k <= m - 1; k++) {
		L[A[k]].insert(B[k]);
		L[B[k]].insert(A[k]);
	}
	//���ڽ������е�index�����Ա������ĿҪ��
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