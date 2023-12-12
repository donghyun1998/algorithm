// 주사위 쌓기

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// (0, 5), (1, 3), (2, 4) 한 쌍임

vector<vector<int> > board;
vector<unordered_map<int, int> > vm;
int n, res = 0, cur_res = 0;

int dice[6] = {5, 3, 4, 1, 2, 0};

void f(int floor, int badak) {
	if (floor == n) {
		res = max(res, cur_res);
		return ;
	}
	int chunjang = vm[floor][badak];
	if (badak != 6 && chunjang != 6)
		cur_res += 6;
	else if (badak != 5 && chunjang != 5)
		cur_res += 5;
	else
		cur_res += 4;
	f(floor + 1, chunjang);
}

int main () {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	board = vector(n, vector(6, 0));
	vm = vector(n, unordered_map<int, int>());

	for (int i = 0; i < n; i++){
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j];
		}
		for (int j = 0; j < 6; j++) {
			vm[i][board[i][j]] = board[i][dice[j]];
		}
	}
	for (int i = 0; i < 6; i++) {
		cur_res = 0;
		f(0, board[0][i]);
	}
	cout << res;
}
