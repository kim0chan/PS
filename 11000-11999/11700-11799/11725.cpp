#include <iostream>
#include <vector>

using namespace std;

const int ELEM_MAX = 100000 + 1;

int N;
bool visited[ELEM_MAX] = { false };
int parent[ELEM_MAX];
vector<int> tree[ELEM_MAX];

void findParent(int nodeNum) {
	visited[nodeNum] = true;

	for (int i = 0; i < tree[nodeNum].size(); i++) {
		int next = tree[nodeNum][i];

		if (!visited[next]) {
			parent[next] = nodeNum;
			findParent(next);
		}
	}
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int node1, node2;
		cin >> node1 >> node2;

		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	findParent(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';

	}

	return 0;
}