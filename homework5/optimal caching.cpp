#include<iostream>
using namespace std;
//�жϻ����ܷ���������
bool exist(int cache[], int request, int k) {
	for (int i = 0; i <= k - 1; i++) {
		if (request == cache[i]) {
			//�������õ��ķŵ�cache���еĺ���
			int tmp = cache[i];
			for (int j = i; j <k-1; j++) {
				cache[j] = cache[j + 1];
			}
			cache[k-1] = tmp;
			return true;
		}
	}
	return false;
}
//����cache��Ӧ�ñ���������
int eviction(int request[],int index, int cache[], int s,int k) {
	int* distance = new int[k];//�洢������ÿ������Ҫ����ľ���
	for (int i = 0; i <= k - 1; i++) {
		distance[i] = 0;
	}
	for (int i = 0; i <= k - 1; i++) {
		for (int j = index + 1; j <= s - 1; j++) {
			if (cache[i] != request[j]) {
				if (j == s - 1) {
					//��ζ�ź������������δ����������֣�����+2���������������ֵľ����
					distance[i] += 2;
				}
				else {
					distance[i]++;
				}
			}
			else {
				distance[i]++;
				break;
			}
		}
	}
	int E = 0;
	for (int i = 1; i <= k - 1; i++) {
		//��Ϊexist�������ѽ����а�δʹ��ʱ�������ˣ���������ֻ��ȽϾ��뼴��
		if (distance[0] < distance[i]) {
			int a = distance[0];
			distance[0] = distance[i];
			distance[i] = a;
			E = i;//��¼����������
		}
	}
	return E;
}

int main() {
	int k, n, s;
	cin >> k >> n >> s;
	//����cache�г�ʼ����
	int* cache = new int[k];
	for (int i = 0; i <= n - 1; i++) {
		cin >> cache[i];
	}
	//������������
	int* request = new int[s];
	for (int i = 0; i <= s - 1; i++) {
		cin >> request[i];
	}
	//��ʼ���eviction����
	for (int i = 0; i <= s - 1; i++) {
		//cache�Ƿ��������
		bool T = exist(cache, request[i], n);
		if (i == s - 1 && !T) {
			cout << cache[0];
			continue;
		}
		if (i == s - 1 && T) {
			continue;
		}
		//cacheδ������������������ֱ�ӽ�cache����
		if (n < k && !T) {
			cache[n] = request[i];
			n++;
			continue;
		}
		//cacheδ��������������
		if (n<k && T) {
			continue;
		}
		//cache�������Ҵ�������
		if (n >= k &&T) {
			continue;
		}
		//cache����������������
		if (n >= k && !T) {
			int tmp = eviction(request, i, cache, s, k);
			cout << cache[tmp] << " ";
			cache[tmp] = request[i];
			//�����õ��ķŵ�cache���к���
			int p = cache[tmp];
			for (int j = tmp; j <k-1; j++) {
				cache[j] = cache[j + 1];
			}
			cache[k-1] = p;
		}
	}
	system("pause");
	return 0;
}