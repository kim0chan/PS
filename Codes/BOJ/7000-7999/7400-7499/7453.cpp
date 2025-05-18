#include <bits/stdc++.h>
using namespace std;

int N;
int a[4002], b[4002], c[4002], d[4002];
int cd[16000002];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) { cin >> a[i] >> b[i] >> c[i] >> d[i]; }

	for (int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cd[i * N + j] = c[i] + d[j];
		}
	}

	sort(cd, cd + N * N);

	long long ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += upper_bound(cd, cd + N * N, -a[i] - b[j]) - lower_bound(cd, cd + N * N, -a[i] - b[j]);
		}
	}

	cout << ans << '\n';
}