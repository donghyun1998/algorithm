#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int> > board(9, vector<int>(9, 0));
vector<pair<int, int> > empty_xy;

bool check(int x, int y, int n) {
	for (int i = 0; i < 9; i++) {
		if (board[x][i] == n)
			return false;
		if (board[i][y] == n)
			return false;
	}

	int start_x = x / 3 * 3, start_y = y / 3 * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[start_x + i][start_y + j] == n)
				return false;
		}
	}
	return true;
}

bool recur(int depth) {
	if (depth == empty_xy.size()) return true;

	for (int n = 1; n <= 9; n++) {
		int x = empty_xy[depth].first;
		int y = empty_xy[depth].second;
		if (check(x, y, n)) {
			board[x][y] = n;
			if (recur(depth + 1))
				return true;
			board[x][y] = 0;
		}
	}
	return false;
}

int main () {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				empty_xy.push_back(make_pair(i, j));
		}
	}
	recur(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
}
