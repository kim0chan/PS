#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {

	string input;
	cin >> input;

	for (char i = 'a'; i <= 'z'; i++) {
		cout << (int)input.find(i) << ' ';
	}
}
