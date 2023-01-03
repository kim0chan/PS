#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int ELEM_MAX = 100 + 1;

int N, M;
int inf_count = -1;
bool infected[ELEM_MAX] = { false };
vector<int> tree[ELEM_MAX];

void dfs(int nodeNum) {
	infected[nodeNum] = true;
	inf_count++;

	for (int i = 0; i < tree[nodeNum].size(); i++) {
		int next = tree[nodeNum][i];

		if (!infected[next]) {
			dfs(next);
		}
	}
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> M;

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

	dfs(1);
	cout << inf_count;

	return 0;
}