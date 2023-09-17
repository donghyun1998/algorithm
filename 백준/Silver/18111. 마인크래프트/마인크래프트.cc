#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <unordered_set>
#include <utility>
#include <cmath>
using namespace std;
vector<vector<int> > board;
int col, row, block, sum = 0, maxHeight = 0;

int getTimeOfWork(int height) {
	if (height > 256)
		return INT32_MAX;
	int remainBlock = sum + block - (height * col * row);
	if (remainBlock < 0) // block 모자랄때
		return INT32_MAX;
	int time = 0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			int distance = height - board[i][j];
			if (distance < 0) // 땅파야함
				time += distance * -2;
			else // 블록 추가해야함
				time += distance;
		}
	}
	return time;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	// 블록 제거 2초
	// 블록 추가 1초
	cin >> col >> row >> block;
	for (int i = 0; i < col; i++) {
		vector<int> v;
		for (int j = 0; j < row; j++) {
			int input;
			cin >> input;
			sum += input;
			maxHeight = max(maxHeight, input);
			v.push_back(input);
		}
		board.push_back(v);
	}
	int averageHeight = static_cast<int>(round(static_cast<double>(sum) / (col * row)));
	int curTime = getTimeOfWork(maxHeight);
	int minTime = curTime;
	int curHeight = maxHeight;
	int minHeight = curHeight;

	while (curHeight >= averageHeight) {
		curTime = getTimeOfWork(--curHeight);
		if (minTime > curTime) {
			minTime = curTime;
			minHeight = curHeight;
		}
	}
	cout << minTime << ' ' << minHeight;
}
