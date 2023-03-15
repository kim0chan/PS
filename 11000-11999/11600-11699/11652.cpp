#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> v;
long long input;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	while (N--) {
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	int local_cnt = 1, max_cnt = 0;
	long long cur = v[0], solve = v[0];

	for (int i = 1; i < v.size(); i++) {
		if (cur != v[i]) {
			if (max_cnt < local_cnt) {
				max_cnt = local_cnt;
				solve = v[i - 1];
			}
			cur = v[i];
			local_cnt = 1;
		}
		else {
			local_cnt++;
		}
	}

	if (max_cnt < local_cnt) {
		solve = v[v.size() - 1];
	}

	cout << solve << '\n';

}