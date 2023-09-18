#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <cstring>
#include <utility>
#include <climits> // int32max

using namespace	std;
int dx[4] = { 0, 1 ,0, -1}; // 오 아 왼 위
int dy[4] = { 1, 0 ,-1, 0};
vector<pair<int, int> > cctv;
vector<vector<int> > board;
int col, row, res = INT32_MAX;

int countZero() {
	int cnt = 0;
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			if (board[i][j] == 0)
				cnt++;
	return cnt;
}

void changeMonitoringArea(int x, int y, int curDx, int curDy) {
	while (x < col && x >= 0 && y < row && y >= 0 && board[x][y] != 6) {
		if (board[x][y] == 0)
			board[x][y] = 7; // 감시영역 7로 표시
		x += curDx;
		y += curDy;
	}
}

void runCctv(int cctvIdx, int direction) {
	int x = cctv[cctvIdx].first;
	int y = cctv[cctvIdx].second;
	int cctvType = board[x][y];
	int curDx, curDy;

	if (true) {// 오른쪽
		curDx = dx[(0 + direction) % 4];
		curDy = dy[(0 + direction) % 4];
		changeMonitoringArea(x, y, curDx, curDy);
	}
	if (cctvType == 2 || cctvType == 4 || cctvType == 5) {// 왼쪽
		curDx = dx[(2 + direction) % 4];
		curDy = dy[(2 + direction) % 4];
		changeMonitoringArea(x, y, curDx, curDy);
	}
	if (cctvType == 3 || cctvType == 4 || cctvType == 5) {// 위
		curDx = dx[(3 + direction) % 4];
		curDy = dy[(3 + direction) % 4];
		changeMonitoringArea(x, y, curDx, curDy);
	}
	if (cctvType == 5) {// 아래
		curDx = dx[(1 + direction) % 4];
		curDy = dy[(1 + direction) % 4];
		changeMonitoringArea(x, y, curDx, curDy);
	}
}

void dfs(int depth) { // cctv 돌면서 4방향 보고있을 때 다 생각할거임
	if (depth == cctv.size()) { // cctv 다 봤음
		res = min(countZero(), res);
		return ;
	}
	for (int i = 0; i < 4; i++) {
		vector<vector<int> > backup(board);
		runCctv(depth, i);
		dfs(depth + 1);
		board = backup;
	}
}

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	// 6 == 벽
	cin >> col >> row;
	for (int i = 0; i < col; i++) {
		vector<int> v;
		for (int j = 0; j < row; j++) {
			int input;
			cin >> input;
			v.push_back(input);
			if (input >= 1 && input <= 5)
				cctv.push_back(make_pair(i, j)); // cctv 배열에 추가해주기
		}
		board.push_back(v);
	}
	dfs(0);
	cout << res;
}
