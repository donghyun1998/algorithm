#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool    cmp(vector<int> a, vector<int> b) {
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> route) {
    sort(route.begin(), route.end(), cmp);
    // for (int i = 0; i < route.size(); i++) {
    //     for (int j = 0; j < route[0].size(); j++)
    //         cout << route[i][j] << ' ';
    //     cout << endl;
    // }
    int prev = route[0][1], res = 1;
    for (int i = 0; i < route.size(); i++) {
        if (prev >= route[i][0] && prev <= route[i][1]) // 경로 안에 카메라 있으면
            continue ;
        prev = route[i][1];
        // cout << prev << endl;
        res++;
    }
    return res;
}