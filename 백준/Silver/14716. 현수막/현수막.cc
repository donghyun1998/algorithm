// 현수막
#include <iostream>
#include <vector>

using namespace std;

int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int col, row, cnt;
vector<vector<int> > board;

void floodFill(int x, int y) {
	board[x][y] = 0;
	for (int i = 0; i < 8; i++) {
		int new_x = x + dx[i], new_y = y + dy[i];
		if (new_x < 0 || new_x >= col || new_y < 0 || new_y >= row || board[new_x][new_y] == 0)
			continue;
		floodFill(new_x, new_y);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin >> col >> row;
	board = vector<vector<int> >(col, vector<int>(row, 0));
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			cin >> board[i][j];

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (board[i][j] == 1) {
				cnt++;
				floodFill(i, j);
			}
		}
	}
	cout << cnt;
}
