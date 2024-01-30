#include <bits/stdc++.h>

using namespace std;

int arr[100005];
int ddp[100005];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	cin >> M;
	
	for (int i = 1; i <= N; i++) {
		ddp[i] = ddp[i - 1] + arr[i];
	}

	while (M--) {
		int a, b;
		cin >> a >> b;
		cout << ddp[b] - ddp[a - 1] << '\n';
	}
}