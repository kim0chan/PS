#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	string temp;
	getline(cin, temp);
	while (N--) {
		string input;
		getline(cin, input);
		input[0] = toupper(input[0]);

		cout << input << '\n';
	}
}