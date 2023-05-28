#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int cnt = 1;
    while (1)
    {
        if (a % 2 == 1)
            a++;
        if (b % 2 == 1) // 짝수를 기준으로 생각 (1, 2) (3, 4)
            b++;
        if (a == b)
            break ;
        a /= 2;
        b /= 2;
        cnt++;
    }
    return cnt;
}