#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string>  split(string s, char sep)
{
    vector<string>  result;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == sep)
        {
            result.push_back(s.substr(0, i));
            result.push_back(s.substr(i + 1, s.size() - i - 1));
            break ;
        }
    }
    return (result);
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, int> report_map; // 이름 / 신고한 횟수
    unordered_map<string, int> reported_map; // 이름 / 신고된 횟수
    
    sort(report.begin(), report.end());
    for (int i = 0; i < id_list.size(); i++)
    {
        report_map[id_list[i]] = 0;
        reported_map[id_list[i]] = 0;
    }
    for (int i = 0; i < report.size(); i++)
    {
        if (i != 0 && report[i] == report[i - 1]) // 똑같은 사람 신고하면 넘어감
            continue ;
        vector<string> result = split(report[i], ' ');
        reported_map[result[1]] += 1; // 신고당한애 cnt++
    }
    for (int i = 0; i < report.size(); i++)
    {
        if (i != 0 && report[i] == report[i - 1]) // 똑같은 사람 신고하면 넘어감
            continue ;
        vector<string> result = split(report[i], ' ');
        if (reported_map[result[1]] >= k) // k번이상 신고먹은놈이면
            report_map[result[0]] += 1; // 신고자 cnt++
    }
    for (int i = 0; i < id_list.size(); i++)
        answer.push_back(report_map[id_list[i]]);
    return answer;
}