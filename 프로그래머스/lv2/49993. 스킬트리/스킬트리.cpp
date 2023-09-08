#include <string>
#include <vector>
using namespace std;
string sk;

bool isSkill(char c) {
    for (int i = 0; i < sk.size(); i++) {
        if (sk[i] == c)
            return true;
    }
    return false;
}


int solution(string skill, vector<string> tree) {
    int answer = 0;
    sk = skill;
    for (int i = 0; i < tree.size(); i++) {
        int skillIdx = 0;
        for (int j = 0; j < tree[i].size(); j++) {
            if (isSkill(tree[i][j]) && tree[i][j] != skill[skillIdx++])
                    break ;
            if (j == tree[i].size() - 1)
                answer++;
        }       
    }
    return answer;
}