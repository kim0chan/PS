#include <bits/stdc++.h>

using namespace std;

int arr[3];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + 3);
	cout << arr[1];
}