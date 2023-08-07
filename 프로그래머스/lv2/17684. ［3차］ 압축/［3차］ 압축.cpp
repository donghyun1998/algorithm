// #include <string>
// #include <vector>
// #include <unordered_map>
// #include <iostream>

// using namespace std;

// unordered_map<string, int>    m;
// vector<int> dict;
// string s;
// int mSize;

// void    initMap() {
//     string str = "A";
//     for (int i = 1; i <= 26; i++, str[0]++) {
//         m[str] = i;
//     }
// }
// int    getSizeAddString(string s) {
//     int curSize = 2;
//     string addString;
//     while (curSize <= s.size()) {
//         if (m.find(s.substr(0, curSize)) == m.end()) {// 없으면
//             addString = s.substr(0, curSize);
//             break ;
//         }
//         curSize++;
//     }
//     if (curSize == 2) { // 이러면 두글자짜리 dict에 추가해줘야함
//         m[s.substr(0, 2)] = ++mSize;
//         dict.push_back(m[s.substr(0, 1)]);
//         return 1;
//     }
//     else { // addString map에 추가해줌
//         m[addString] = ++mSize;
//         dict.push_back(m[s.substr(0, curSize)]);
//     }
//     return curSize;
// }
// vector<int> solution(string msg) {
//     s = msg;
//     mSize = 26;
    
//     initMap();
//     int i = 0;
//     while (i < s.size())
//         i += getSizeAddString(s.substr(i)); // 현재 인덱스부터 남은 string 인자로넣어줌
//     return dict;
// }

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
    for (int i = 1; i <= 26; i++) { // 수정: 문자열 생성 방식 변경
        m[str] = i;
        str[0] = 'A' + i; // 수정: 다음 알파벳으로 변경
    }
}

int getSizeAddString(string s) {
    int curSize = 1;
    string addString;
    while (curSize <= s.size()) {
        if (m.find(s.substr(0, curSize)) == m.end()) {
            addString = s.substr(0, curSize);
            break;
        }
        curSize++;
    }
    if (curSize == 1) {
        m[s.substr(0, 1)] = ++mSize;
        return 1;
    } 
    else
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
    return dict; // 수정: 압축 결과 반환
}