#include <bits/stdc++.h>
#define BIAS	65;
using namespace std;

int cnt[26];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		cnt[toupper(input[i]) - 65]++;
	}

	int count = 0;
	int max = 0;
	int idx;
	for (int i = 0; i < 26; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
			idx = i;
			count = 1;
		}
		else if (max == cnt[i]) {
			count++;
		}
	}

	if (count == 1) {
		cout << (char)(idx + 65) << '\n';
	}
	else {
		cout << '?' << '\n';
	}
}