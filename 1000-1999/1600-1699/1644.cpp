#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
	if (n == 1) { return 0; }
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) { return 0; }
	}
	return true;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	vector<int> v;
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		if (isPrime(i)) {
			v.push_back(i);
		}
	}
	
	int solve = 0;
	for (int st = 0; st < v.size(); st++) {
		int en = st;
		int sum = v[st];

		while (en < v.size() && sum < N) {
			en++;
			if(en != v.size()) { sum += v[en]; }
		}
		if (sum == N) { solve++; }
	}

	cout << solve << '\n';
}