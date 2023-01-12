#include <bits/stdc++.h>

using namespace std;

char sign[10];
int vis[10];
int ans[11];
bool solved_a, solved_b;
int k;

void solve_a(int l) {
	if (solved_a) return;
	if (l == k + 1) {
		for (int i = 0; i < k + 1; i++) {
			cout << ans[i];
		}
		cout << '\n';
		solved_a = true;
	}
	if (l == 0) {
		for (int i = 0; i <= 9; i++) {
			ans[l] = i;
			vis[i] = 1;
			solve_a(l + 1);
			vis[i] = 0;
		}
	}
	else {
		if (sign[l - 1] == '<') {
			for (int i = 0; i <= 9; i++) {
				if(!vis[i] && ans[l - 1] < i) {
					ans[l] = i;
					vis[i] = 1;
					solve_a(l + 1);
					vis[i] = 0;
				}
			}
		}
		else if (sign[l - 1] == '>') {
			for (int i = 0; i <= 9; i++) {
				if (!vis[i] && ans[l - 1] > i) {
					ans[l] = i;
					vis[i] = 1;
					solve_a(l + 1);
					vis[i] = 0;
				}
			}
		}
		else {
			;
		}
	}
}

void solve_b(int l) {
	if (solved_b) return;
	if (l == k + 1) {
		for (int i = 0; i < k + 1; i++) {
			cout << ans[i];
		}
		cout << '\n';
		solved_b = true;
	}
	if (l == 0) {
		for (int i = 9; i >= 0; i--) {
			ans[l] = i;
			vis[i] = 1;
			solve_b(l + 1);
			vis[i] = 0;
		}
	}
	else {
		if (sign[l - 1] == '<') {
			for (int i = 9; i >= 0; i--) {
				if (!vis[i] && ans[l - 1] < i) {
					ans[l] = i;
					vis[i] = 1;
					solve_b(l + 1);
					vis[i] = 0;
				}
			}
		}
		else if (sign[l - 1] == '>') {
			for (int i = 9; i >= 0; i--) {
				if (!vis[i] && ans[l - 1] > i) {
					ans[l] = i;
					vis[i] = 1;
					solve_b(l + 1);
					vis[i] = 0;
				}
			}
		}
		else {
			;
		}
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> sign[i];
	}

	solve_b(0);
	solve_a(0);
	cout << '\n';
}