#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main () {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n;
	cin >> n;
	vector<string> input(n);
	map<string, int> m;
	for (int i = 0;i < n; i++)
		cin >> input[i];

	for (int i = 0; i < n; i++) {
		string s = input[i].substr(input[i].find('.') + 1);
		if (m.find(s) != m.end())
			m[s] += 1;
		else
			m[s] = 1;
	}
	for (auto it : m) {
		cout << it.first << ' ' << it.second << '\n';
	}
}
