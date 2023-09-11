#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace	std;
vector<string> input;
int n, m;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	deque<int> dq;
	for (int i = 1; i <= n; i++)
		dq.push_back(i);
	cout << '<';
	while (!dq.empty()) {
		for (int i = 1; i < m; i++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		if (dq.size() != 1)
			cout << dq.front() << ", ";
		else
			cout << dq.front() << ">";
		dq.pop_front();
	}

}
