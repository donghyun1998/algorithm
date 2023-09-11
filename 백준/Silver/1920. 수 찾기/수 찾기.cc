#include <iostream>
#include <vector>
#include <algorithm>

using namespace	std;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0);

	int N, M;
	vector<int>	v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int cur;
		cin >> cur;
		v.push_back(cur);
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		int cur;
		cin >> cur;
		if (binary_search(v.begin(), v.end(), cur))
			cout << '1' << '\n';
		else
			cout << '0' << '\n';
	}
}
