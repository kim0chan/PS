#include <bits/stdc++.h>
using namespace std;

int N, ans;
int alphabet[26];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		int length = (int)input.length();
		int exp = length - 1;
		for (int j = 0; j < length; j++) {
			alphabet[input[j] - 'A'] += pow(10, exp);
			--exp;
		}
	}

	sort(alphabet, alphabet + 26, greater<>());

	int weight = 9;
	for (int i = 0; i < 26; i++) {
		if (!alphabet[i])	break;
		ans += alphabet[i] * weight;
		--weight;
	}

	cout << ans << '\n';
}