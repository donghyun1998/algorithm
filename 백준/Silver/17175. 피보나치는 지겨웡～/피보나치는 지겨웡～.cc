// 피보나치는 지겨웡~

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fibo(51, 0);
// vector<int> cnt(50, 0);

int main() {
	int n, res = 0;
	cin >> n;
	fibo[0] = 1;
	fibo[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2] + 1;
		fibo[i] %= 1000000007;
	}
	cout << fibo[n];
}
