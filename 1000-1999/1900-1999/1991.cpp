#include <iostream>
#include <vector>

using namespace std;
//A는 65.
const int ELEM_MAX = 26;

int N;
bool visited[ELEM_MAX] = { false };
int parent[ELEM_MAX];
vector<int> tree[ELEM_MAX];

void preorderTraversal(int num) {
	cout << (char)(num + 65);

	for (int i = 0; i < tree[num].size(); i++) {
		if (tree[num][i] >= 0) {
			preorderTraversal(tree[num][i]);
		}
	}

	return;
}

void inorderTraversal(int num) {
	int cnt = tree[num].size();

	if (cnt && tree[num][0] >= 0) {
		inorderTraversal(tree[num][0]);
	}

	cout << (char)(num + 65);

	if (cnt && tree[num][1] >= 0) {
		inorderTraversal(tree[num][1]);
	}
	return;
}

void postorderTraversal(int num) {
	for (int i = 0; i < tree[num].size(); i++) {
		if (tree[num][i] >= 0) {
			postorderTraversal(tree[num][i]);
		}
	}

	cout << (char)(num + 65);

	return;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		char node1, node2, node3;
		int n1, n2, n3;
		cin >> node1 >> node2 >> node3;
		n1 = node1 - 65;
		n2 = node2 - 65;
		n3 = node3 - 65;
		tree[n1].push_back(n2);
		tree[n1].push_back(n3);
	}

	preorderTraversal(0);
	cout << '\n';
	inorderTraversal(0);
	cout << '\n';
	postorderTraversal(0);
	cout << '\n';

	return 0;
}