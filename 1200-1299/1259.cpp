#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	while (1) {
		int ya = 1;
		string input;
		cin >> input;
		if (input == "0") { break; }
		
		for (int i = 0; 2 * i <= input.size(); i++) {
			if (input[i] != input[input.size() - 1 - i]) {
				cout << "no\n";
				ya = 0;
				break;
			}
		}

		if (ya) {
			cout << "yes\n";
		}
	}

}