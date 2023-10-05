#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <cstring>
#include <utility>

using namespace	std;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int num, res = 0;
	cin >> num;
	vector<int> rope;
	for (int i = 0; i < num; i++) {
		int input;
		cin >> input;
		rope.push_back(input);
	}
	sort(rope.begin(), rope.end());
	for (int i = 0; i < num; i++)
		res = max(res, rope[i] * (num - i));
	cout << res;
}
