#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int N, M, ans;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	unordered_set<string> us;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		us.insert(input);
	}

	for (int i = 0; i < M; i++) {
		string input;
		cin >> input;

		if (us.find(input) != us.end()) {
			ans++;
		}
	}

	cout << ans << '\n';
}