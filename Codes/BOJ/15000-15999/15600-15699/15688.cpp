#include <bits/stdc++.h>
using namespace std;

int chk[2000006];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	vector<int> v;

	int N;
	cin >> N;
	while (N--) {
		int input;
		cin >> input;
		chk[input + 1000000]++;
	}

	for (int i = 0; i < 2000001; i++) {
		if (chk[i]) {
			for (int j = 0; j < chk[i]; j++) {
				cout << i - 1000000 << '\n';
			}
		}
	}
}