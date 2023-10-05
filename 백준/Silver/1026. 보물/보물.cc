#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <cstring>
#include <utility>

using namespace	std;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int num, res = 0;
	cin >> num;
	vector<int> A, B;
	for (int i = 0; i < num; i++) {
		int input;
		cin >> input;
		A.push_back(input);
	}
	for (int i = 0; i < num; i++) {
		int input;
		cin >> input;
		B.push_back(input);
	}
	sort(A.begin(), A.end(), greater<int>()); // 내림차순으로 정렬해준다.
	sort(B.begin(), B.end());
	for (int i = 0; i < num; i++)
		res += A[i] * B[i];
	cout << res;
}
