#include <bits/stdc++.h>

using namespace std;

int dr[55];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> dr[i];
	}
	sort(dr, dr + n);

	cout << dr[0] * dr[n - 1];
}