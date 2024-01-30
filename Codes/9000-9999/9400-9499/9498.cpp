#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n;
    cin >> n;
    if(n >= 90) {
        cout << 'A';
    }
    else if(n >= 80) {
        cout << 'B';
    }
    else if(n >= 70) {
        cout << 'C';
    }
    else if(n >= 60) {
        cout << 'D';
    }
    else {
        cout << 'F';
    }
}