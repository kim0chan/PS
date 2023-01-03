#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int c;
	float result[1000];
	int arr[1000];
	int size, sum, avg, over;

	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> size;
		sum = 0;
		over = 0;
		for (int j = 0; j < size; j++) {
			cin >> arr[j];
			sum += arr[j];
		}
		avg = sum / size;
		for (int j = 0; j < size; j++) {
			if (arr[j] > avg) { over++; }
		}
		
		result[i] = ((float)over / (float)size);
	}

	for (int i = 0; i < c; i++) {
		fprintf(stdout, "%.3f%%\n", result[i] * 100);
	}

	return 0;
}