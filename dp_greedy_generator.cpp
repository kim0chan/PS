#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	srand(time(NULL));

	int DP[] = { 2302, 2293, 1788, 4883, 9251, 1699, 9084, 1915, 10942, 9655, 2011, 2294, 2133, 1520, 9657, 11660, 2482 };
	int greedy[] = { 2457, 1541, 1744, 2847, 1439, 11000, 15903, 2170, 1700, 8980, 7570 };

	int type, num, prob;

	
	type = rand() % 2;
	if (type) {
		num = rand() % (sizeof(DP) / sizeof(int));
		prob = DP[num];
	}
	else {
		num = rand() % (sizeof(greedy) / sizeof(int));
		prob = greedy[num];
	}
	
	cout << "오늘은 " << prob << "번 문제를 풀어보아요\n";
	
}