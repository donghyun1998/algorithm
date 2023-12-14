// 통나무 건너뛰기
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int n, vector<int>& v) {
	// 제일 큰 거를 중간에 넣고 왼쪽 오른쪽 순으로 추가해 나가야 할 것 같은데

	int res = 0;
	sort(v.begin(), v.end(), greater<int>());

	deque<int> dq;
	dq.push_back(v[0]);
	for (int i = 1; i < v.size(); i++) {
		if (dq.front() >= dq.back()) {
			int prev = dq.front();
			dq.push_front(v[i]);
			res = max(res, prev - dq.front());
		}
		else {
			int prev = dq.back();
			dq.push_back(v[i]);
			res = max(res, prev - dq.back());
		}
	}
	res = max(res, abs(dq.front() - dq.back()));
	return res;
}

int main () {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int case_n;
	cin >> case_n;

	for (int i = 0; i < case_n; i++) {
		int n;
		cin >> n;
		vector<int> v(n, 0);
		for (int j = 0; j < n; j++)
			cin >> v[j];
		cout << solution(n, v) << '\n';
	}
}
