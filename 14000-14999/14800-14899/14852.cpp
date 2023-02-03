#include <bits/stdc++.h>

using namespace std;

int a[10], b[10];
bool reversed;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	for (int i = 1; i < 10; i++) {
		int input;
		cin >> input;

		a[i] = a[i - 1] + input;
	}

	for (int i = 1; i < 10; i++) {
		int input;
		cin >> input;

		if (a[i] > b[i-1]) { reversed = true; break; }
		b[i] = b[i - 1] + input;
	}


	if (reversed) {
		cout << "Yes\n";
		return 0;
	}

	cout << "No\n";
}