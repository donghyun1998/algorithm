#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long>   dp(n + 1);
    
    if (n < 4)
        return n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3; //만약 n이 1일때 오류가 난다
    
    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
        if (dp[i] >= 1234567)
            dp[i] %= 1234567;
    }
    return dp[n];
}