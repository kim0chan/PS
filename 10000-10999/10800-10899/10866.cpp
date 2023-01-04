#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	int N, num;
	string input;
	
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	deque<int> dq;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (input == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (input == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (input == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (input == "size") {
			cout << dq.size() << '\n';
		}
		else if (input == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (input == "front") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.front() << '\n';
			}
		}
		else if (input == "back") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.back() << '\n';
			}
		}
		else {
			fprintf(stdout, "an error eccurred\n");
		}
	}

	return 0;
}