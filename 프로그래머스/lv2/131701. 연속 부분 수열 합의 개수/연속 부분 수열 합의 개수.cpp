#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0, sum_of_circle = 0;
    unordered_set<int> sum_set;
    
    for (int seq_len = 1; seq_len <= elements.size(); seq_len++) // len 만큼의 부분 수열의 합을 구함
    {
        for (int start_i = 0; start_i < elements.size(); start_i++) // 시작 인덱스가 i인 len만큼의 부분 수열의 합 구함
        {
            int sum = 0;
            for (int i = 0; i < seq_len; i++)
                sum += elements[(start_i + i) % elements.size()];
            sum_set.insert(sum);
        }
    }
    
    return (sum_set.size());
}