#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	unordered_map<string, string> book;

	while (N--) {
		string domain;
		cin >> domain;
		cin >> book[domain];
	}

	while (M--) {
		string domain;
		cin >> domain;
		cout << book[domain] << '\n';
	}
}