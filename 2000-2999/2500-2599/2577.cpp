#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int A, B, C;
	int result;
	int num;
	int arr[10] = { 0, };

	cin >> A;
	cin >> B;
	cin >> C;

	result = A * B * C;

	while (result) {
		num = result % 10;
		arr[num]++;
		result /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}