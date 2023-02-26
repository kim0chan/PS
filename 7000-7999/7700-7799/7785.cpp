#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	unordered_set<string> us;

	int n;
	cin >> n;

	while (n--) {
		string name, command;
		cin >> name >> command;

		if (command == "enter")		us.insert(name);
		else						us.erase(name);
	}
	vector<string> ans(us.begin(), us.end());
	sort(ans.rbegin(), ans.rend());
	for (auto a : ans) {
		cout << a << '\n';
	}
}