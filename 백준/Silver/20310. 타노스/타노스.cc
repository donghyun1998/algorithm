#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace	std;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin >> s;
	int half_zero_cnt, half_one_cnt = 0;

	for (int i = 0; i < s.size(); i++)
		if (s[i] == '1')
			half_one_cnt++;
	half_zero_cnt = s.size() - half_one_cnt;
	half_one_cnt /= 2;
	half_zero_cnt /= 2;

	for (int i = 0; half_one_cnt > 0; i++) {
		if (s[i] == '1') {
			half_one_cnt--;
			s[i] = '2';
		}
	}
	for (int i = s.size() - 1; half_zero_cnt > 0; i--) {
		if (s[i] == '0') {
			half_zero_cnt--;
			s[i] = '2';
		}
	}
	string res(s.size() / 2, 0);
	int res_cnt = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] != '2')
			res[res_cnt++] = s[i];
	cout << res;
}