#include <string>
#include <string.h> // memset땜시
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//1
//22
//333
//4444  [3][3]
//55555 [4][3]. [4][4]

int solution(vector<vector<int>> triangle) {
    int size = triangle.size();
    int dp[size][size];
    
    memset (dp, 0, sizeof(dp));
    for (int i = 0; i < size; i++) // 맨 아래줄만 초기화
        dp[size - 1][i] = triangle[size - 1][i];
    for (int h = size - 2; h >= 0; h--) // 맨아래의 두번째 줄부터 더하면서 dp테이블 만든다.
        for (int w = 0; w < size - 2; w++)
            dp[h][w] = triangle[h][w] + max(dp[h + 1][w], dp[h + 1][w + 1]);
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    return (dp[0][0]);
}