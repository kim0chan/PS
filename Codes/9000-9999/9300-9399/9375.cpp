#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		int solve = 1;
		int n;
		cin >> n;
		unordered_map<string, int> closet;
		while (n--) {
			string name, type;
			cin >> name >> type;
			if (closet.find(type) == closet.end())	closet[type] = 2;
			else 									closet[type]++;
		}

		for (auto elem : closet) {
			solve *= elem.second;
		}

		solve--;
		cout << solve << '\n';
	}
}