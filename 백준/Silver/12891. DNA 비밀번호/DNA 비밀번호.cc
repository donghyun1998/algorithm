// DNA 비밀번호

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
vector<int> acgt(4, 0), cur_acgt(4, 0);

void addChar(char obj) {
	switch (obj) {
		case 'A':
			cur_acgt[0] += 1;
			break ;
		case 'C':
			cur_acgt[1] += 1;
			break ;
		case 'G':
			cur_acgt[2] += 1;
			break ;
		case 'T':
			cur_acgt[3] += 1;
			break ;
	}
}

void deleteChar(char obj) {
	switch (obj) {
		case 'A':
			cur_acgt[0] -= 1;
			break ;
		case 'C':
			cur_acgt[1] -= 1;
			break ;
		case 'G':
			cur_acgt[2] -= 1;
			break ;
		case 'T':
			cur_acgt[3] -= 1;
			break ;
	}
}
bool isValid() {
	for (int i = 0; i < 4; i++)
		if (acgt[i] > cur_acgt[i])
			return false;
	return true;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int input_size, target_size, res = 0;
	string input;

	cin >> input_size >> target_size >> input;
	for (int i = 0; i < 4; i++)
		cin >> acgt[i];

	for (int i = 0; i < target_size; i++)
		addChar(input[i]);

	for (int i = 0; i + target_size <= input_size; i++) {
		if (isValid())
			res++;
		deleteChar(input[i]);
		if (i + target_size < input_size)
			addChar(input[i + target_size]);
	}
	cout << res;
}
