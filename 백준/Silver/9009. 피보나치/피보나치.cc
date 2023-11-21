#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> fibo, input;

void f(int target) {
	vector<int> res;
	int idx = fibo.size() - 1;
	while (target > 0) {
		while (fibo[idx] > target)
			idx--;
		target -= fibo[idx];
		res.push_back(fibo[idx]);
	}
	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i] << ' ';
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input_n;
		cin >> input_n;
		input.push_back(input_n);
	}

	int maxx = -1;
	for (int i = 0; i < input.size(); i++)
		maxx = max(input[i], maxx);

	fibo.push_back(0);
	fibo.push_back(1);
	for (int i = 2; fibo[i - 1] + fibo[i - 2] <= maxx; i++)
		fibo.push_back(fibo[i - 1] + fibo[i - 2]);

	for (int i = 0; i < input.size(); i++)
		f(input[i]);
}
