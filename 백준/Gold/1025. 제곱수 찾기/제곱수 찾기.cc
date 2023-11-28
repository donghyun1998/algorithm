// 제곱수 찾기

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

int res = -1;
unordered_set<int> s;

void f2(int num) {
	// cout << num << endl;
	int sqrt_num = sqrt(num);
	if (sqrt_num * sqrt_num == num)
		res = max(res, num);
}

void f(const vector<int>& v) {
	for (int i = 1; i <= v.size(); i++) {
		int num = 0;
		for (int j = 0; j < i; j++)
			num = num * 10 + v[j];
		if (s.find(num) == s.end()) {
			s.insert(num);
			f2(num);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int col, row;
	cin >> col >> row;
	vector<vector<int> > board(col,vector<int>(row, 0));

	for (int i = 0;i < col; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < row; j++)
			board[i][j] = input[j] - '0';
	}

	for (int start_x = 0; start_x < col; start_x++) {
		for (int start_y = 0; start_y < row; start_y++) {
			for (int dist_x = -col; dist_x < col; dist_x++) { // dist 제일 작은 거부터 증가
				for (int dist_y = -row; dist_y < row; dist_y++) {
					if (dist_x == 0 && dist_y == 0) // 증가량 0 0 무한루프
						continue;
					vector<int> cur;
					for (int x = start_x, y = start_y;x >= 0 && x < col && y >= 0 && y < row; x += dist_x,y += dist_y) // 경계값 다 검사
						cur.push_back(board[x][y]);
					f(cur);
				}
			}
		}
	}
	cout << res;
}
