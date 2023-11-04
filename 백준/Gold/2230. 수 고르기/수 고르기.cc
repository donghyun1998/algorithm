#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace	std;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int n, m, res = 2147483647;
	vector<int> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	int start = 0;
	for (int end = 0; end < v.size(); end++) {
		while (start + 1 < end && v[end] - v[start + 1] >= m)
			start++;
		if (v[end] - v[start] >= m)
			res = min(res , v[end] - v[start]);
	}
	cout << res;
}
