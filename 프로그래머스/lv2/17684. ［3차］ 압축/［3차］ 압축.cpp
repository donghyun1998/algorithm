#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> m;
string s;
int mSize;

void initMap() {
    string str = "A";
    for (int i = 1; i <= 26; i++) {
        m[str] = i;
        str[0] = 'A' + i;
    }
}

int getSizeAddString(string s) { // 더할 문자열의 길이를 리턴
    int curSize = 1;
    string addString;
    while (curSize <= s.size()) {
        if (m.find(s.substr(0, curSize)) == m.end()) { // 없는게 나오면 
            addString = s.substr(0, curSize);
            break;
        }
        curSize++;
    }
    m[addString] = ++mSize;
    return curSize - 1;
}
vector<int> solution(string msg) {
    s = msg;
    mSize = 26;

    initMap();
    vector<int> dict;
    int i = 0;
    while (i < s.size()) {
        int size = getSizeAddString(s.substr(i));
        dict.push_back(m[s.substr(i, size)]);
        i += size;
    }
    return dict;
}