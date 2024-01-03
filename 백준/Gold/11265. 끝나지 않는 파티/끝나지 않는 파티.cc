// 끝나지 않는 파티
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > board;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n, m;
	cin >> n >> m;
	board = vector<vector<int> >(n,vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][k] + board[k][j] < board[i][j])
					board[i][j] = board[i][k] + board[k][j];
			}
		}
	}

	while (m--) {
		int a, b, time;
		cin >> a >> b >> time;
		if (board[a - 1][b - 1] <= time)
			cout << "Enjoy other party\n";
		else
			cout << "Stay here\n";
	}
}
