#include <bits/stdc++.h>
using namespace std;

vector<int> solve;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 2; i * i <= N; i++) {
		while (N % i == 0) {
            // vector에 안넣고 바로 cout 해줘도 된다.
			solve.push_back(i);
			N /= i;
		}
	}

	for (auto a : solve) {
		cout << a << '\n';
	}

	if (N != 1) cout << N << '\n';
}