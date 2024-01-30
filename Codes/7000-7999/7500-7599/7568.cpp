#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct {
	int height;
	int weight;
	int rank;
} man_info;

int main() {
	man_info arr[50];
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i].weight >> arr[i].height;
		arr[i].rank = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i].height < arr[j].height && arr[i].weight < arr[j].weight) {
				arr[i].rank += 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i].rank << " ";
	}
}