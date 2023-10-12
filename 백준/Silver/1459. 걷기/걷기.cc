#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace	std;

long long X, Y, line, cross, res = 0;

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin >> X >> Y >> line >> cross;
	if (line * 2 < cross)
		res = (X + Y) * line;
	else if (cross < line) { // 대각선이 더 빠를때
		int maxCross = min(X, Y);
		int remainDist = X - maxCross + Y - maxCross;
		if (remainDist % 2) { // 홀수이면
			res += line;
			remainDist--;
		}
		res += maxCross * cross + remainDist * cross;
	}
	else {
		int maxCross = min(X, Y);
		res = maxCross * cross + (X - maxCross) * line + (Y - maxCross) * line;
	}
	cout << res;
}
