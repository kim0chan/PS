#include <bits/stdc++.h>
using namespace std;

#define ll	long long

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	ll solve = 0;
	int N;
	cin >> N;

	vector<int> v(N);
	vector<bool> check(100001);
	
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	check[v[0]] = true;
	int en = 0;
	for (int st = 0; st < N; st++) {
		while (en < N - 1 && !check[v[en + 1]]) {
			check[v[++en]] = 1;
		}
		solve += (en - st + 1);
		check[v[st]] = false;
	}
	cout << solve << '\n';
}