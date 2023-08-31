#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
using namespace std;

int N;

int getDiffWithCutWire(vector<vector<int> > wires, int cutIdx) { // ref로 받지 않았다 복사한 wires임
    unordered_set<int> groupA;
    groupA.insert(wires[cutIdx][0]);
    unordered_set<int> groupB;
    groupB.insert(wires[cutIdx][1]);
    
    wires.erase(wires.begin() + cutIdx);
    
    while (groupA.size() + groupB.size() < N) {
        for (int i = 0; i < wires.size(); i++){
            int tower1 = wires[i][0];
            int tower2 = wires[i][1];
            if (groupA.find(tower1) != groupA.end())
                groupA.insert(tower2);
            else if (groupA.find(tower2) != groupA.end())
                groupA.insert(tower1);
            else if (groupB.find(tower1) != groupB.end())
                groupB.insert(tower2);
            else if (groupB.find(tower2) != groupB.end())
                groupB.insert(tower1);
        }
    }
    return abs((int)groupA.size() - (int)groupB.size());
}

int solution(int n, vector<vector<int>> wires) {
    N = n;
    int res = 2147483647;
    
    for (int i = 0; i < wires.size(); i++)
        res = min(res, getDiffWithCutWire(wires, i));
    
    return res;
}