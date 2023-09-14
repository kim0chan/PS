#include <bits/stdc++.h>
using namespace std;
#define X	first
#define Y	second

int N, K;
long long ans;
pair<int, int> jewel[300001];
multiset<int> bag;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> jewel[i].Y >> jewel[i].X;
	}
	sort(jewel, jewel + N);

	for (int i = 0; i < K; i++) {
		int c;
		cin >> c;
		bag.insert(c);
	}

	for (int i = N - 1; i >= 0; i--) {
		int v, m;
		tie(v, m) = jewel[i];
		auto iter = bag.lower_bound(m);
		if (iter == bag.end()) continue;
		ans += v;
		bag.erase(iter);
	}
	cout << ans << '\n';
}