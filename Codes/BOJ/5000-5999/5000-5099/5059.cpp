#include <bits/stdc++.h>
using namespace std;

int T;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		int ans = 0;
		int numItems;
		cin >> numItems;
		vector<int> prices(numItems);

		for (int i = 0; i < numItems; i++) {
			cin >> prices[i];
		}

		sort(prices.begin(), prices.end(), greater<>());
		for (int i = 0; i < numItems; i++) {
			if ((i + 1) % 3 == 0)	ans += prices[i];
		}

		cout << ans << '\n';
	}
}