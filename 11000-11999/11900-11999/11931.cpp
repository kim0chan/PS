#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), compare);

	for (auto a : v) {
		cout << a << '\n';
	}
}