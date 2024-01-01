// 계란으로 계란치기
#include <iostream>
#include <vector>
using namespace std;
int n;
struct Egg {
	int hp;
	int power;
};
vector<Egg> v;
int res;

void recur(int depth) {
	if (depth == n) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (v[i].hp <= 0)
				cnt++;
		res = max(res, cnt);
		return ;
	}
	if (v[depth].hp <= 0) {
		recur(depth + 1);
		return ;
	}
	bool is_hit = false;
	for (int i = 0; i < n; i++) {
		if (v[i].hp <= 0 || i == depth)
			continue;
		is_hit = true;
		v[depth].hp -= v[i].power;
		v[i].hp -= v[depth].power;
		recur(depth + 1);
		v[depth].hp += v[i].power;
		v[i].hp += v[depth].power;
	}
	if (!is_hit)
		recur(depth + 1);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		Egg input;
		cin >> input.hp >> input.power;
		v.push_back(input);
	}
	recur(0);
	cout << res;
}
