#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	bool existence[2000001] = { 0, };
	int arr[100001] = { 0, };
	int n, cnt, x;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}
	cin >> x;

	cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] >= x) continue;
		else { // arr[i] < x
			if (existence[x - arr[i]]) { cnt++; }
			existence[arr[i]] = true;
		}
	}

	cout << cnt;

	return 0;
}