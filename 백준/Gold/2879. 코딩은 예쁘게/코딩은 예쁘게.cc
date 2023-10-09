#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <cstring>
#include <utility>

using namespace	std;
vector<int> diff;
int res = 0, num;

bool isAllZero(int start, int end) {
	for (int i = start; i <= end; i++)
		if (diff[i] != 0)
			return false;
	return true;
}

void drag(int start, int end) {
	int minEle, maxEle;

	minEle = *min_element(diff.begin() + start, diff.begin() + end + 1);
	maxEle = *max_element(diff.begin() + start, diff.begin() + end + 1);

	if (diff[start] > 0) { // 양수
		for (int i = start; i <= end; i++)
			diff[i] -= minEle;
		res += minEle;
	}
	else { // 음수
		for (int i = start; i <= end; i++)
			diff[i] -= maxEle;
		res -= maxEle;
	}
}

int	main()
{
	vector<int> src, dst;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int input;
		cin >> input;
		src.push_back(input);
	}
	for (int i = 0; i < num; i++) {
		int input;
		cin >> input;
		dst.push_back(input);
	}
	for (int i = 0; i < num; i++)
		diff.push_back(src[i] - dst[i]);
	int start = 0, end = 0;
	while (start < num && isAllZero(start, num - 1) == false) {
		while (start < num && diff[start] == 0)
			start++;
		end = start;
		while (end + 1 < num && diff[start] * diff[end + 1] > 0) // 같은 부호
			end++;
		drag(start, end);
	}
	cout << res;
}
