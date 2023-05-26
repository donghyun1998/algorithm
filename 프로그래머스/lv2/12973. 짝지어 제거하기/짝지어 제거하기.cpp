#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<int>  stk;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (stk.empty())
            stk.push(s[i]);
        else if (stk.top() == s[i])
                stk.pop();
        else
            stk.push(s[i]);
    }
    if (stk.empty())
        return (1);
    return (0);
}