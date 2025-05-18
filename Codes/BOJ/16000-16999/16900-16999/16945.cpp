#include <bits/stdc++.h>
using namespace std;

int ans = 0x3f3f3f3f;
int arr[9];
int brr[9];
bool vis[9];

int calculateCost() {
	int ret = 0;
	for (int i = 0; i < 9; i++) {
		ret += abs(arr[i] - brr[i]);
	}

	return ret;
}

void solve(int k) {
	if (k == 9) {
		int sum = brr[0] + brr[1] + brr[2];
		if (brr[3] + brr[4] + brr[5] != sum)	return;
		if (brr[6] + brr[7] + brr[8] != sum)	return;

		if (brr[0] + brr[3] + brr[6] != sum)	return;
		if (brr[1] + brr[4] + brr[7] != sum)	return;
		if (brr[2] + brr[5] + brr[8] != sum)	return;

		if (brr[0] + brr[4] + brr[8] != sum)	return;
		if (brr[2] + brr[4] + brr[6] != sum)	return;

		ans = min(ans, calculateCost());
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (vis[i])	continue;
		vis[i] = true;
		brr[k] = i + 1;
		solve(k + 1);
		vis[i] = false;
	}
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	solve(0);
	cout << ans << '\n';
}