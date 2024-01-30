#include <bits/stdc++.h>
using namespace std;

int N;
int p[28];
int lc[28];
int rc[28];

void preOrderTraversal(int V) {
	cout << char(V + 'A');
	if (lc[V])	preOrderTraversal(lc[V]);
	if (rc[V])	preOrderTraversal(rc[V]);
}

void inOrderTraversal(int V) {
	if (lc[V])	inOrderTraversal(lc[V]);
	cout << char(V + 'A');
	if (rc[V])	inOrderTraversal(rc[V]);
}

void postOrderTraversal(int V) {
	if (lc[V])	postOrderTraversal(lc[V]);
	if (rc[V])	postOrderTraversal(rc[V]);
	cout << char(V + 'A');
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		char name, left, right;
		cin >> name >> left >> right;

		if (left != '.')	lc[name - 'A'] = left - 'A';
		if (right != '.')	rc[name - 'A'] = right - 'A';
	}

	/*
	for (int i = 0; i < N; i++) {
		cout << char(i + 'A') << ' ';
	}
	cout << '\n';
	for (int i = 0; i < N; i++) {
		cout << lc[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < N; i++) {
		cout << rc[i] << ' ';
	}
	cout << '\n';
	*/
	preOrderTraversal(0);
	cout << '\n';
	inOrderTraversal(0);
	cout << '\n';
	postOrderTraversal(0);
	cout << '\n';
}