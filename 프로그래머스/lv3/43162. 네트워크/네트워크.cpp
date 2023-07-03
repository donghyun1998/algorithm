#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v;
vector<vector<int>> com;
int         nn;

// 1 1 0
// 1 1 0
// 0 0 1
void    recur(int i) // 인덱스 하나씩 순회하면서
{
    for (int j = 0; j < nn; j++) {
        if (v[j] && com[i][j]) { // i, j 가 연결되어 있으면
            v[j] = 0;
            recur(j); // 또 j랑 연결된 애들 죄다 0 만들기
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int ans = 0;
    nn = n;
    com = computers;
    for (int i = 0; i < n; i++)
        v.push_back(1); // v에 1로 다 초기화해준다.
    for (int i = 0; i < n; i++) {
        if (v[i]) {
            ans++;
            recur(i);       
        }
        for (int j = 0; j < n; j++)
            cout << v[j] << ' ';
        cout << endl;
    }
    return ans;
}