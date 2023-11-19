#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <cstring>

using namespace	std;
int dp[101][10];

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int N;
	cin >> N;

	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][0] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][9] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

			dp[i][j] %= 1000000000;
		}
	}
	int res = 0;
	for (int i = 0; i < 10; i++) {
		res += dp[N][i];
		res %= 1000000000;
	}
	cout << res;
}
