#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string open = "([{", close = ")]}";
    for (int x = 0; x < s.size(); x++)
    {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
            if (stk.empty())
            {
                stk.push(s[i]);
                continue ;
            }
            for (int j = 0; j < 3; j++)
            {
                if (stk.top() == open[j] && s[i] == close[j])
                {
                    stk.pop();
                    break ;
                }
                else if (j == 2) // 짝이 맞지 않으면
                    stk.push(s[i]);
            }
        }
        if (stk.empty())
            answer++;
        s = s.substr(1, s.size() - 1) + s.substr(0, 1);
        // cout << s << '\n';
    }
    // cout << open << ' ' << close;
    return answer;
}