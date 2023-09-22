#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <cstring>
#include <utility>

using namespace	std;

int len, res = 2147483647, wantCnt;
vector<pair<int, int> > store;
vector<pair<int, int> > house;
int selectArr[15];
int selectIdx = 0;

int getChickenDist() {
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int diff = 2147483647;
		for (int j = 0; j < wantCnt; j++) {
			int cur = abs(store[selectArr[j]].first - house[i].first)
				 + abs(store[selectArr[j]].second - house[i].second);
			diff = min(diff, cur);
		}
		sum += diff;
	}
	return sum;
}

void dfs(int depth) {
	if (selectIdx == wantCnt) {
		res = min(getChickenDist(), res);
		return ;
	}
	if (depth == store.size())
		return; // 더 이상 탐색할 필요 없음
	selectArr[selectIdx++] = depth;
	dfs(depth + 1);
	selectIdx--;
	dfs(depth + 1);
}

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int input;
	cin >> len >> wantCnt;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cin >> input;
			if (input == 2)
				store.push_back(make_pair(i, j));
			if (input == 1)
				house.push_back(make_pair(i, j));
		}
	}
	dfs(0);
	cout << res;
}
