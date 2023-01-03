#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	string input;
	cin >> input;
	N--;

	while (N--) {
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (input[i] != str[i]) input[i] = '?';
		}
	}

	cout << input << '\n';
}