#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class point {
	public:
		int x;
		int y;

		point(int _x, int _y) {
			x = _x;
			y = _y;
		}
};

bool compare(point &a, point &b) {
	if (a.y < b.y) {
		return true;
	}

	else if (a.y == b.y) {
		if (a.x < b.x) {
			return true;
		}
		else return false;
	}
	else return false;
}

int main() {
	int N;

	cin >> N;
	int x, y = 0;

	vector<point> v;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(point(x, y));
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++) {
		cout << v[i].x << ' ' << v[i].y << '\n';
	}

	return 0;
}