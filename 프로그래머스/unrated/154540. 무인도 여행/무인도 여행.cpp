#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> res;
int cnt = 0;
vector<string> map;
int xLen, yLen;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void    dfs(int x, int y) {
    cnt += map[x][y] - '0';
    map[x][y] = 'X';
    for (int i = 0; i < 4; i++) {
        if (x + dx[i] >= 0 && x + dx[i] < xLen 
            && y + dy[i] >= 0 && y + dy[i] < yLen 
            && map[x + dx[i]][y + dy[i]] != 'X') {
                dfs(x + dx[i], y + dy[i]);
        }
    }
}

vector<int> solution(vector<string> maps) {
    map = maps;
    vector<int> answer;
    xLen = map.size();
    yLen = map[0].size();
    for (int i = 0; i < xLen; i++) {
        for (int j = 0; j < yLen; j++) {
            if (map[i][j] != 'X') {
                dfs(i, j);
                answer.push_back(cnt);
                cnt = 0;
            }
        }
    }
    sort(answer.begin(), answer.end());
    if (answer.size() == 0)
        answer.push_back(-1);
    return answer;
}