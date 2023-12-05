#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int child, team;
	cin >> child >> team;
	vector<int> v(child, 0);
	for (int i = 0; i < child; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	vector<int> diff;
	int res = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		int cur_diff = v[i + 1] - v[i];
		diff.push_back(cur_diff);
		res += cur_diff;
	}
	sort(diff.begin(), diff.end(), greater<int>());
	for (int i = 0; i < team - 1; i++)
		res -= diff[i];
	cout << res;
}
