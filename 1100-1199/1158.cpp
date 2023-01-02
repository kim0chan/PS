#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	list<int> l;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		l.push_back(i + 1);
	}

	auto t = l.begin();

	cout << '<';
	while (1) {
		for (int i = 0; i < K - 1; i++) {
			t++;
			if (t == l.end()) {
				t = l.begin();
			}
		}
		cout << *t;
		t = l.erase(t);
		if (t == l.end()) {
			t = l.begin();
		}

		if (l.empty()) {
			break;
		}
		else {
			cout << ", ";
		}
	}
	cout << '>';
}