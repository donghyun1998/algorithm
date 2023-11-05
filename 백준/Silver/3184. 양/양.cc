#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace	std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool visit[300][300];
vector<string> board;
int res_sheep = 0, res_wolf = 0;
int n, m;

void bfs(int start_x, int start_y) {
	int sheep = 0, wolf = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(start_x, start_y));
	visit[start_x][start_y] = true;
	if (board[start_x][start_y] == 'o')
		sheep++;
	else if (board[start_x][start_y] == 'v')
		wolf++;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i], new_y = y + dy[i];
			if (new_x < 0 || new_x > n || new_y < 0 || new_y > m
			|| board[new_x][new_y] == '#' || visit[new_x][new_y] == true)
				continue;
			q.push(make_pair(new_x, new_y));
			visit[new_x][new_y] = true;
			if (board[new_x][new_y] == 'o')
				sheep++;
			else if (board[new_x][new_y] == 'v')
				wolf++;
		}
	}
	if (sheep > wolf)
		res_sheep += sheep;
	else
		res_wolf += wolf;
}


int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin >> n >> m;
	board = vector<string>(n);

	// o == 양 v == 늑대
	for (int i = 0; i < n; i++)
		cin >> board[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (visit[i][j] == false && (board[i][j] == 'v' || board[i][j] == 'o'))
				bfs(i, j);
	cout << res_sheep << ' ' << res_wolf;
}
