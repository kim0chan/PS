#include <bits/stdc++.h>
using namespace std;

int N;
int students[10001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	long long solve = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> students[i];
	}

	sort(students, students + N);

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int* ub = upper_bound(students + j + 1, students + N, -students[i] - students[j]);
			int* lb = lower_bound(students + j + 1, students + N, -students[i] - students[j]);
			solve += (ub - lb);
		}
	}

	cout << solve << '\n';
}