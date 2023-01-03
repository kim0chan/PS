#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	queue<int> qu;
	int N, val;

	cin >> N;

	for (int i = 0; i < N; i++) {
		qu.push(i + 1);
	}

	while (1) {
		val = qu.front();
		qu.pop();
		if (qu.empty()) { break; }
		val = qu.front();
		qu.pop();
		qu.push(val);
	}

	cout << val << '\n';

	return 0;
}