#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int min_n, max_n, first_flag = 1;
    
    for (int i = 0; i < s.size(); i++)
    {
        int cur = 0, minus = 1;
        if (s[i] == '-') // 부호 찾음
        {
            minus = -1;
            i++;
        }
        while (i < s.size() && s[i] != ' ') // 숫자일때까지 더해서 cur 구하기
            cur = cur * 10 + s[i++] - '0';
        cur *= minus;
        if (first_flag)
        {
            min_n = cur;
            max_n = cur;
            first_flag = 0;
            continue ;
        }
        max_n = max(cur, max_n);
        min_n = min(cur, min_n);
    }
    answer += to_string(min_n);
    answer += ' ';
    answer += to_string(max_n);
    return answer;
}