#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int ELEM_MAX = 1000 + 1;

int N, M, V;
bool visited[ELEM_MAX] = { false };
vector<int> tree[ELEM_MAX];
queue<int> q;

void reset(bool* visited) {
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}

	return;
}

void depthTraversal(int nodeNum) {
	visited[nodeNum] = true;

	cout << nodeNum << ' ';
	for (int i = 0; i < tree[nodeNum].size(); i++) {
		int next = tree[nodeNum][i];

		if (!visited[next]) {
			depthTraversal(next);
		}
	}
}

void breadthTraversal(int nodeNum) {
	int next;

	q.push(nodeNum);
	visited[nodeNum] = 1;

	while (!q.empty()) {
		next = q.front();
		q.pop();
		cout << next << ' ';

		for (int i = 0; i < tree[next].size(); i++) {
			if (!visited[tree[next][i]]) {
				q.push(tree[next][i]);
				visited[tree[next][i]] = 1;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int node1, node2;

		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		//fprintf(stdout, "[DEBUG] %d is pushed into vector %d\n", node2, node1);
		tree[node2].push_back(node1);
		//fprintf(stdout, "[DEBUG] %d is pushed into vector %d\n", node1, node2);
		sort(tree[node1].begin(), tree[node1].end());
		sort(tree[node2].begin(), tree[node2].end());
	}

	depthTraversal(V);
	reset(visited);
	cout << '\n';
	breadthTraversal(V);

	return 0;
}