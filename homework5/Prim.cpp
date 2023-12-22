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
	int depth;//�ڵ����
	bool t;//������ʾ�ڵ��Ƿ񱻼��뵽��֪��̾���ļ���
	List() {
		head = tail = NULL;
		t = false;
	}
	//������뺯��
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
	cout << "�������гɹ��������ڵ����д�1��ʼ!" << endl;
	//nΪ�ڵ�����eΪ������sΪ��ʼ�ڵ�
	int n, e, s;
	s = 0;
	cin >> n >> e ;
	int* A = new int[e];//�ߵ����
	int* B = new int[e];//�ߵ��յ�
	int* C = new int[e];//�ߵ�Ȩֵ
	List* L = new List[n];//�������飬���ڽ��������ʽ�洢ͼ
	for (int k = 0; k <= e - 1; k++) {
		cin >> A[k] >> B[k] >> C[k];
		A[k] -= 1;
		B[k] -= 1;
		L[A[k]].insert(B[k], C[k]);
	}
	int count = 1;//��¼������С�������Ľڵ����
	L[s].t = true;
	int* D = new int[n];//�洢��СȨ��
	D[s] = 0;
	int* tmp = new int[n];//�洢��ʱ��СȨ��
	for (int k = 0; k <= n - 1; k++) {
		if (k == s) {
			tmp[k] = 0;
		}
		else {
			tmp[k] = INT_MIN;//������ʾ��δ��ͨ
		}
	}
	Node* p = new Node();
	int index = s;//��¼���¼��뼯�ϵĽڵ�
	while (true) {
		if (count == n)break;
		p = L[index].head;
		//����Ȩ�ؼ���
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
		//�ҳ�Ӧ���뼯�ϵĵ�
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