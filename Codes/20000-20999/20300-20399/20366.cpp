#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ans = 0x7fffffff;

	vector<int> snow;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		snow.push_back(input);
	}
	sort(snow.begin(), snow.end());

	for (int i = 0; i < N; i++) {
		for (int j = i + 3; j < N; j++) {
			int first = snow[i] + snow[j];
			int left = i + 1;
			int right = j - 1;

			while (left <= right) {
				int second = snow[left] + snow[right];
				ans = min(ans, abs(first - second));
				if (first - second <= 0)	right--;
				else	left++;
			}
		}
	}
	cout << ans << '\n';
}