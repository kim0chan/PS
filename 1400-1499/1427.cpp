#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int N;
	int size;
	int arr[10000000];
	int j = 0;

	size = 0;
	cin >> N;

	while (N) {
		arr[j] = N % 10;
		N = N/10;
		j++;
		size++;
	}

	sort(arr, arr + size, compare);

	for (int i = 0; i < size; i++) {
		cout << arr[i];
	}

	return 0;
}