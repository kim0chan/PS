#include <bits/stdc++.h>
using namespace std;

int L, C;
bool visited[26];
char alphabet[26];
char ans[16];

// a-0, e-4, i-8, o-14, u-20;

void solve(int k) {
	if (k == L) {
		bool valid = false;
		int v_count = 0, c_count = 0;
		for (int i = 0; i < 26; i++) {
			if (visited[i]) {
				if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20)	v_count++;
				else	c_count++;
			}
			if (v_count > 0 && c_count > 1) {
				valid = true;
				break;
			}
		}
		if (!valid)	return;
		for (int i = 0; i < L; i++) {
			cout << ans[i];
		}
		cout << '\n';
		return;
	}
	//cout << "solve with [" << k << "]\n";
	for (int i = 0; i < C; i++) {
		if (k == 0 || ans[k - 1] < alphabet[i]) {
			visited[alphabet[i] - 'a'] = true;
			ans[k] = alphabet[i];
			solve(k + 1);
			visited[alphabet[i] - 'a'] = false;
		}
	}

}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> alphabet[i];
	}

	sort(alphabet, alphabet + C);
	solve(0);
}