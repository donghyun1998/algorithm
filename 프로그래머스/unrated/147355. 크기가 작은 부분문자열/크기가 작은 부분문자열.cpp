#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0, plen = p.size();
    
    for (int i = 0; i < t.size() - plen + 1; i++)
    {
        if (t.substr(i, plen) <= p)
            answer++;
    }
    return answer;
}