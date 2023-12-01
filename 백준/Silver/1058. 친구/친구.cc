#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
	int n, res = 0;
	cin >> n;
	vector<string> board(n);
	for (int i = 0; i < n; i++)
		cin >> board[i];
	unordered_map<int, vector<int> > buddy_m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'Y') {
				buddy_m[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		unordered_set<int> buddy_s(buddy_m[i].begin(), buddy_m[i].end());
		for (auto f : buddy_m[i]) {
			for (auto ff : buddy_m[f]) {
				if (ff != i) {
					buddy_s.insert(ff);
				}
			}
		}
		res = max(res, static_cast<int>(buddy_s.size()));
	}
	cout << res;

}
