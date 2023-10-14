#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace	std;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int M, woodLen, res = 0;
	vector<pair<int, int> > v;

	cin >> M >> woodLen;
	for (int i = 0; i < M; i++) {
		pair<int, int> input;
		cin >> input.first >> input.second;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	int startIdx = -1;
	for (int i = 0; i < M; i++) {
		if (startIdx >= v[i].second) // 이미 널빤지로 막힌 웅덩이면
			continue;
		startIdx = max(startIdx, v[i].first);
		int dist = v[i].second - startIdx;
		if (dist % woodLen)
			dist += woodLen - dist % woodLen;
		startIdx += dist;
		res += dist / woodLen;
	}
	cout << res;
}
