#include <iostream>

using namespace std;

long long getFactorial(long long n) {
	long long res = 0;
	while (n > 0) {
		res += n--;
	}
	return res;
}

int main() {
	long long sum, len;
	cin >> sum >> len;
	while (len <= 100) {
		long long fact = getFactorial(len - 1);
		if (sum - fact < 0) // 이미 망함
			break ;
		if ((sum - fact) % len == 0) {
			int start = (sum - fact) / len;
			for (int i = 0; i < len; i++)
				cout << start + i << ' ';
			return 0;
		}
		len++;
	}
	cout << -1;
}
