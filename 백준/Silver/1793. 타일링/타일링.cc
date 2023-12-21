// 타일링
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string add(string a, string b) {
	string res;

	int alen = a.size() - 1, blen = b.size() - 1;
	int oLLim = 0;

	for (int i = 0; alen - i >= 0 || blen - i >= 0; i++) {
		int an = 0, bn = 0;
		if (alen - i >= 0)
			an = a[alen - i] - '0';
		if (blen - i >= 0)
			bn = b[blen - i] - '0';
		int sum = an + bn + oLLim;
		if (sum > 9) {
			sum -= 10;
			oLLim = 1;
		} else {
			oLLim = 0;
		}
		res += '0' + sum;
	}
	if (oLLim)
		res += '1';
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	vector<string> dp(251);

	dp[0] = "1";
	dp[1] = "1";
	for(int i = 2; i < 251; i++) {
		dp[i] = add(add(dp[i - 1], dp[i - 2]), dp[i - 2]);
	}
	int input;
	while (cin >> input) {
		cout << dp[input] << '\n';
	}
}
