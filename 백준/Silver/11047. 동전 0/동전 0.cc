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

	int coinNum, target, res = 0, prevCoinIdx;
	vector<int> coin;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> coinNum >> target;
	for (int i = 0; i < coinNum; i++) {
		int input;
		cin >> input;
		coin.push_back(input);
	}
	for (int i = coin.size() - 1; i >= 0; i--) {
		if (target == 0)
			break ;
		if (target < coin[i])
			continue ;
		for (int j = 1; target >= coin[i]; j++) {
			prevCoinIdx = i;
			target -= coin[i];
			res++;
		}
		if (i == 0 && target != 0) {
			target += coin[prevCoinIdx];
			i = prevCoinIdx - 1;
		}
	}
	cout << res;
}
