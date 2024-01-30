#include <bits/stdc++.h>

using namespace std;

vector<int> vec;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int count = 0;
	int solve = 0;
	int N;
	cin >> N;

	while (N--) {
		int input;
		cin >> input;

		vec.push_back(input);
	}
	sort(vec.begin(), vec.end());

	for (auto c : vec) {
		count = count + c;
		solve = solve + count;
	}

	cout << solve;
}