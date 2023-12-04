#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector<long long> v;
int n;
int num_v[] = {9,8,7,6,5,4,3,2,1,0};
bool vis[10];
deque<int> dq;

long long getNum() {
	long long res = 0;
	for (int i = 0; i < dq.size(); i++)
		res = res * 10 + dq[i];
	return res;
}

void dfs(int depth, int idx, int size) {
	if (depth == size) {
		v.push_back(getNum());
		return ;
	}
	for (int i = idx; i < 10; i++) {
		if (vis[i] == false) {
			vis[i] = true;
			dq.push_back(num_v[i]);
			dfs(depth + 1, i + 1, size);
			dq.pop_back();
			vis[i] = false;
		}
	}
}

int main() {
	cin >> n;
	if(n > 1023) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= 10; i++)
		dfs(0, 0, i);
	sort(v.begin(), v.end());
	if (n > v.size())
		cout << -1;
	else
		cout << v[n - 1];
}
