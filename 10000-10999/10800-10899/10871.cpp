#include <iostream>

using namespace std;

int main(void) {
	int n, x;
	int Arr[10000];
	
	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> Arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (Arr[i] < x) {
			cout << Arr[i] << ' ';
		}
	}

	return 0;
}