#include <bits/stdc++.h>
using namespace std;

int solution[100005];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ans1 = 1e9+1;
	int ans2 = 1e9+1;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> solution[i];
	}

	for (int i = 0; i < N; i++) {
		int idx = lower_bound(solution, solution + N, -solution[i]) - solution;
		if (idx + 1 < N && i != idx + 1 && abs(solution[i] + solution[idx + 1]) < abs(ans1 + ans2)) {
			ans1 = solution[i];
			ans2 = solution[idx + 1];
		}
		if (idx < N && i != idx && abs(solution[i] + solution[idx]) < abs(ans1 + ans2)) {
			ans1 = solution[i];
			ans2 = solution[idx];
		}
		if (idx != 0 && i != idx - 1 && abs(solution[i] + solution[idx - 1]) < abs(ans1 + ans2)) {
			ans1 = solution[i];
			ans2 = solution[idx - 1];
		}
	}
	if (ans1 > ans2)	swap(ans1, ans2);
	cout << ans1 << ' ' << ans2 << '\n';
}