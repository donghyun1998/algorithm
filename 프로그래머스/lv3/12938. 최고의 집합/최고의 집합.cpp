#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (n > s)
    {
        answer.push_back(-1);
        return answer;
    }
    int cnt = s / n; // 그대로 넣어줄 값
    int no_plus_cnt = n - s % n; // 1씩 더해줄 개수
    for (int i = 0; i < n; i++)
    {
        if (no_plus_cnt > 0)
        {
            no_plus_cnt--;
            answer.push_back(cnt);
        }
        else
            answer.push_back(cnt + 1);
    }
    return answer;
}