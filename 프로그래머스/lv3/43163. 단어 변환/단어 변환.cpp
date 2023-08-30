#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string Begin, Target;
vector<string> Words;
bool  visit[100] = { false, };
int res = 2147483647;

bool    canTransform(string a, string b) {
    if (a.size() != b.size())
        return false;
    int diffCnt = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            diffCnt++;
    if (diffCnt != 1)
        return false;
    return true;
}

void recur(string input, int depth) {
    if (input == Target) {
        res = depth;
        return ;
    }
    for (int i = 0; i < Words.size(); i++) {
        if (canTransform(input, Words[i]) && visit[i] == false) {
            visit[i] = true;   
            recur(Words[i], depth + 1);
            visit[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {    
    Begin = begin; Target = target; Words = words;
    if (find(words.begin(), words.end(), target) == words.end())
        return (0);
    recur(begin, 0);
    return res;
}