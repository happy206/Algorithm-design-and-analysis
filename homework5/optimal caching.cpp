#include<iostream>
using namespace std;
//判断缓存能否满足请求
bool exist(int cache[], int request, int k) {
	for (int i = 0; i <= k - 1; i++) {
		if (request == cache[i]) {
			//将最新用到的放到cache序列的后面
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
//返回cache中应该被替代的序号
int eviction(int request[],int index, int cache[], int s,int k) {
	int* distance = new int[k];//存储缓存中每个被将要请求的距离
	for (int i = 0; i <= k - 1; i++) {
		distance[i] = 0;
	}
	for (int i = 0; i <= k - 1; i++) {
		for (int j = index + 1; j <= s - 1; j++) {
			if (cache[i] != request[j]) {
				if (j == s - 1) {
					//意味着后面的请求序列未出现这个数字，所以+2，让它比其他出现的距离大
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
		//因为exist函数，已将序列按未使用时间排序了，所以这里只需比较距离即可
		if (distance[0] < distance[i]) {
			int a = distance[0];
			distance[0] = distance[i];
			distance[i] = a;
			E = i;//记录距离达的索引
		}
	}
	return E;
}

int main() {
	int k, n, s;
	cin >> k >> n >> s;
	//输入cache中初始数据
	int* cache = new int[k];
	for (int i = 0; i <= n - 1; i++) {
		cin >> cache[i];
	}
	//输入请求序列
	int* request = new int[s];
	for (int i = 0; i <= s - 1; i++) {
		cin >> request[i];
	}
	//开始输出eviction序列
	for (int i = 0; i <= s - 1; i++) {
		//cache是否存在请求
		bool T = exist(cache, request[i], n);
		if (i == s - 1 && !T) {
			cout << cache[0];
			continue;
		}
		if (i == s - 1 && T) {
			continue;
		}
		//cache未满，还不存在请求，则直接进cache就行
		if (n < k && !T) {
			cache[n] = request[i];
			n++;
			continue;
		}
		//cache未满，但存在请求
		if (n<k && T) {
			continue;
		}
		//cache已满，且存在请求
		if (n >= k &&T) {
			continue;
		}
		//cache已满，不存在请求
		if (n >= k && !T) {
			int tmp = eviction(request, i, cache, s, k);
			cout << cache[tmp] << " ";
			cache[tmp] = request[i];
			//将新用到的放到cache序列后面
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