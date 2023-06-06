#include <string>
#include <vector>

using namespace std;

int get_multi(vector<vector<int>> arr1, vector<vector<int>> arr2, int i, int j)
{
    int res = 0;
    for (int idx = 0; idx < arr1[0].size(); idx++) // 반대다 행렬의 곱이니까
        res += arr1[i][idx] * arr2[idx][j];
    return res;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size()));
    
    for (int i = 0; i < arr1.size(); i++)
        for (int j = 0; j < arr2[0].size(); j++)
            answer[i][j] = get_multi(arr1, arr2, i, j);
    return answer;
}

/*
0,0 0,1     0,0 0,1
1,0 1,1     1,0 1,1
2,0 2,1    

(0,0)*(0,0) + (0,1)*(1,0), (0,0)*(0,1) + (0,1)*(1,1)

1 4   3 2
3 2   3 4
4 1
    
1 * 3 + 4 * 3 , 1 * 2 + 4 * 4
3 * 3 + 2 * 3 , 3 * 2 + 2 * 4
4 * 3 + 1 * 3 , 4 * 2 + 1 * 4
*/