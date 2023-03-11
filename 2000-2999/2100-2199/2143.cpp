#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll T;
int n, m;
ll A[1001];
ll B[1001];
vector<ll> AA;
vector<ll> BB;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> T;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		A[i] += A[i - 1];
	}

	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
		B[i] += B[i - 1];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			AA.push_back(A[i] - A[j]);
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < i; j++) {
			BB.push_back(B[i] - B[j]);
		}
	}

	sort(AA.begin(), AA.end());
	sort(BB.begin(), BB.end());

	ll solve = 0;
	for (int i = 0; i < (int)AA.size(); i++) {
		auto ub = upper_bound(BB.begin(), BB.end(), T - AA[i]);
		auto lb = lower_bound(BB.begin(), BB.end(), T - AA[i]);

		solve += (ub - lb);
	}

	cout << solve << '\n';
}