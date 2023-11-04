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
	int start = 0, sum = v[0];
	for (int end = 0; end < v.size(); end++) {
		while (start + 1 <= end && sum - v[start] >= m)
			sum -= v[start++];
		if (sum >= m)
			res = min(res, end - start + 1); // 길이니까 + 1
		sum += v[end + 1];
	}
	if (res == 2147483647)
		cout << '0';
	else
		cout << res;
}
