#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	int N, num;
	string input;
	queue<int> qq;
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;

		if (input == "push") {
			cin >> num;
			qq.push(num);
		}
		else if (input == "pop") {
			if (!qq.empty()) {
				cout << qq.front() << '\n';
				qq.pop();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (input == "size") {
			cout << qq.size() << '\n';
		}
		else if (input == "empty") {
			cout << qq.empty() << '\n';
		}
		else if (input == "front") {
			if (!qq.empty()) {
				cout << qq.front() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (input == "back") {
			if (!qq.empty()) {
				cout << qq.back() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else { fprintf(stdout, "An error occurred.\n"); return -1; }
	}

	return 0;
}