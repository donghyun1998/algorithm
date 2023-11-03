#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int row, int col, vector<vector<int>> puddles) {
    int answer = 0; // row 가로 col 세로
    vector<vector<int> > board(col, vector<int>(row, 0));
    
    board[0][0] = 1;
    for (int i = 0; i < puddles.size(); i++)
        board[puddles[i][1] - 1][puddles[i][0] - 1] = -1; // 0 부터 시작이라 1씩 빼줌
    
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (board[i][j] == -1)
                continue ;
            int sum = 0;
            if (i - 1 >= 0 && board[i - 1][j] != -1)
                sum += board[i - 1][j];
            if (j - 1 >= 0 && board[i][j - 1] != -1)
                sum += board[i][j - 1];
            board[i][j] += sum % 1000000007;
        }
    }
    
    // for (int i = 0; i < col; i++) {
    //     for (int j = 0; j < row; j++)
    //         cout << board[i][j] << ' ';
    //     cout << endl;
    // }
    return board[col - 1][row - 1];
}