#include <string>
#include <vector>
#include <set>
// #include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int>    ms;
    
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'I') {
            ms.insert(stoi(operations[i].substr(2))); // substr(숫자) 넣으면 숫자만큼 앞에 자른다
            // cout << stoi(operations[i].substr(2)) << endl;
        }
        else if (operations[i][2] == '-' && ms.size())
            ms.erase(ms.begin());
        else if (operations[i][2] == '1' && ms.size())
            ms.erase(--ms.end()); // 이렇게 하면 맨 마지막 요소 삭제 가능!!!!
    }
    if (ms.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    answer.push_back(*(--ms.end()));
    answer.push_back(*(ms.begin()));
    return answer;
}