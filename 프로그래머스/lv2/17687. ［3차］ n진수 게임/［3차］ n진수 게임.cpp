#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<char>    numArr;

string getStringValue(int value, int n) { // n == 진법
    string res = "";
    if (value == 0)
        res += '0';
    while (value) {
        res += numArr[value % n];
        value /= n;
    }
    reverse(res.begin(), res.end());
    return (res);
}


string solution(int n, int t, int m, int p) {
    // 진법 n, 미리 구할 숫자의 갯수 t, 게임에 참가하는 인원 m, 튜브의 순서 p
    numArr = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string game = "", res = "";
    int value = 0;
    while (game.size() < t * m)
        game += getStringValue(value++, n);
    for (int i = 0; i < t; i++)
        res += game[i * m + p - 1];
    return res;
}