#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

void    setMap(unordered_map<string, int>   &map, string str, unordered_set<string> &set)
{
    for (int i = 0; i < str.size() - 1; i++)
    {
        string s = str.substr(i, 2);
        if (!islower(s[0]) || !islower(s[1]))
            continue ;
        set.insert(s);
        map[s] += 1;
    }
}

int solution(string str1, string str2) {
    int cnt_inter = 0, cnt_combin = 0;
    for (int i = 0; i < str1.size(); i++) // 다 소문자로 바꿔줌
        str1[i] = tolower(str1[i]);
    for (int i = 0; i < str2.size(); i++)
        str2[i] = tolower(str2[i]);
    unordered_map<string, int>   map1, map2;
    unordered_set<string>        set;
    setMap(map1, str1, set);
    setMap(map2, str2, set);
    for (auto s : set)
    {
        cnt_combin += max(map1[s], map2[s]);
        cnt_inter += min(map1[s], map2[s]);
        // cout << "s: " << s << " com: "<< max(map1[s], map2[s]) << " int: " << min(map1[s], map2[s]) << endl;
    }
    if (set.size() == 0) // 집합 A와 집합 B가 모두 공집합일 경우에는 나눗셈이 정의되지 않으니 따로 J(A, B) = 1
        return (65536);
    return 65536 * cnt_inter / cnt_combin;
}