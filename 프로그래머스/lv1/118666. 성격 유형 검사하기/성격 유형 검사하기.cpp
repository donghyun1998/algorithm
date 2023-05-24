#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int>    map;
    
    map['R'] = 0; // 사전 순으로 빠른 애들을 key로 map을 만들어준다.
    map['C'] = 0;
    map['J'] = 0;
    map['A'] = 0;
    
    for (int i = 0; i < survey.size(); i++)
    {
        if (map.find(survey[i][0]) != map.end()) // 앞에꺼가 키
            map[survey[i][0]] -= (choices[i] - 4);
        else // 뒤에꺼가 키
            map[survey[i][1]] += (choices[i] - 4);
        // cout << map['R'] << ' ' << map['C'] << ' ' << map['J'] << ' ' << map['A'] << '\n';
    }
    
    if (map['R'] >= 0)
        answer.push_back('R');
    else
        answer.push_back('T');
    if (map['C'] >= 0)
        answer.push_back('C');
    else
        answer.push_back('F');
    if (map['J'] >= 0)
        answer.push_back('J');
    else
        answer.push_back('M');
    if (map['A'] >= 0)
        answer.push_back('A');
    else
        answer.push_back('N');
    return answer;
}