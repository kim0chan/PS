#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n, min, max;
	int arr[1000001];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	min = max = arr[0];

	for (int i = 1; i < n; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	cout << min << ' ' << max;
}