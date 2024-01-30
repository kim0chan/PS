#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int X;
	cin >> X;

	int phase = 1;
	int subphase = 1;
	int order = -1;
	for (int i = 1; i < X; i++) {
		if (phase == subphase) {
			phase++;
			subphase = 1;
			order *= -1;
		}
		else {
			subphase++;
		}
	}
	if (order > 0) {
		cout << subphase << '/' << phase - subphase + 1 << '\n';
	}
	else {
		cout << phase - subphase + 1 << '/' << subphase << '\n';
	}
}