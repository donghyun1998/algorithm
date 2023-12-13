// 자원 캐기
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > board;
vector<vector<int> > dp;
int col, row, res;

void goDown(int x, int y) {
	for (; x < col; x++)
	{
		int prev1 = 0, prev2 = 0;
		if (x - 1 >= 0)
			prev1 = dp[x - 1][y];
		if (y - 1 >= 0)
			prev2 = dp[x][y - 1];
		dp[x][y] = max(prev1, prev2) + board[x][y];
	}
}
void goRight(int x, int y) {
	for (; y < row; y++)
	{
		int prev1 = 0, prev2 = 0;
		if (x - 1 >= 0)
			prev1 = dp[x - 1][y];
		if (y - 1 >= 0)
			prev2 = dp[x][y - 1];
		dp[x][y] = max(prev1, prev2) + board[x][y];
	}
}

int main () {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin >> col >> row;
	board = vector(col, vector(row, 0));
	dp = vector(col, vector(row, 0));

	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			cin >> board[i][j];

	for (int dist = 0; dist < min(col, row); dist++) {
		goDown(dist, dist);
		goRight(dist, dist);
	}

	cout << dp[col - 1][row - 1];
}
