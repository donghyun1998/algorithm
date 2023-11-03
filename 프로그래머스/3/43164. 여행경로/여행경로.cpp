#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
vector<string> answer;
unordered_map<string, int> m; // 도시별 티켓의 인덱스
vector<vector<string>> tickets;
vector<bool> visit(10001, false);
int ticket_size;
bool find_flag = false;

void dfs(int cnt, string city) {
    answer.push_back(city);
    if (cnt == ticket_size) {
        find_flag = true;
        return;
    }
    for (int i = m[city]; i < ticket_size && city == tickets[i][0]; i++) {
        if (visit[i] == true)
            continue ;
        visit[i] = true;
        dfs(cnt + 1, tickets[i][1]);
        if (find_flag)
            return;
        visit[i] = false;
    }
    answer.pop_back();
}

vector<string> solution(vector<vector<string>> ticket) {
    tickets = ticket;
    sort(tickets.begin(), tickets.end());
    ticket_size = tickets.size();
    for (int i = 0; i < ticket_size; i++) {
        if (m.find(tickets[i][0]) == m.end())
            m[tickets[i][0]] = i;
    }
    dfs(0, "ICN");
    return answer;
}
