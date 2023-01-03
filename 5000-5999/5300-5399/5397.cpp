#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		list<char> l;
		string str;
		auto cursor = l.begin();

		cin >> str;

		for (auto c : str) {
			if (c == '<') {
				if (cursor != l.begin()) {
					cursor--;
				}
			}
			else if (c == '>') {
				if (cursor != l.end()) {
					cursor++;
				}
			}
			else if (c == '-') {
				if (cursor != l.begin()) {
					cursor--;
					cursor = l.erase(cursor);
				}
			}
			else {
				l.insert(cursor, c);
			}
		}

		for (auto c : l) {
			cout << c;
		}
		cout << '\n';
	}

	return 0;
}