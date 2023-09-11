#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace	std;
vector<string> input;
int n, m;

int getDiffWhiteBoard(int startX, int startY) {
	int res = 0;
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			int curX = x + startX;
			int curY = y + startY;
			if ((curX % 2 == 0 && curY % 2 == 0) || (curX % 2 == 1 && curY % 2 == 1)){
				if (input[curX][curY] == 'B') // wbwbwb 일때 arr[x][y] 짝수 짝수 홀수 홀수
					res++;
			}
			else {
				if (input[curX][curY] == 'W')
					res++;
			}
		}
	}
	return res;
}

int getDiffBlackBoard(int startX, int startY) {
	int res = 0;
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			int curX = x + startX;
			int curY = y + startY;
			if ((curX % 2 == 0 && curY % 2 == 0) || (curX % 2 == 1 && curY % 2 == 1)){
				if (input[curX][curY] == 'W') // wbwbwb 일때 arr[x][y] 짝수 짝수 홀수 홀수
					res++;
			}
			else {
				if (input[curX][curY] == 'B')
					res++;
			}
		}
	}
	return res;
}

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	int res = 2147483647;
	for (int i = 0; i < n; i++) {
		string cur;
		cin >> cur;
		input.push_back(cur);
	}
	for (int x = 0; x + 8 <= n; x++)
		for (int y = 0; y + 8 <= m; y++)
			res = min(res, min(getDiffBlackBoard(x, y), getDiffWhiteBoard(x, y)));
	cout << res;
}
