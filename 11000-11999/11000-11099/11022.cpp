#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        int A, B;
        cin >> A >> B;
        cout << "Case #" << i << ": " << A << " + " << B << " = " << A + B << '\n';
    }
}