#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[10];
int arr[10];
bool visited[10];

void solve(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int temp = -1;
	for (int i = 0; i < N; i++) {
		if (temp != num[i]) {
			visited[i] = true;
			arr[k] = num[i];
			temp = arr[k];
			solve(k + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);

	solve(0);
}