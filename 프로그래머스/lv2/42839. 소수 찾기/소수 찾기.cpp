#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool>    prime(10000000,true);
vector<bool>    visit(10000000, false);
vector<bool>    visitIdx(8,false);
int nSize, res = 0;
string num;

void dfs(string s) {
    if (s != "") {
        int curNum = stoi(s);
        if (visit[curNum] == false) { // 아직 접근 안한값이면
            visit[curNum] = true;
            if (prime[curNum] == true) // 소수이면
                res++;
        }
    }
    for (int i = 0; i < nSize; i++) {
        if (visitIdx[i] == false) {
            visitIdx[i] = true;
            dfs(s + num[i]);
            visitIdx[i] = false;
        }
    }
}

int solution(string numbers) {
    nSize = numbers.size();
    num = numbers;
    
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i < 10000000; i++) // 에라토스테네스의 체
        if (prime[i])
            for (int j = i * i; j < 10000000; j += i)
                prime[j] = false;
    dfs("");
    return res;
}