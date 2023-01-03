#include <bits/stdc++.h>

using namespace std;

pair<int, int> s[100005];

bool compare( pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	int count = 1;
	int k = 0;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> s[i].first >> s[i].second;
	}

	sort(s, s + N, compare);

	for (int i = 1; i < N; i++) {
		if (s[i].first >= s[k].second) {
			count++;
			k = i;
		}
	}

	

	cout << count << '\n';
}