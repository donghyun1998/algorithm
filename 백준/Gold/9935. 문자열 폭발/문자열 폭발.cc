#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string input, bomb;
	cin >> input >> bomb;
	int correctCnt = 0;
	stack<char>	a, b;

	for (int i = input.size() - 1; i >= 0; i--) // 문자열 뒤부터 스택에넣어줌
		a.push(input[i]);
	while (!a.empty()) {
		if (a.top() == bomb[correctCnt])
			correctCnt++;
		else {
			correctCnt = 0;
			if (a.top() == bomb[correctCnt])
				correctCnt++;
		}
		b.push(a.top());
		a.pop();
		if (correctCnt == bomb.size()) { // isbomb
			correctCnt = 0;
			for (int i = 0; i < bomb.size(); i++)
				b.pop();
			for (int i = 0; !b.empty() && i <= bomb.size() + 1; i++) {
				a.push(b.top());
				b.pop();
			}
		}
	}
	if (b.empty())
		cout << "FRULA";
	else {
		string s(b.size(), 0);
		for (int i = b.size() - 1; i >= 0; i--) {
			s[i] = b.top();
			b.pop();
		}
		cout << s;
	}
}
