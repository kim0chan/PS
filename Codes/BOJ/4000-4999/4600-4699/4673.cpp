#include <bits/stdc++.h>

using namespace std;


bool nums[10001];

int d(int num) {
	int sum = num;

	while (num) {
		sum += num % 10;
		num /= 10;
	}

	return sum;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	for (int i = 1; i < 10001; i++) {
		int ret = d(i);

		if (ret < 10001) {
			nums[ret] = true;
		}
	}

	for (int i = 1; i < 10001; i++) {
		if (!nums[i]) {
			cout << i << '\n';
		}
	}
}