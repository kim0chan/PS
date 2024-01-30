#include <bits/stdc++.h>

using namespace std;

int GCDD(int a, int b)
{
	if (b == 0) { return a; }
	if (a < b) { return GCDD(a, b % a); }
	return GCDD(b, a % b);
}

int GCD(int a, int b) {
	if (b == 0) { return a; }
	if (a > b) { return GCD(b, a % b); }
	return GCD(a, b % a);
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;

	while (T--) {
		int a, b, gcd;
		cin >> a >> b;

		gcd = GCD(a, b);

		cout << (a / gcd) * (b / gcd) * gcd << '\n';
	}
}