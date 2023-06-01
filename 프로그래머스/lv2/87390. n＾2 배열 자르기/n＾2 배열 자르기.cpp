#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    while (left <= right)
    {
        int x = left / n, y = left % n;
        if (x >= y)
            answer.push_back(x + 1);
        else
            answer.push_back(y + 1); // index니까 1 더해줌
        left++;
    }
    return answer;
}

// 만약 arr[x][y] 에서 x > y 이면 x이고 x < y 이면 y다

// arr[i / n][i % n]