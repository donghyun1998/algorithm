#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer, board;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (board.size() == 0)
        {
            board.push_back(s[i]);
            answer.push_back(-1);
            continue ;
        }
        for (int j = board.size() - 1; j >= 0; j--)
        {
            if (board[j] == s[i])
            {
                answer.push_back(board.size() - j);
                board.push_back(s[i]);
                break ;
            }
            if (j == 0)
            {
                answer.push_back(-1);
                board.push_back(s[i]);
            }
        }
    }
    return answer;
}