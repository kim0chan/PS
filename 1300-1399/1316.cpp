#include <bits/stdc++.h>

using namespace std;

int isGroupWord(string str) {
	int ab[27] = { 0, };

	for (int i = 0; i < str.size(); i++) {
		char c;
		c = str[i];
		if (ab[c - 97]) {
			if (str[i - 1] == c) {
				continue;
			}
			return 0;
		}

		ab[c - 97] = 1;
	}
	return 1;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	int count = 0;
	cin >> N;

	while (N--) {
		string input;
		cin >> input;
		if (isGroupWord(input)) {
			count++;
		}
	}
	cout << count;
}