#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	int x = 0;
	cin >> N;
	
	while (N--) {
		for (int i = 0; i < x; i++) {
			cout << ' ';
		}
		for (int i = 0; i <= N; i++) {
			cout << '*';
		}
		cout << '\n';
		x++;
	}
}