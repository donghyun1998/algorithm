#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <cstring>
#include <utility>

using namespace	std;

string s, p;

bool canCopy(int startIdx, int len) {
	for (int i = 0; i + len <= s.size(); i++) {
		for (int j = 0; j < len; j++) {
			if (s[i + j] != p[startIdx + j])
				break ;
			if (j == len - 1)
				return true;
		}
	}
	return false;
}

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> s >> p;
	int idx = 0, len = p.size(), cnt = 0;

	while (idx < p.size()) {
		if (canCopy(idx, len)) {
			cnt++;
			idx += len;
			len = p.size() - idx + 1;
		}
		len--;
	}
	cout << cnt;
}
