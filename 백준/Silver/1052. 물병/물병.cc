#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, k, res = 0;
	cin >> n >> k;

	while (true) {
		int tmp = n, cnt = 0;
		while (tmp > 0) {
			if (tmp % 2 == 0)
				tmp /= 2;
			else {
				tmp /= 2;
				cnt++;
			}
		}
		if (k >= cnt)
			break ;
		n++;
		res++;
	}
	cout << res;
}
