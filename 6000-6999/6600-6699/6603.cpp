#include <bits/stdc++.h>
#define MAX		6
using namespace std;

int N;
int num[50];
int arr[6];
bool visited[50];

void solve(int k) {
	if (k == MAX) {
		for (int i = 0; i < MAX; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i] && (k == 0 || arr[k - 1] < num[i])) {
			arr[k] = num[i];
			visited[i] = true;
			solve(k + 1);
			visited[i] = false;
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
		sort(num, num + N);

		solve(0);
		cout << '\n';
	} while (N);
}