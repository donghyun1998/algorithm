#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string>  ft_split(string s) // 공백을 구분자로 잘라준다
{
    vector<string>  res;
    
    int space_idx1 = 0, space_idx2 = 0;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (space_idx1 == 0)
                space_idx1 = i;
            else
                space_idx2 = i;
        }
    }
    res.push_back(s.substr(0, space_idx1));
    if (space_idx2 == 0)
        res.push_back(s.substr(space_idx1 + 1, s.size() - space_idx1));
    else
    {
        res.push_back(s.substr(space_idx1 + 1, space_idx2 - space_idx1 - 1));
        res.push_back(s.substr(space_idx2 + 1, s.size() - space_idx2));
    }
    return res;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string>   db;
    
    for (int i = 0; i < record.size(); i++)
    {
        vector<string>  split = ft_split(record[i]); // split[0] : 상호작용, 1:uid, 2: 닉네임
               
        if (split[0] == "Enter") // uid에 해당하는 닉네임 넣어줌
            db[split[1]] = split[2];
        else if (split[0] == "Change") // 바꿔줌
            db[split[1]] = split[2];
    }
    
    for (int i = 0; i < record.size(); i++)
    {
        vector<string>  split = ft_split(record[i]); // split[0] : 상호작용, 1:uid, 2: 닉네임
               
        if (split[0] == "Enter")
            answer.push_back(db[split[1]] + "님이 들어왔습니다.");
        else if (split[0] == "Leave")
            answer.push_back(db[split[1]] + "님이 나갔습니다.");
    }
    return answer;
}