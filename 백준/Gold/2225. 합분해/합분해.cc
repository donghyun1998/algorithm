// 합분해

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<vector<long long> > dp(201, vector<long long>(201, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= n; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}
	cout << dp[k][n];
	return 0;
}
