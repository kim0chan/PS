#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int sum = 0;

	for (int i = 0; i < 5; i++) {
		int input;
		cin >> input;

		if (input < 40) { input = 40; }
		sum += input;
	}

	cout << sum / 5 << '\n';
}