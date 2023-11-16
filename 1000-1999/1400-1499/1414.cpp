#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> adj[101];
bool chk[101];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int cnt = 0;
	int total_cost = 0;
	int total_length = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < N; j++) {
			if (input[j] == '0')	continue;
			if ('a' <= input[j] && input[j] <= 'z') {
				adj[i].push_back({ j, input[j] - 'a' + 1 });
				adj[j].push_back({ i, input[j] - 'a' + 1 });
				total_length += (input[j] - 'a' + 1);
			}
			else if ('A' <= input[j] && input[j] <= 'Z') {
				adj[i].push_back({ j, input[j] - 'A' + 27 });
				adj[j].push_back({ i, input[j] - 'A' + 27 });
				total_length += (input[j] - 'A' + 27);
			}
		}
	}

	chk[0] = true;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	for (auto edge : adj[0]) {
		pq.push({ edge.second, 0, edge.first });
	}

	//cout << "[DEBUG] total length : " << total_length << '\n';

	while (cnt < N - 1) {
		if (pq.empty()) {
			cout << -1 << '\n';
			return 0;
		}
		int src, dst, cost;
		tie(cost, src, dst) = pq.top();	pq.pop();
		if (chk[dst])	continue;

		total_cost += cost;
		chk[dst] = true;

		for (auto edge : adj[dst]) {
			if (chk[edge.first])	continue;
			pq.push({ edge.second, dst, edge.first });
		}
		
		cnt++;
	}

	//cout << "[DEBUG] total cost : " << total_cost << '\n';
	cout << total_length - total_cost << '\n';
}