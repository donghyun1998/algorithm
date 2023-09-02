// 쿼드트리

#include <iostream>
using namespace	std;

void	func(string board[128], int n, int x, int y)
{
	int	cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[x][y] == board[x + i][y + j]) // 인자 전부 검사
				cnt++;
	if (cnt == n * n) // 전부 같으면
	{
		cout << board[x][y];
		return ;
	}
	cout << '(';
	int	div_2 = n / 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			func(board,div_2, x + div_2 * i, y + div_2 * j);
	cout << ')';
}

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int	n;

	cin >> n;
	string	board[64];
	for (int i = 0; i < n; i++)
		cin >> board[i];
	func(board, n, 0, 0);
}

