#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int min_x = wallpaper.size(), min_y = wallpaper[0].size(), max_x = 0, max_y = 0;
    
    for (int i = 0; i < wallpaper.size(); i++)
    {
        for (int j = 0; j < wallpaper[0].size(); j++)
        {
            if (wallpaper[i][j] == '#')
            {
                min_x = min(min_x, i);
                min_y = min(min_y, j);
                max_x = max(max_x, i);
                max_y = max(max_y, j);
            }
        }
    }
    answer.push_back(min_x);
    answer.push_back(min_y);
    answer.push_back(max_x + 1); // 감싸야 하니까 한칸씩 더 가야함
    answer.push_back(max_y + 1);
    return answer;
}