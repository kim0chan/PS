#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
unordered_map<string, int> um;
const int MX = 200005;
int parent[MX];
int num_friends[MX];

int Find(int x) {
	if (parent[x] == x)	return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	//cout << "Union(" << x << ", " << y << ") 호출\n";
	x = Find(x);
	y = Find(y);

	if (x < y) {
		parent[y] = x;
		num_friends[x] += num_friends[y];
	}
	else if (x > y){
		parent[x] = y;
		num_friends[y] += num_friends[x];
	}
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		um.clear();
		int unused = 1;
		for (int i = 0; i < MX; i++) {
			parent[i] = i;
			num_friends[i] = 1;
		}

		int F;
		cin >> F;

		int A, B;
		for (int i = 0; i < F; i++) {
			string input_A, input_B;
			cin >> input_A >> input_B;

			if (!um[input_A]) {
				um[input_A] = unused++;
				//cout << input_A << "의 해쉬 값이 " << unused - 1 << "이 되었음.\n";
			}
			A = um[input_A];

			if (!um[input_B]) {
				um[input_B] = unused++;
				//cout << input_B << "의 해쉬 값이 " << unused - 1 << "이 되었음.\n";
			}
			B = um[input_B];

			Union(A, B);
			int root = Find(A);
			cout << num_friends[root] << '\n';
		}
	}
}