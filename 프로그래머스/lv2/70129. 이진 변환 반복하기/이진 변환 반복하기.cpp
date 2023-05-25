#include <string>
#include <vector>
#include <iostream>

using namespace std;

string binary_transformation(int num)
{
    string res = "";
    int multi = 1;
    while (2 * multi <= num)
        multi *= 2;
    // cout << num << ' ' << multi << '\n';
    while (num > 0 && multi >= 1)
    {
        if (num - multi >= 0)
        {
            res += '1';
            num -= multi;
        }
        else
            res += '0';
        multi /= 2;
    }
    while (multi > 0)
    {
        res += '0';
        multi /= 2;
    }
    return res;
}

vector<int> solution(string s) {
    vector<int> answer;
    int change_cnt = 0, zero_cnt = 0;
    
    while (s != "1")
    {
        int cur_one_cnt = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1')
                cur_one_cnt++; // 0의 개수
        zero_cnt += s.size() - cur_one_cnt;
        s = binary_transformation(cur_one_cnt);
        // cout << s << '\n';
        change_cnt++;
    }
    answer.push_back(change_cnt);
    answer.push_back(zero_cnt);
    return answer;
}