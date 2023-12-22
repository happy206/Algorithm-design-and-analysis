#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int x) {
		data = x;
		next = NULL;
	}
	Node() {
		next = NULL;
	}
};
class list {
public:
	Node* head;
	Node* tail;
	list() {
		head = tail = NULL;
	}
	void insert(int x) {
		Node* p = new Node(x);
		if (head == NULL) {
			head = tail = p;
			head->next = tail;
			tail->next = NULL;
			return;
		}
		else {
			tail->next = p;
			tail = p;
			tail->next = NULL;
		}
	}
};
int main() {
	int n;
	cin >> n;
	int* S = new int[n];//��ʼʱ��
	int* F = new int[n];//���ʱ��
	for (int i = 0; i <= n - 1; i++) {
		cin >> S[i] >> F[i];
	}
	//����
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			if (S[i] > S[j]) {
				int tmp1 = F[i];
				int tmp2 = S[i];
				F[i] = F[j];
				F[j] = tmp1;
				S[i] = S[j];
				S[j] = tmp2;
			}
		}
	}
	int num = 1;//��������
	list* C = new list[n];//���Ҽ���
	for (int i = 0; i <= n - 1; i++) {
		bool T = true;
		for (int j = 0; j <= num - 1; j++) {
			if (C[j].head == NULL) {
				//ֻ�轫���ʱ��������о���
				//��Ϊֻ��ȽϺ����γ̵Ŀ�ʼʱ����Ѿ�����Ŀγ̵����ʱ��
				//����֪���Ƿ����
				C[j].insert(F[i]);
				T = false;//��Ϊ�н��ҿ��ã����Բ������ӽ�����
			}
			else {
				Node* p = new Node();
				p = C[j].tail;
				//ֻ���������ҿ�ʼʱ������Ŀγ̵����ʱ����бȽϼ���
				if (S[i] < p->data) {
					continue;
				}
				else {
					//�������ݵĽ��ң�ֱ�ӽ�ȥ���У������Ĳ�����
					C[j].insert(F[i]);
					T = false;//��Ϊ�н��ҿ��ã����Բ������ӽ�����
					break;
				}
			}
		}
		//��Ҫ���ӽ���
		if (T) {
			num++;
			C[num - 1].insert(F[i]);//�γ̽������µĽ��Ҽ���
		}
	}
	cout << num;
	system("pause");
	return 0;
}