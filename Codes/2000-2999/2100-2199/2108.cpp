#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
	int N;
	int arr[500000];
	int sum, freq_num, best_freq, cur_freq, freq_count;
	float avg;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	sum = arr[0];
	freq_num = arr[0];
	best_freq = 1;
	freq_count = 1;
	cur_freq = 1;

	for (int i = 1; i < N; i++) {
		sum += arr[i];
		
		if (arr[i - 1] == arr[i]) {
			cur_freq++;
		}
		else {
			cur_freq = 1;
		}

		if (best_freq <= cur_freq) {
			if (best_freq == cur_freq) {
				if (freq_count < 2) {
					freq_num = arr[i];
					freq_count++;
				}
			}
			else {
				freq_num = arr[i];
				best_freq = cur_freq;
				freq_count = 1;
			}
		}
	}
	avg = (float)sum / (float)N;
	avg = floor(avg + 0.5);
	

	cout << avg << '\n' << arr[(N / 2)] << '\n' << freq_num << '\n' << arr[N - 1] - arr[0];

	return 0;
}