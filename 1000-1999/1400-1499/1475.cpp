#include <bits/stdc++.h>

using namespace std;

int main() {
	int max = 0;
	int room;
	int arr[9] = { 0, };
	//0 1 2 3 4 5 6 7 8

	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> room;
	while (room) {
		int num;
		num = room % 10;
		if (num == 9) {
			num -= 3;
		}
		arr[num]++;

		room /= 10;
	}

	for (int i = 0; i < 9; i++) {
		int comp = (i != 6) ? arr[i] : (arr[i] + 1) / 2;
		max = (max < comp) ? comp : max;
	}

	cout << max;
	return 0;
}