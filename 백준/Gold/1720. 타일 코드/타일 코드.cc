// 타일 코드
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n;
	cin >> n;
	vector<int> dp(31, 0);

	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
	}

	if (n % 2) { // 홀수
		// 좌우 대칭인 경우 가운데 | 이거 한개만 가능이므로 dp[n / 2]개 있음
		cout << (dp[n] + dp[n / 2]) / 2;
	} else { // 짝수
		// 좌우 대칭인 경우 dp[n / 2 - 1] * 3개 있음 가운데 네모, ||, = 올 수 있음
		cout << (dp[n] + dp[n / 2] + dp[n / 2 - 1] * 2) / 2;
	}
	return 0;
}
