#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int A, B;
    cin >> A >> B;
    
    if(A > B) {
        cout << ">" << '\n';
    }
    else if(A < B) {
        cout << "<" << '\n';
    }
    else {
        cout << "==" << '\n';
    }
}