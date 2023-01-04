#include <bits/stdc++.h>

using namespace std;

int N[20000005];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n, m;
	cin >> n;
	while (n--) {
		int in;
		cin >> in;
		N[in + 10000000] += 1;
	}
	cin >> m;
	while (m--) {
		int in;
		cin >> in;
		cout << N[in + 10000000] << ' ';
	}

}