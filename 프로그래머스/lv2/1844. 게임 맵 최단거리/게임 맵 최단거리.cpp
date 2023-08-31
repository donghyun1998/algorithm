#include<vector>
#include <queue>
#include <cstdlib>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int> > maps)
{
    int visit[100][100];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            visit[i][j] = 0;
    queue<pair<int, int> > q;
    int row = maps.size();
    int col = maps[0].size();
    
    visit[0][0] = 1;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        if (curX == row - 1 && curY == col - 1)
            return (visit[curX][curY]);
        
        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            
            if (nextX >= 0 && nextX < row && nextY >= 0 && nextY < col 
                && maps[nextX][nextY] == 1 && visit[nextX][nextY] == 0) {
                q.push(make_pair(nextX, nextY));
                visit[nextX][nextY] = visit[curX][curY] + 1;
            }
        }
    }
    return (-1);
}