#include <bits/stdc++.h>
using namespace std;

int N;
string input;
vector<long long> v;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		reverse(input.begin(), input.end());
		v.push_back(stoll(input));
	}

	sort(v.begin(), v.end());
	for (auto a : v) {
		cout << a << '\n';
	}
}