#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<string>	ft_split(string s, char sep) // 구분자 하나짜리
{
	vector<string>	res;
	int	start_idx = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == sep)
		{
			if (i > start_idx)
				res.push_back(s.substr(start_idx, i - start_idx));
			start_idx = i + 1;
		}
	}
		if (start_idx < s.size())
			res.push_back(s.substr(start_idx, s.size() - start_idx));
	return (res);
}

bool    cmp(string a, string b)
{
    return (a.size() < b.size());
}

int getNumLen(int i, string s) // 현재 튜플안의 숫자의 길이 리턴
{
    int res = 0;
    while (s[i + res] != ',' && s[i + res] != '}')
        res++;
    return (res);
}

vector<int> solution(string s) {
    vector<int>         answer;
    vector<string>      split = ft_split(s, '{'); // "숫자, 숫자, 숫자}," 이런식으로 잘리게 된다.
    unordered_set<int>  set;
    
    sort(split.begin(), split.end(), cmp);
    for (int i = 0; i < split.size(); i++) // , 하나 넘겨야 하니까 i++
    {
        int idxTuple = 0;
        while (split[i][idxTuple] != ',' && split[i][idxTuple] != '}')
        {
            int numLen = getNumLen(idxTuple, split[i]);
            int curNum = stoi(split[i].substr(idxTuple, numLen));
            if (set.find(curNum) == set.end()) // 없는거 == 새로 생긴 인자면
            {
                set.insert(curNum);
                answer.push_back(curNum);
                break ;
            }
            idxTuple += numLen + 1;
        }
    }
    return answer;
}