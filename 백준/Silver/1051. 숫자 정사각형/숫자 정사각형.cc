#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int col, row;
	cin >> col >> row;
	int res = 1;
	vector<string> board;
	for (int i = 0; i < col; i++) {
		string input;
		cin >> input;
		board.push_back(input);
	}
	for (int x = 0; x < col; x++)
		for (int y = 0; y < row; y++)
			for (int dist = 1; x + dist < col && y + dist < row; dist++)
				if (board[x][y] == board[x + dist][y] && board[x][y] == board[x][y + dist] && board[x][y] == board[x + dist][y + dist])
					res = max(res, (dist + 1) * (dist + 1));
	cout << res;
}
