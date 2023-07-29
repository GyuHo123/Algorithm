#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 1000001

using namespace std;

vector<int> arr(MAXN), arr1;
int n;
set<int> s1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s1.insert(arr[i]);
    }

    for (auto t : s1) {
        arr1.push_back(t);
    }

    for (int i = 0; i < n; i++) {
        cout << lower_bound(arr1.begin(), arr1.end(), arr[i]) - arr1.begin() << " ";
    }
}
