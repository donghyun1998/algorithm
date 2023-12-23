// 행렬 제곱
#include <iostream>
#include <vector>
using namespace std;
int n;
long long b;
vector<vector<int> > board;
// 00 01 02
// 10 11 12
// 20 21 22

int calculate(int x, int y, vector<vector<int> >& v1, vector<vector<int> >& v2) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += v1[x][i] * v2[i][y];
	}
	return res;
}

vector<vector<int> > multiple(vector<vector<int> >& v1, vector<vector<int> >& v2) {
	vector<vector<int> > res(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res[i][j] = calculate(i, j, v1, v2) % 1000;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> b;
	board = vector<vector<int> >(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	vector<vector<int> > res(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		res[i][i] = 1; // 단위 행렬로 만듬

	while (b > 0) {
		if (b % 2 == 1) {// 1이 남으면 res에 쌓아주다가 b == 1이되면 나간다
			res = multiple(res, board);
			if (b == 1)
				break ;
		}
		board = multiple(board, board);
		b /= 2;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << res[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
