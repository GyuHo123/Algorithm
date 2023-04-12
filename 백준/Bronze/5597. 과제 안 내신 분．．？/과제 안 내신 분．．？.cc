#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int arr[30];

int main() {
    for (int i = 0; i < 28; i++) {
        int n;
        cin >> n;
        arr[n - 1] = 1;
    }
    for (int i = 0; i < 30; i++) {
        if (arr[i] == 0) cout << i + 1 << endl;
    }
    return 0;
}