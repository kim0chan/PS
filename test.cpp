#include <bits/stdc++.h>

using namespace std;

int N;
int entry[3] = { 1, 2, 3 };
bool solved = false;
string ans = "                                                                                                  ";

bool isValid(int l) {
	for (int i = 1; i <= l / 2; i++) {
		if (ans.substr(l - i, i) == ans.substr(l - 2 * i, i)) return false;
	}
	return true;
}

void solve(int k) {
	if (solved) { return; }
	if (k == N) {
		for (int i = 0; i < N; i++) {
			cout << ans[i];
		}
		cout << '\n';
		solved = true;
		return;
	}

	else {
		for (int i = 0; i < 3; i++) {
			ans[k] = entry[i];
			if (isValid(k + 1)) {
				solve(k + 1);ㄴ
			}
		}
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;

	solve(N);
}