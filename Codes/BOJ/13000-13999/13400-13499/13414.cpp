#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool compare(pair<string, int>& a, pair<string, int>& b) {
	return a.second < b.second;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	unordered_map<string, int> um;
	int K, L;
	cin >> K >> L;

	for (int i = 0; i < L; i++) {
		string input;
		cin >> input;
		if (um.find(input) != um.end()) {
			um.erase(input);		
		}
		um[input] = i;
	}

	vector<pair<string, int>> ans(um.begin(), um.end());
	sort(ans.begin(), ans.end(), compare);

	int en = min(K, (int)ans.size());
	for (int i = 0; i < en; i++) {
		cout << ans[i].first << '\n';
	}

}