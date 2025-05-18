#include <iostream>

using namespace std;

int main(void) {
	int a, b;

	while (1) {
		cin >> a >> b;

		if (a || b) {
			cout << a + b << '\n';
		}
		else break;
	}

	return 0;
}