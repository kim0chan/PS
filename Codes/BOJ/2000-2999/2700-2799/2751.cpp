#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
	int N;
	int arr[1000000];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}