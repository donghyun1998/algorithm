#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <cstring>

using namespace	std;
int col, row, res = -1;
vector<string> board;
// unordered_set<char> s;
bool visit[27];
int dx[4] = {1, 0,-1 ,0};
int dy[4] = {0, -1, 0 ,1};

void dfs(int depth, int x, int y) {
	if (visit[board[x][y] - 'A'] == true) {
		res = max(depth, res);
		return ;
	}
	visit[board[x][y] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];
		if (newX < 0 || newY < 0 || newX >= col || newY >= row)
			continue;
		dfs(depth + 1, newX, newY);
	}
	visit[board[x][y] - 'A'] = false;
}


int	main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> col >> row;
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < col; i++) {
		string input;
		cin >> input;
		board.push_back(input);
	}
	dfs(0, 0, 0);
	cout << res;
}
