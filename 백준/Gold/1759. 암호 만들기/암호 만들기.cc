#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <cstring>
#include <utility>

using namespace	std;

int len, num;
string s, moum = "aeiou";

void dfs(string cur, int depth) {
	if (cur.size() == len) {
		int moumCnt = 0;
		for (int i = 0; i < len; i++)
			for (int j = 0; j < 5; j++)
				if (moum[j] == cur[i])
					moumCnt++;
		if (moumCnt != 0 && len - moumCnt >= 2)
			cout << cur << '\n';
		return ;
	}
	for (int i = depth; i < num; i++)
		dfs(cur + s[i], i + 1);
}

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> len >> num;
	for (int i = 0; i < num; i++) {
		char input;
		cin >> input;
		s += input;
	}
	sort(s.begin(), s.end());
	// cout << s << ' ';
	// cout << endl; ///////////
	dfs("", 0);
}
