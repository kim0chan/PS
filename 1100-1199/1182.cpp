#include <bits/stdc++.h>
using namespace std;

int n, s;
int cnt = 0;
int arr[30];

void func(int sum, int cur) {
	if (cur == n) {
		if (sum == s) { cnt++; }
		return;
	}
	func(sum + arr[cur], cur + 1);
	func(sum, cur + 1);
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	func(0, 0);
	if (s == 0) cnt--;
	cout << cnt << '\n';

}