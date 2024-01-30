#include <bits/stdc++.h>

using namespace std;

int main() {
	string str;
	list<char> l;

	cin >> str;
	for (auto c : str) {
		l.push_back(c);
	}
	auto cursor = l.end();
	int M;
	char sel;

	cin >> M;
	while (M--) {
		cin >> sel;

		if (sel == 'L') {
			if (cursor != l.begin()) {
				cursor--;
			}
		}
		else if (sel == 'D') {
			if (cursor != l.end()) {
				cursor++;
			}
		}
		else if (sel == 'B') {
			if (cursor != l.begin()) {
				cursor--;
				cursor = l.erase(cursor);
			}
		}
		else {
			char c;
			cin >> c;
			l.insert(cursor, c);
		}
	}

	for (auto c : l) {
		cout << c;
	}

}