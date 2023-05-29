#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool    ft_cmp(pair<int, int> a, pair<int, int> b)
{
    return (a.second > b.second); // 역순 정렬
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> map;
    
    for (int i = 0; i < tangerine.size(); i++)
    {
        if (map.find(tangerine[i]) == map.end()) // 없으면
            map[tangerine[i]] = 1;
        else
            map[tangerine[i]] += 1;
    }
    
    vector<pair<int, int>> v(map.begin(), map.end()); // (key, value)를 pair로 가지는 vector 만들어줌
    sort(v.begin(), v.end(), ft_cmp);
    
    for (int i = 0; k > 0; i++)
    {
        k -= v[i].second;
        answer++;
    }
    return answer;
}