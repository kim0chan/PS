#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int ans = 0;
	string input;

	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		ans *= 16;

		if (input[i] >= 'A' && input[i] <= 'F') {
			ans = ans + input[i] - 'A' + 10;
		}
		else {
			ans = ans + input[i] - '0';
		}
	}

	cout << ans << '\n';

}