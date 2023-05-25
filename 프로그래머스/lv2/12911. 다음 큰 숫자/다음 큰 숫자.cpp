#include <string>
#include <vector>
#include <iostream>

using namespace std;

int get_one_cnt(int num)
{
    int res = 0;
    int multi = 1;
    while (2 * multi <= num)
        multi *= 2;
    while (num > 0 && multi >= 1)
    {
        if (num - multi >= 0)
        {
            res++;
            num -= multi;
        }
        multi /= 2;
    }
    // cout << res << '\n';
    return res;
}

int solution(int n) {
    int one_cnt = get_one_cnt(n);
    while (get_one_cnt(++n) != one_cnt);
    return n;
}