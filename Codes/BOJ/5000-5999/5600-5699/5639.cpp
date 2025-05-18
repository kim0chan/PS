#include <iostream>
#include <vector>

using namespace std;

const int ELEM_MAX = 1000001;

typedef struct node {
	int left = 0;
	int right = 0;
} NODE;

vector<node> v(ELEM_MAX);

void postorderTraversal(int root) {
	if (root == 0) {
		return;
	}
	else {
		postorderTraversal(v[root].left);
		postorderTraversal(v[root].right);
		cout << root << '\n';
	}
	return;
}

void insert(int val, int root) {
	if (val < root) {
		if (v[root].left == 0) {
			//fprintf(stdout, "DEBUG: v[%d].left = %d\n", root, v[root].left);
			v[root].left = val;
			//fprintf(stdout, "DEBUG: %d이 %d의 왼쪽에 삽입됨.\n", val, root);
			return;
		}
		else {
			insert(val, v[root].left);
		}
	}
	else if (val > root) {
		if (v[root].right == 0) {
			//fprintf(stdout, "DEBUG: v[%d].right = %d\n", root, v[root].right);
			v[root].right = val;
			//fprintf(stdout, "DEBUG: %d이 %d의 오른쪽에 삽입됨.\n", val, root);
			return;
		}
		else {
			insert(val, v[root].right);
		}
	}
	else {
		fprintf(stdout, "[DEBUG] an error occurred in insert function\n");
	}
}

int main() {
	int val, root;
	int i = 1;

	while (cin >> val) {
		if (i) {
			root = val;
			i--;
		}
		else {
			insert(val, root);
		}
	}

	postorderTraversal(root);

	return 0;
}