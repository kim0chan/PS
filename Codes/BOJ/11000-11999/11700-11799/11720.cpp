#include <bits/stdc++.h>
using namespace std;

int main() {
	int sum = 0;
	int N;
	cin >> N;

	while (N--) {
		int input;
		scanf("%1d", &input);

		sum += input;
	}

	cout << sum << '\n';
}