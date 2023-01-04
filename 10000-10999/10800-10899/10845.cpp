#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	queue<int> qu;
	string input;
	int N;

	cin >> N;
	while (N--) {
		cin >> input;
		if (input == "push") {
			int arg;
			cin >> arg;
			qu.push(arg);
		}
		else if (input == "pop") {
			if (qu.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << qu.front() << '\n';
				qu.pop();
			}
		}
		else if (input == "size") {
			cout << qu.size() << '\n';
		}
		else if (input == "empty") {
			cout << qu.empty() << '\n';
		}
		else if (input == "front") {
			if (qu.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << qu.front() << '\n';
			}
		}
		else if (input == "back") {
			if (qu.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << qu.back() << '\n';
			}
		}
		else {
			cout << "error" << '\n';
		}
	}
	return 0;
}