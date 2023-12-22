#include<iostream>
#include<limits.h>
using namespace std;
//节点
class Node {
public:
	Node* next;
	Node* right;
	Node* left;
	int deep;
	int F;
	Node() {
		next = right = left  = NULL;
		deep = 1;
	}
	Node(int F) {
		this->F = F;
		next = right = left  = NULL;
		deep = 1;
	}
};
//链表
class list {
public:
	Node* head;
	Node* tail;
	int count;
	list() {
		count = 0;
		head = tail = NULL;
	}
	//插入节点
	void insert(Node* root) {
		if (head == NULL) {
			head = tail = root;
			head->next = tail;
			tail->next = NULL;
			count++;
		}
		else {
			if (head == tail) {
				if (root->F >= head->F) {
					tail->next = root;
					tail = root;
					tail->next = NULL;
					count++;
				}
				else {
					root->next = head;
					head = root;
					count++;
				}
		    }
			else {
				if (root->F < head->F) {
					root->next = head;
					head = root;
					count++;
					return;
				}
				else {
					Node* p = new Node();
					p = head;
					while (p) {
						if (p == tail) {
							tail->next = root;
							tail = root;
							tail->next = NULL;
							count++;
							return;
						}
						if (root->F >= p->F&&root->F<p->next->F) {
							root->next = p->next;
							p->next = root;
							count++;
							return;
						}
						else {
							p = p->next;
						}
					}
				}
			}
		}
	}
	//删除节点
	void det(int F) {
		if (head == NULL)return;
		if (head == tail) {
			head = tail = NULL;
			count--;
			return;
		}
		if (head->F == F) {
			head = head->next;
			count--;
			return;
		}
		if (tail->F == F) {
			Node* p = new Node();
			p = head;
			while (p) {
				if (p->next==tail) {
					tail = p;
					tail->next = NULL;
					count--;
					return;
				}
				p = p->next;
			}
		}
		Node* p = new Node();
		p = head;
		while (p) {
			if (p->next->F==F) {
				p ->next= p->next->next;
				count--;
				return;
			}
			p = p->next;
		}
	}
};
void sort(int A[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			if (A[i] > A[j]) {
				int a = A[i];
				A[i] = A[j];
				A[j] = a;
			}
		}
	}
}
//将一棵树的所有节点的深度+1
void grow (Node* p) {
	if (p == NULL) {
		return;
	}
	else {
		p->deep++;
		int a = p->deep;
		grow(p->left);
		grow(p->right);
	}
}
//计算平均编码长度
int ASL(Node* p) {
	int count=0;
	if (p == NULL) {
		return count;
	}
	else {
		if (p->right == NULL && p->left == NULL) {
			count += p->F * (p->deep-1);
			return count;
		}
		else {
			count += ASL(p->right);
			count += ASL(p->left);
			return count;
		}
	}
}
int main() {
	int n;
	cin >> n;
	int* F = new int[n];
	double sum = 0;
	for (int i = 0; i <= n - 1; i++) {
		cin >> F[i];
		sum += (double)F[i];
	}
	sort(F, n);
	Node** root = new Node * [n];
	list l;
	for (int i = 0; i <= n - 1; i++) {
		Node* tmp = new Node(F[i]);
		root[i] = tmp;
		l.insert(root[i]);
	}
	while (true) {
		if (l.count == 1) {
			break;
		}
		int a = l.head->F;
		int b = l.head->next->F;
		Node* tmp = new Node(l.head->F+ l.head->next->F);
		int c = tmp->F;
		grow(l.head);
		grow(l.head->next);
		tmp->left= l.head;
		tmp->right = l.head->next;
		l.det(l.head->next->F);
		l.det(l.head->F);
		l.insert(tmp);
	}
	int asl = ASL(l.head);
	double num = (double)asl / sum;
	cout << num;
	cout << endl;
	system("pause");
	return 0;
}