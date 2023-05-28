#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) // 최대공약수
{
    while(1)
    {
        int r = a % b;
        if (r == 0)
            return b;
        a = b;
        b = r;
    }
}

int solution(vector<int> arr) {
    int cur = arr[0];
    
    for (int i = 1; i < arr.size(); i++)
        cur = cur * arr[i] / gcd(cur , arr[i]); // 최소공배수 구하기
    return cur;
}