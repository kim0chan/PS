#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int T, n, order, num, ret, size;
	string input;

	queue<int> qu;
	vector<int> v;
	int* front, * back;

	cin >> T;
	for (int i = 0; i < T; i++) {
		v.clear();
		cin >> input;

		for (int j = 0; j < input.size(); j++) {
			if (input[j] == 'R') {
				qu.push(1);
				//fprintf(stdout, "1 pushed into queue\n");
			}
			else if (input[j] == 'D') {
				qu.push(0);
				//fprintf(stdout, "0 pushed into queue\n");
			}
			else {
				fprintf(stdout, "input error\n");
				return 0;
			}
		}

		order = 1;
		cin >> n;
		cin >> input;
		num = 0;
		ret = 1;

		for (int j = 1; j < input.length(); j++) {
			if (input[j] > 47 && input[j] < 58) {
				num *= 10;
				num += (int)(input[j] - 48);
			}
			else {
				if (j > 1) {
					v.push_back(num);
					num = 0;
				}
			}
		}

		size = v.size();
		if (size) {
			front = &v.front();
			back = &v.back();
		}
		else {
			front = back = 0;
		}

		while (!qu.empty()) {
			num = qu.front();
			//fprintf(stdout, "[DEBUG] num is %d.\n", num);
			qu.pop();

			if (num == 1) {
				order *= -1;
			}
			else if (num == 0) {
				if (size) {
					if (order > 0) {
						//fprintf(stdout, "[DEBUG] %d deleted from vector\n", v.front());
						front = front + 1;
					}
					else {
						//fprintf(stdout, "[DEBUG] %d deleted from vector\n", v.back());
						back = back - 1;
					}
					size--;
				}
				else {
					cout << "error" << '\n';
					while (!qu.empty()) {
						qu.pop();
					}
					ret = 0;
					break;
				}
			}
			else {
				fprintf(stdout, "queue error\n");
				return 0;
			}
		}

		if (ret) {
			cout << '[';
			if (order > 0) {
				for (int i = 0; i < size; i++) {
					cout << *(front + i);
					if (i < size - 1) { cout << ','; }
				}
			}
			else {
				for (int i = 0; i < size; i++) {
					cout << *(back - i);
					if (i < size - 1) { cout << ','; }
				}
			}
			cout << ']' << '\n';
		}
	}

	return 0;
}