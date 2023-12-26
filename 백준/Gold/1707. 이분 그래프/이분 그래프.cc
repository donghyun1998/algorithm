// 이분 그래프
#include <iostream>
#include <vector>
using namespace std;
int k, node_n, pipe_n;
vector<vector<int> > v;
vector<int> vis;
bool isBipartite = true;

void dfs(int node, int color) {
	vis[node] = color;

	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];

		if (vis[next] == 0) {
			int next_color = 1;
			if (color == 1)
				next_color = 2;
			dfs(next, next_color);
		} else if (vis[next] == color) {
			isBipartite = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	while (k--) {
		cin >> node_n >> pipe_n;
		vis = vector<int>(node_n + 1, 0);
		v = vector<vector<int> >(node_n + 1);
		for (int i = 0; i < pipe_n; i++) {
			int input_a, input_b;
			cin >> input_a >> input_b;
			v[input_a].push_back(input_b);
			v[input_b].push_back(input_a);
		}
		isBipartite = true;
		for (int i = 1; i <= node_n; i++) {
			if (vis[i] || isBipartite == false)
				continue;
			dfs(i, 1);
		}
		if (isBipartite)
			cout << "YES\n";
		else
			cout << "NO\n";

	}
}
