#include <bits/stdc++.h>
using namespace std;

int N, M;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	vector<int> cards;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		cards.push_back(input);
	}
	sort(cards.begin(), cards.end());
	cin >> M;
	while (M--) {
		int input;
		cin >> input;
		cout << binary_search(cards.begin(), cards.end(), input) << ' ';
	}
}