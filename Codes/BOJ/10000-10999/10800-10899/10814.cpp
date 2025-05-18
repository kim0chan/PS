#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

class info {
	public:
		int age;
		int order;
		string name;

	info(int _age, int _order, string _name) {
		age = _age;
		order = _order;
		name = _name;
	}
};

bool compare(info a, info b) {
	if (a.age < b.age) {
		return true;
	}
	else if (a.age == b.age) {
		if (a.order < b.order) {
			return true;
		}
		else
			return false;
	}
	else return false;
}

int main() {
	int N;
	int age;
	string name;

	cin >> N;
	
	vector<info> v;

	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		v.push_back(info(age, i, name));
	}
	
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << v[i].age << ' ' << v[i].name << '\n';
	}

	return 0;
}