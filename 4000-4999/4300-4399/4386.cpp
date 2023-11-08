#include <bits/stdc++.h>
using namespace std;

double xpos[101];
double ypos[101];
bool chk[101];

double dist(int a, int b) {
	return sqrt(pow((xpos[a] - xpos[b]), 2) + pow((ypos[a] - ypos[b]), 2));
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> xpos[i] >> ypos[i];
	}

	priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;
	chk[0] = true;

	for (int i = 1; i < N; i++) {
		pq.push({ dist(0, i), 0, i });
	}

	double ans = 0;
	int cnt = 0;
	while (cnt < N - 1) {
		double cost;
		int src, dst;
		tie(cost, src, dst) = pq.top();	pq.pop();

		if (chk[dst])	continue;
		ans += cost;
		cnt++;
		chk[dst] = true;

		for (int i = 0; i < N; i++) {
			if (chk[i])	continue;
			pq.push({dist(dst, i), dst, i});
		}
	}

	ans = floor(ans * 1e2) / 1e2;
	cout << ans << '\n';
}