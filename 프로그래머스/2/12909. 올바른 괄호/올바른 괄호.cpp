#include<string>
#include <iostream>
#include <deque>

using namespace std;

bool solution(string s)
{
    deque<char> dq;
    
    for (int i = 0; i < s.size(); i++) {
        char cur = s[i];
        if (dq.empty())
            dq.push_back(cur);
        else if (dq.back() == '(' && cur == ')')
            dq.pop_back();
        else
            dq.push_back(cur);
    }
    if (dq.empty())
        return true;
    return false;

}