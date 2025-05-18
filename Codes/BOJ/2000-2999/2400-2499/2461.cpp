#include <bits/stdc++.h>
#define MIN(a, b) a < b ? a : b
using namespace std;

int N, M;
int students[1001][1001];
int cur[1001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)	cin >> students[i][j];
	}

	for (int i = 0; i < N; i++) {
		sort(students[i], students[i] + M);
	}

	int maxidx = 0, minidx = 0;
	int solve = 0x7fffffff;
	while (cur[minidx] < M) {
		int min = 0x7fffffff;
		int max = -1;
		for (int i = 0; i < N; i++) {
			if (students[i][cur[i]] < min) {
				min = students[i][cur[i]];
				minidx = i;
			}
			if (students[i][cur[i]] > max) {
				max = students[i][cur[i]];
				maxidx = i;
			}
		}
		solve = MIN(solve, max - min);
		//cout << "[DEBUG] (max, min) is " << "(" << max << ", " << min << ")\n";
		//cout << "[DEBUG] solve is set to " << solve << '\n';
		cur[minidx]++;
	}

	cout << solve << '\n';
}