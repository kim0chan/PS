#include <iostream>

using namespace std;

int main(void) {
	int cycle = 0;
	int input;
	int input_l, input_r;
	int result;
	int result_l, result_r;
	int initial_value;

	cin >> input;
	initial_value = input;

	while (1) {
		cycle++;
		input_r = input % 10;
		input_l = input / 10;

		result = input_l + input_r;

		result_r = result % 10;
		result_l = result / 10;

		input = (input_r * 10) + result_r;

		if (input == initial_value) {
			break;
		}
	}
	cout << cycle;
	return 0;
}