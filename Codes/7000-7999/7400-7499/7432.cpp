#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 25000;
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

void dfs(int cur, int depth) {
	for (auto next : nxt[cur]) {
		string lev;
		for (int i = 0; i < depth; i++) {
			lev += " ";
		}
		cout << lev << next.first << '\n';
		dfs(next.second, depth + 1);
	}
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<string> v;
		string input;
		cin >> input;
		
		string temp = "";
		for (int j = 0; j < input.length(); j++) {
			if (input[j] == '\\') {
				v.push_back(temp);
				temp = "";
				continue;

			}
			temp += input[j];
			if (j == input.length() - 1) {
				v.push_back(temp);
			}
		}

		insert(v);
	}

	dfs(1, 0);
}