#include <bits/stdc++.h>

using namespace std;

int N;
char entry[3] = { '1', '2', '3' };
bool solved = false;
string ans;

bool isValid(string tmp) {
	int len = tmp.length();
	for (int i = 1; i <= len / 2; i++) {
		if (tmp.substr(len - i, i) == tmp.substr(len - 2 * i, i)) return false;
	}
	return true;
}

void solve(string tmp, int k) {
	if (solved) { return; }
	if (!isValid(tmp)) { return; }
	if (k == N) {
		ans = tmp;
		solved = true;
	}

	for (int dir = 0; dir < 3; dir++) {
		solve(tmp + entry[dir], k + 1);
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	solve("", 0);
	cout << ans;
}