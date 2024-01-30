#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int t;
	cin >> t;

	while (t--) {
		int score = 0;
		int accumulative = 1;
		string input;
		cin >> input;

		for (int i = 0; i < input.size(); i++) {
			if (input[i] == 'O') {
				score += accumulative;
				accumulative++;
			}
			else {
				accumulative = 1;
			}
		}

		cout << score << '\n';
	}


}