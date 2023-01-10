#include <bits/stdc++.h>

using namespace std;

int N;
int arr[6];
int num[50];
bool visited[50];

void solve(int k) {
	if (k == 6) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i < N; i++) {
			if (!visited[i] && (k == 0 || arr[k - 1] < num[i])) {
				arr[k] = num[i];
				visited[i] = true;
				solve(k + 1);
				visited[i] = false;
			}
		}
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	do {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}

		solve(0);
	} while (N);
}