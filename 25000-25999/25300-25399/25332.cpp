#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll ans = 0;
	int N;
	cin >> N;
	vector<ll> A(N + 1);
	vector<ll> B(N + 1);
	vector<ll> P(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> B[i];
	}
	for (int i = 1; i <= N; i++) {
		P[i] = P[i - 1] + B[i] - A[i];
	}

	unordered_map<ll, ll> um;
	for (int i = 1; i <= N; i++) {
		if (P[i] == 0)	ans++;
		ans += um[P[i]]++;
	}
	cout << ans << '\n';
}