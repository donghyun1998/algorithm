#include <string>
#include <vector>

using namespace std;

vector<int> num;
int targ, answer;

void    recur(int idx, int res) {
    if (idx == num.size()) {
        if (res == targ)
            answer++;
        return ;   
    }
    recur (idx + 1, res - num[idx]);
    recur (idx + 1, res + num[idx]);
}

int solution(vector<int> numbers, int target) {
    num = numbers;
    targ = target;
    answer = 0;
    recur(0, 0);
    return answer;
}