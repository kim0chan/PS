#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if(!a) return b;
    return gcd(b%a, a);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
	int n1, n2;
	cin >> n1 >> n2;
	cout << gcd(n1, n2) << "\n" << lcm(n1, n2);
}
