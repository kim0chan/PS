#include <bits/stdc++.h>
using namespace std;

int N;
int arr[10];
bool visited[10];

void solve(int k) {
	if (k == N) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			arr[k] = i;
			visited[i] = true;
			solve(k + 1);
			visited[i] = false;
		}
	}

}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;

	solve(0);
}