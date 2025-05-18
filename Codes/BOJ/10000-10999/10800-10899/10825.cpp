#include <bits/stdc++.h>
using namespace std;

typedef struct {
	string name;
	int kor;
	int eng;
	int mth;
} STUDENT;

int N;
STUDENT input;
vector<STUDENT> v;

bool compare(STUDENT& a, STUDENT& b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.mth == b.mth) {
				return a.name < b.name;
			}
			return a.mth > b.mth;
		}
		return a.eng < b.eng;
	}
	return a.kor > b.kor;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input.name >> input.kor >> input.eng >> input.mth;
		v.push_back(input);
	}

	sort(v.begin(), v.end(), compare);
	for (auto e : v) {
		cout << e.name << '\n';
	}
}