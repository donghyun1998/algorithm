#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n,m;
	cin >> n >> m;
	unordered_set<string>	s;
	vector<string> res;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		s.insert(input);
	}
	for (int i = 0; i < m; i++) {
		string input;
		cin >> input;
		if (s.find(input) != s.end())
			res.push_back(input);
	}
	cout << res.size() << '\n';
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << '\n';
}
