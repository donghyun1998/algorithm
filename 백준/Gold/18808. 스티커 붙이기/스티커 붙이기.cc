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

struct Sticker {
	vector<vector<int> > shape[4]; // 돌려가면서 만들 모양
	int col[4];
	int row[4];
};
int col, row, sNum, sArea = 0; // sticker 개수
vector<Sticker> s;
vector<vector<int> > board;
void printVector(vector<vector<int> > v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
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

// 11 12 13
// 21 22 23
// 31 32 33

// 31 21 11
// 32 22 12
// 33 23 13 정신나가겠네
void	turnSticker() { // 1 2 3 버전 돌려서 등록해줌
	for (int i = 0; i < s.size(); i++) {
		for (int j = 1; j < 4; j++) {
			s[i].shape[j] = getTurnedBoard(s[i].shape[j - 1]);
			s[i].col[j] = s[i].row[j - 1];
			s[i].row[j] = s[i].col[j - 1];
		}
	}
}

int getSArea() {
	int cnt = 0;
	for (int x = 0; x < col; x++)
		for (int y = 0; y < row; y++)
			if (board[x][y])
				cnt++;
	return cnt;
}


bool canPutSticker(int startX, int startY, int sIdx, int dir) {
	for (int x = 0; x < s[sIdx].col[dir]; x++) {
		for (int y = 0; y < s[sIdx].row[dir]; y++) {
			if (board[startX + x][startY + y] == 1 && s[sIdx].shape[dir][x][y] == 1)
				return false;
		}
	}
	return true;
}

void putSticker(int startX, int startY, int sIdx, int dir) {
	for (int x = 0; x < s[sIdx].col[dir]; x++) {
		for (int y = 0; y < s[sIdx].row[dir]; y++) {
			if (s[sIdx].shape[dir][x][y] == 1)
				board[startX + x][startY + y] = 1;
		}
	}
}

void	dfs(int sIdx) {
	if (sIdx == s.size()) {
		int curSArea = getSArea();
		sArea = max(sArea, curSArea);
		// printVector(board);
		return ;
	}
	bool flag = true;
	for (int dir = 0; dir < 4; dir++) { // 4방향 다
		for (int startX = 0; startX <= col - s[sIdx].col[dir]; startX++) {
			for (int startY = 0; startY <= row - s[sIdx].row[dir]; startY++) {
				if (flag && canPutSticker(startX, startY, sIdx, dir)) {
					// cout << "x, y" << startX << "," << startY << endl;
					flag = false;
					vector<vector<int> > backup = board;
					putSticker(startX, startY, sIdx, dir);
					// printVector(board);
					dfs(sIdx + 1);
					board = backup;
				}
			}
		}
	}
	if (flag)
		dfs(sIdx + 1); // 스티커 안붙히는 경우
}

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin >> col >> row >> sNum;
	for (int i = 0; i < col; i++) {
		vector<int> V;
		for (int j = 0; j < row; j++)
			V.push_back(0);
		board.push_back(V);
	}
	for (int i = 0; i < sNum; i++) {
		int sCol, sRow, arg;
		cin >> sCol >> sRow;
		Sticker input;
		for (int x = 0; x < sCol; x++) {
			vector<int> inputV;
			for (int y = 0; y < sRow; y++) {
				cin >> arg;
				inputV.push_back(arg);
			}
			input.shape[0].push_back(inputV);
		}
		input.col[0] = input.shape[0].size();
		input.row[0] = input.shape[0][0].size();
		s.push_back(input);
	}
	turnSticker();
	dfs(0);
	cout << sArea;
}
