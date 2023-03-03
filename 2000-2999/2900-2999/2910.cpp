#include <bits/stdc++.h>
using namespace std;

int N, C, input;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> C;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		cin >> input;
		bool dup = false;
		for (auto& a : v) {
			if (input == a.first) {
				dup = true;
				a.second++;
				break;
			}
		}
		if (!dup)		v.push_back({ input, 1 });
	}
	stable_sort(v.begin(), v.end(), compare);

	for (auto& a : v) {
		for (int i = 0; i < a.second; i++) {
			cout << a.first << ' ';
		}
	}
	cout << '\n';
}