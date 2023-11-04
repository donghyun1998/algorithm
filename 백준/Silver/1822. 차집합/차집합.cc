#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace	std;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int a_size, b_size;
	cin >> a_size >> b_size;
	vector<int> A(a_size, 0);
	vector<int> B(b_size, 0);
	vector<int> res;
	for (int i = 0; i < a_size; i++)
		cin >> A[i];
	for (int i = 0; i < b_size; i++)
		cin >> B[i];
	sort(B.begin(), B.end());
	for (int i = 0; i < a_size; i++)
		if (binary_search(B.begin(), B.end(), A[i]) == false)
			res.push_back(A[i]);
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << ' ';
}
