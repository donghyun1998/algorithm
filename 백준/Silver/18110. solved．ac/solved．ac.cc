#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <unordered_set>
#include <utility>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	double n;
	cin >> n;
	vector<int> v;
	int exclude = static_cast<int>(round(n * 0.15));
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	double res = 0;
	int resCnt = n - (exclude * 2);
	if (resCnt == 0) {
		cout << 0;
		return 0;
	}
	for (int i = exclude; i < n - exclude; i++)
		res += v[i];
	cout << round(res / resCnt);
}
