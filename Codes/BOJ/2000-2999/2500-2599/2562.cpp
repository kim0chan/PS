#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n = 9;
	int arr[9];
	int input;
	int max, index;

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (!i) {
			max = input;
			index = 1;
		}

		if (input > max) {
			max = input;
			index = i + 1;
		}
	}

	cout << max << '\n' << index;
}