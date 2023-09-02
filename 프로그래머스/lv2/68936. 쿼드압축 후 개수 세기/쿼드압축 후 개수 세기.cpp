#include <string>
#include <vector>

using namespace std;
vector<vector<int>> board;
int cnt0 = 0, cnt1 = 0;

bool checkSameArea(int startX, int startY, int len) {
    int areaNum = board[startX][startY];
    
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            if (areaNum != board[startX + i][startY + j])
                return false;
    if (board[startX][startY] == 1)
        cnt1++;
    else
        cnt0++;
    return true;
}

void recur (int startX, int startY, int len) {
    if (len == 1) {
        if (board[startX][startY] == 1)
            cnt1++;
        else
            cnt0++;
        return ;
    }
    if (checkSameArea(startX, startY, len) == false) { // 쿼드압축 불가능
        int newLen = len / 2;
        recur(startX, startY, newLen);
        recur(startX + newLen, startY, newLen);
        recur(startX, startY + newLen, newLen);
        recur(startX + newLen, startY + newLen, newLen);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    board = arr;
    vector<int> answer;
    
    recur(0, 0, arr.size());
    answer.push_back(cnt0);
    answer.push_back(cnt1);
    return answer;
}