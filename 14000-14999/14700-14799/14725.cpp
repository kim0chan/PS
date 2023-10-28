#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 1000 * 15 + 5;
map<string, int> nxt[MX];
bool chk[MX];

void insert(vector<string>& v) {
	int cur = ROOT;
	for (string s : v) {
		if (!nxt[cur][s]) {
			nxt[cur][s] = unused++;
		}
		cur = nxt[cur][s];
	}
}

void dfs(int cur, int d) {
	for (auto next : nxt[cur]) {
		string lev;
		for (int i = 0; i < d; i++) {
			lev += "--";
		}
		cout << lev << next.first << '\n';
		dfs(next.second, d + 1);
	}
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int numString;
		cin >> numString;
		vector<string> v(numString);
		for (int j = 0; j < numString; j++)
			cin >> v[j];

		insert(v);
	}
	dfs(1, 0);
}