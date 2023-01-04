#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int numarr[10];
bool visited[10];

void solve(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[k] = numarr[i];
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
		cin >> numarr[i];
	}
	sort(numarr, numarr + N);

	solve(0);
}