#include <bits/stdc++.h>

using namespace std;

int main() {
	string str;
	int len;

	cin >> str;
	for (char a = 'a'; a <= 'z'; a++) {
		int cnt = 0;
		for (auto c : str) {
			if (c == a) cnt++;
		}
		cout << cnt << ' ';
	}

	return 0;
}