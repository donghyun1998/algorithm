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
#include <cstring>
using namespace std;
 // 9:20pm ~
bool isValid[10];
int target, wrongCnt, channel = 100;

int getLength(int num) {
	int i = 0;
	if (num == 0)
		return 1;
	while (num) {
		num /= 10;
		i++;
	}
	return i;
}

void dfs(int num) {
	if (abs(num - target) < abs(channel - target))
		channel = num;
	else if (abs(num - target) == abs(channel - target) && getLength(num) < getLength(channel))
		channel = num;
	for (int i = 0; i <= 9; i++) {
		if (isValid[i]) {
			int cur = num * 10 + i;
			if (abs(num - target) > abs(cur - target))
				dfs(cur);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(isValid, 1, sizeof(isValid));
	cin >> target >> wrongCnt;
	for (int i = 0; i < wrongCnt; i++) {
		int input;
		cin >> input;
		isValid[input] = false;
	}
	int noChangeChannelCnt = abs(target - channel);
	for (int i = 0; i <= 9; i++)
		if (isValid[i])
			dfs(i);
	// cout << "channel: " << channel <<endl;
	int res = getLength(channel) + abs(target - channel);
	cout << min(res, noChangeChannelCnt);
}
