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

int len, res = 2;
vector<vector<int> > board;

int getLargeNum() {
	int res = 0;
	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[0].size(); j++)
			res = max(res, board[i][j]);
	return res;
}
vector<vector<int> > getTurnedBoard(vector<vector<int> > b) {
	int col = b[0].size(), row = b.size();

	vector<vector<int> > res(col, vector<int>(row, 0));
	for (int x = 0; x < col; x++) {
		for (int y = 0; y < row; y++) {
			res[x][y] = b[row - y - 1][x];
		}
	}
	return res;
}

void swipe() { // 왼쪽으로 밀겠음 왜냐? 생각하기 편하니까!
	for (int x = 0; x < len; x++) {
		for (int y = 0; y < len - 1; y++) {
			int diff = 1;
			while (y + diff < len && board[x][y + diff] == 0)
				diff++; // 중간에 0 들어있을 수 있걸랑
			if (board[x][y] == board[x][y + diff]) {
				board[x][y] *= 2; // 같은 숫자 다 합쳐줌
				board[x][y + diff] = 0;
			}
			y += diff - 1;
		}
		vector<int> v;
		for (int y = 0; y < len; y++)
			if (board[x][y] != 0)
				v.push_back(board[x][y]);
		for (int y = 0; y < len; y++) {
			if (y < v.size())
				board[x][y] = v[y];
			else
				board[x][y] = 0;
		}
	}
}

void	dfs(int depth) {
	if (depth == 5) {
		res = max(res, getLargeNum());
		return ;
	}
	for (int i = 0; i < 4; i++) { // 4방향
		vector<vector<int> > backup(board);
		swipe();
		dfs(depth + 1);
		board = getTurnedBoard(backup);
	}
}

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin >> len;
	vector<vector<int> > v(len, vector<int>(len));
	board = v;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			cin >> board[i][j];
	dfs(0);
	cout << res;
}
