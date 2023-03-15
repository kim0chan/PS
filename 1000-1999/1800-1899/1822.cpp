#include <bits/stdc++.h>
using namespace std;

int input;
vector<int> A, B;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int NA, NB;
	cin >> NA >> NB;

	for (int i = 0; i < NA; i++) {
		cin >> input;
		A.push_back(input);
	}
	for (int i = 0; i < NB; i++) {
		cin >> input;
		B.push_back(input);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	vector<int> ans;
	for (auto a : A) {
		if (binary_search(B.begin(), B.end(), a)) continue;
		ans.push_back(a);
	}

	cout << (int)ans.size() << '\n';
	for (auto a : ans) {
		cout << a << ' ';
	}

}