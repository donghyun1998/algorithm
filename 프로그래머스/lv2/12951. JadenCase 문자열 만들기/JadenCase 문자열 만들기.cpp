#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

string solution(string s) {
    int first_flag = 1;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            first_flag = 1;
        if (first_flag)
        {
            if (s[i] == ' ')
                continue ;
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32;
            first_flag = 0;
        }
    }
    return s;
}