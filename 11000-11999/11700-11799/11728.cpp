#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	//vector<int> A(N);
	//vector<int> B(M);
	vector<int> result;

	for (int i = 0; i < N + M; i++) {
		int input;
		cin >> input;
		result.push_back(input);
	}

	sort(result.begin(), result.end());

	for (auto a : result) {
		cout << a << ' ';
	}
	cout << '\n';

	

}