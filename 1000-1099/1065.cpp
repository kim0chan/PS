#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int isHansu(int num) {
	int a[4] = { 0, };
	int i = 0;
	int diff, comp;

	while (num) {
		a[i] = num % 10;
		num /= 10;
		i++;
	}

	diff = a[0] - a[1];
	for (int j = 1; j < i - 1; j++) {
		comp = a[j] - a[j + 1];
		if (diff != comp) {
			return 0;
		}
	}

	return 1;
}

int main(void) {
	int N, count;

	cin >> N;
	count = 0;
	for (int i = 1; i <= N; i++) {
		if (isHansu(i)) { count++; }
	}

	cout << count;
	return 0;
}