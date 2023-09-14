#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <unordered_set>
#include <utility>
using namespace std;
bool compare(std::pair<int, int> a, std::pair<int,int> b){
	if(a.second == b.second) // 끝나는 시간 즉 second를 기준으로 sort해야 함...
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, res = 0;
	cin >> n;
	vector<pair<int, int> > v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), compare);

	int end = -1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first >= end) { // 여태 제일 빨리 끝나는 회의 끝나는 시간보다 지금 시작시간이 뒤일때
			res++;
			end = v[i].second;
		}
	}
	cout << res;
}
