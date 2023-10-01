#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <unordered_set>
#include <cstring>
#include <utility>
#include <climits> // int32max

using namespace	std;
vector<string> board;
int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, -1 , 0, 1};

void printBoard() {
	for (int i = 0; i < 12; i++)
		cout << board[i] << endl;
	cout << endl;
}

bool	bfs(int inputX, int inputY) {
	vector<pair<int, int> >	sameXY;
	char type = board[inputX][inputY];
	vector<string> visit(board);
	queue<pair<int, int> > q;
	q.push(make_pair(inputX, inputY));
	sameXY.push_back(make_pair(inputX, inputY));
	visit[inputX][inputY] = 'V';

	while (!q.empty()) {
		int startX = q.front().first, startY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newX = startX + dx[i], newY = startY + dy[i];
			if (newX < 0 || newY < 0 || newX >= 12 || newY >= 6 || visit[newX][newY] == 'V')
				continue;
			if (board[newX][newY] == type) {
				sameXY.push_back(make_pair(newX, newY));
				q.push(make_pair(newX, newY));
				visit[newX][newY] = 'V';
			}
		}
	}
	// bfs돌려서 4개짜리인거 터트리고 .으로 바꿔주기
	if (sameXY.size() < 4)
		return false;
	for (int i = 0; i < sameXY.size(); i++)
		board[sameXY[i].first][sameXY[i].second] = '.';
	return true;
}

void fall() {
	for (int y = 0; y < 6; y++) {
		stack<char> stk;
		// 위에셔부터 .빼고 담아줌
		for (int x = 0; x < 12; x++) {
			if (board[x][y] != '.')
				stk.push(board[x][y]);
			board[x][y] = '.';
		}
		int x = 11;
		// 담은거 아래서부터 넣어줌
		while (!stk.empty()) {
			board[x][y] = stk.top();
			stk.pop();
			x--;
		}
	}
}

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int res = 0;

	for (int i = 0; i < 12; i++) {
		string input;
		cin >> input;
		board.push_back(input);
	}
	while (true) {
		int popCnt = 0;
		for (int x = 0; x < 12; x++) {
			for (int y = 0; y < 6; y++) {
				if (board[x][y] != '.') {
					if (bfs(x, y)) {
						popCnt++;
					}
				}
			}
		}
		// printBoard();
		fall();
		if (popCnt == 0) {
			cout << res;
			return 0;
		}
		res++;
	}
}
