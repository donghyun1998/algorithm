// 농장 관ㅣ

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[8] = {0, -1, 0, 1, -1, 1, -1, 1};

using namespace std;
vector<vector<int> > board;
int col, row, mountain_top;
vector<vector<bool> > vis;

int getMaxHeight() {
	int res = 0;
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			if (board[i][j] > res)
				res = board[i][j];
	return res;
}

void turnVisitZero() {
	for (int i = 0; i < col; i++) // 방문한 애들 다 0 만들어줌
		for (int j = 0; j < row; j++)
			if (vis[i][j])
				board[i][j] = 0;
}

void bfs(int start_x, int start_y) {
	mountain_top++;
	vis[start_x][start_y] = true;
	queue<pair<int, int> >	q;
	q.push(make_pair(start_x, start_y));

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int new_x = x + dx[i], new_y = y + dy[i];
			if (new_x < 0 || new_x >= col || new_y < 0 || new_y >= row || vis[new_x][new_y] == true)
				continue;
			if (board[new_x][new_y] <= board[x][y]) { // 새로운 지점이 현재 위치보다 낮으면
				q.push(make_pair(new_x, new_y));
				vis[new_x][new_y] = true;
			}
		}
	}
}

void print() {
	cout << endl;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	cin >> col >> row;
	board = vector(col, vector(row, 0));
	vis = vector(col, vector<bool>(row, false));

	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			cin >> board[i][j];
	while (true) {
		int max_height = getMaxHeight();
		if (max_height == 0)
			break ;
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++){
				if (board[i][j] == max_height && vis[i][j] == false) {
					bfs(i, j);
					turnVisitZero();
					// print();///////////
					// cout << "maxheight:  " << max_height << endl;
				}
			}
		}
	}
	cout << mountain_top;
}
