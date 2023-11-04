#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace	std;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int n, m;
	unordered_set<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		s.insert(input);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		if (s.find(input) == s.end())
			cout << "0 ";
		else
			cout << "1 ";
	}
}
