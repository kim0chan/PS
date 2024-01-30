#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
const int MX = 10000 * 500 + 1;
int nxt[MX][26];
int unused = 2;
int N, M;

int c2i(char c) {
	return c - 'A';
}

void insert(string& s) {
	int cur = ROOT;
	for (char c : s) {
		if (nxt[cur][c2i(c)] == -1) {
			nxt[cur][c2i(c)] = unused++;
		}
		cur = nxt[cur][c2i(c)];
	}
}

bool isPrefix(string& s) {
	int cur = ROOT;
	for (char c : s) {
		if (nxt[cur][c2i(c)] == -1) {
			return false;
		}
		cur = nxt[cur][c2i(c)];
	}
	return true;
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	cin >> N >> M;
	for (int i = 0; i < MX; i++) {
		fill(nxt[i], nxt[i] + 26, -1);
	}

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		insert(s);
	}

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (isPrefix(s))	ans++;
	}

	cout << ans << '\n';
}