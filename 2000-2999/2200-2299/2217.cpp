#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	vector<int> v;

	int N;
	cin >> N;

	for(int i = 0; i < N; i++) {
		int input;
		cin >> input;

		v.push_back(input);
	}

	sort(v.rbegin(), v.rend());

	int max = 0;
	int weight = 0;
	for (int i = 0; i < N; i++) {
		weight = v[i] * (i + 1);
		max = max > weight ? max : weight;
	}

	cout << max << '\n';
}