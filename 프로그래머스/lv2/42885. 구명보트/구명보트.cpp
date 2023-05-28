#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int>  dq(people.begin(), people.end());
    
    sort(dq.begin(), dq.end()); // 정렬 해주고
    while (!dq.empty())
    {
        if (dq.front() + dq.back() <= limit) // 둘다 탈 수 있음
            dq.pop_front();
        if (!dq.empty())
            dq.pop_back();
        answer++;
    }
    return answer;
}