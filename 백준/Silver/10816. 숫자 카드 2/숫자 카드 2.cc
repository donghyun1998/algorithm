#include <iostream>
#include <unordered_map>

using namespace	std;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0);

	int N, M;
	unordered_map<int, int> m;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int cur;
		cin >> cur;
		if (m.find(cur) != m.end())
			m[cur] += 1;
		else
			m[cur] = 1;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int cur;
		cin >> cur;
		if (m.find(cur) == m.end())
			cout << 0 << ' ';
		else
			cout << m[cur] << ' ';
	}
}
