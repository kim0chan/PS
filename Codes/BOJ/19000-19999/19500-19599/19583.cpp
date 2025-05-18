#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

string S, E, Q;
int start_time, end_time, quit_time, cnt;

int TimeToValue(string& s) {
	int h = stoi(s.substr(0, 2));
	int m = stoi(s.substr(3, 2));

	return h * 60 + m;
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	unordered_set<string> visitors;

	cin >> S >> E >> Q;
	start_time = TimeToValue(S);
	end_time = TimeToValue(E);
	quit_time = TimeToValue(Q);

	while (true) {
		string chat_time;
		string name;

		cin >> chat_time >> name;
		if (cin.eof()) break;

		if (TimeToValue(chat_time) <= start_time) {
			visitors.insert(name);
		}
		else if (end_time <= TimeToValue(chat_time) &&
				quit_time >= TimeToValue(chat_time)) {
			if (visitors.find(name) != visitors.end()) {
				visitors.erase(name);
				cnt++;
			}
		}
	}

	cout << cnt << '\n';
}