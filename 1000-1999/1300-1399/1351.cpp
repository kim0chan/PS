#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll	long long

ll N, P, Q;
unordered_map<ll, ll> um;

ll solve(ll k) {
	if (k == 0) return 1;
	if (um.find(k) != um.end()) {
		return um[k];
	}
	
	ll a, b;
	a = solve(k / P);
	b = solve(k / Q);

	um[k] = a + b;
	return a + b;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	cin >> N >> P >> Q;
	cout << solve(N) << '\n';
}