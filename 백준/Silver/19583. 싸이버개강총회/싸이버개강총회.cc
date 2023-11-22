#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int timeToInt(string& input) {
	int res = 0;
	res += (input[0] - '0') * 600;
	res += (input[1] - '0') * 60;
	res += (input[3] - '0') * 10;
	res += (input[4] - '0');
	return res;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string input;
	vector<int> v(3, 0); // [1] 시작 [2] 끝 [3] 방송끝
	int res = 0;
	for (int i = 0; i < 3; i++) {
		cin >> input;
		v[i] = timeToInt(input);
	}
	unordered_set<string> s;
	string time, nickname;
	while (getline(cin, time, ' ') && getline(cin, nickname)) {
		// cout << time << ' ' << nickname << endl;
		if (timeToInt(time) <= v[0]) { // 시작 전이면
			s.insert(nickname);
		} else if (timeToInt(time) >= v[1] && timeToInt(time) <= v[2]) {
			if (s.find(nickname) != s.end()) {
				s.erase(nickname);
				res++;
			}
		}
		// cout << res;
	}
	cout << res;
}
