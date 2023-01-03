#include <iostream>

using namespace std;

int main(void) {
	int num;
	int i, j;

	cin >> num;

	for (i = 1; i <= num; i++) {
		for (j = 0; j < i; j++) {
			cout << "*";
		}
		cout << '\n';
	}

	return 0;
}