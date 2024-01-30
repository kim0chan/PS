#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(void) {
	int N;
	float arr[1000];
	float sum, avg, max;

	cin >> N;
	max = -(INFINITY);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (max < arr[i]) { max = arr[i]; }
	}

	sum = 0;
	for (int i = 0; i < N; i++) {
		arr[i] = arr[i] / max * 100;
		sum += arr[i];
	}

	avg = sum / N;
	cout << avg;

	return 0;
}