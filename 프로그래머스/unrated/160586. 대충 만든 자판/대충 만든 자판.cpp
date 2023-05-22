#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int>   map;
    
    for (int i = 0; i < keymap.size(); i++)
    {
        for (int j = 0; j < keymap[i].size(); j++)
        { // map에 문자를 key로 횟수를 value로 넣어준다
            if (map.find(keymap[i][j]) == map.end() || (map[keymap[i][j]] > j + 1))
                map[keymap[i][j]] = j + 1;
            // cout << "key: " << keymap[i][j] << " value: " << map[keymap[i][j]] << '\n';
        }
    }
    for (int i = 0; i < targets.size(); i++)
    {
        int sum = 0;
        
        for (int j = 0; j < targets[i].size(); j++)
        {
            if (map.find(targets[i][j]) == map.end())
            { // 없는 값일때 처리
                sum = -1;
                break ;
            }
            sum += map[targets[i][j]];
        }
        answer.push_back(sum);
    }   
    return answer;
}