#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N, input;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	priority_queue<int> qu;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input) {
			qu.push(input);
		}
		else {
			if (qu.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << qu.top() << '\n';
				qu.pop();
			}
		}
	}

	return 0;
}