#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

/*
1
1 1
1 1 1
1 1 1 1
1 1 1 1 1
*/
vector<int> getAnswer(const vector<vector<int> > arr, int n) {
    vector<int> v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            v.push_back(arr[i][j]);
    return v;
}

vector<int> solution(int n) {
    vector<vector<int> > arr(n, vector<int>(n, 0));

    int i = 0, x = 0, y = 0;
    int command = 1;
    while (arr[x][y] == 0) { // 넣을 자리에 이미 들어가 있으면 종료
        arr[x][y] = ++i;
        if (command == 1 && (x >= n - 1 || arr[x + 1][y] != 0))
            command++;
        else if (command == 2 && (y >= n - 1 || arr[x][y + 1] != 0))
            command++;
        else if (command == 3 && arr[x - 1][y - 1] != 0) // 0 아니면 이미 채워진 거 => 내려가면 됨 cmd 1
            command = 1;

        if (command == 1)
            x++;
        else if (command == 2)
            y++;
        else if (command == 3) {
            x--; y--;
		}
    }
    return getAnswer(arr, n);
}