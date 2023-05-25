#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 2]+ dp[i - 1];
        if (dp[i] >= 1234567)
            dp[i] %= 1234567;
    }
    return (dp[n]);
}