#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int x, stick = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> x;
    for (int i = 0; i < 7; i++) {
        if (x & (1 << i)) {
            stick++;
        }
    }

    cout << stick << endl;
}
