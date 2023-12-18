// 카드 놓기
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n + 1, 0);
	deque<int> dq;
	for (int i = n; i > 0; i--) // 역순으로
		cin >> v[i];

	for (int i = 1; i <= n; i++)
	{
		if (v[i] == 1) {
			dq.push_front(i);
		}
		else if (v[i] == 2) {
			int tmp = dq.front();
			dq.pop_front();
			dq.push_front(i);
			dq.push_front(tmp);
		}
		else if (v[i] == 3) {
			dq.push_back(i);
		}
	}
	for (int i = 0; i < dq.size(); i++)
		cout << dq[i] << ' ';
	return 0;
}
