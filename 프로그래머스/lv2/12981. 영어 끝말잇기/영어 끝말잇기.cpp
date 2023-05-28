#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    char    first_char = words[0][0];
    unordered_set<string>  s; // 여태 사용한 단어 담기
    
    for (int i = 0; i < words.size(); i++)
    {
        if (s.find(words[i]) == s.end() && first_char == words[i][0]) // 여태 나오지 않은 단어면 , 끝말잇기 성립되면
        {
            s.insert(words[i]);
            first_char = words[i][words[i].size() - 1];
        }
        else
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            return (answer);
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}