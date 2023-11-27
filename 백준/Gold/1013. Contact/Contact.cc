// Contact

#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


string solution(string input) {
	if (input[input.size() - 1] == '0') // 0으로 끝나는거 말이안됨
		return "NO";
	if (input[0] == '0' && input[1] == '0')
		return "NO";

// 1XXX
	for (int i = 0; i + 1 < input.size(); i++) {
		if (i != 0 && input[i] == '0' && input[i + 1] == '0') { // 0연속 찾았다!
			int j = 0;
			while (i + j + 1 < input.size() && input[i + j + 1] == '0') // 0 연속인 개수 찾음
				j++;
			while (i + j + 1 < input.size() && input[i + j + 1] == '1') // 1 연속인 개수 찾음
				j++;
			if (input[i + j] != '1') // 0011으로 끝나는 문자열
				return "NO";
			if (input[i - 1] == 'x')
				return "NO";
			if (input[i + j - 1] == '0') { // 끝에 붙는 1 하나짜리
				input[i - 1] = 'x';
				for (int k = 0; k <= j; k++)
					input[i + k] = 'x';
			} else { // 끝에 붙는 1 두개짜리
				input[i - 1] = 'X';
				for (int k = 0; k <= j; k++)
					input[i + k] = 'X';
			}
		}
	}
	// cout << input << endl;
	for (int i = 0; i + 1 < input.size(); i++) {
		if (input[i] == '0' && input[i + 1] == '1') {
			input[i] = 'X';
			input[i + 1] = 'X';
		}
	}
	// cout << input << endl;
	for (int i = 0; i < input.size(); i++)
		if (input[i] != 'X' && input[i] != 'x')
			return "NO";
	return "YES";
}
// (100+1+ | 01)+
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int n;
	cin >> n;
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		cout << solution(input) << '\n';
	}
}
