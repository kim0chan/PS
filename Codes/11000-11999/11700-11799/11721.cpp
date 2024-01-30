#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		cout << input[i];
		if ((i+1) % 10 == 0) {
			cout << '\n';
		}
	}
}