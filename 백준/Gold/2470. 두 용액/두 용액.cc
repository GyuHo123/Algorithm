#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct p {
    int first;
    int second;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int start = 0, end = n - 1;

    // Initialize the struct
    p sol{v[start], v[end]};
    int min_value = abs(sol.first + sol.second);

    while (start < end) {
        if(abs(v[start] + v[end]) < min_value) {
            min_value = abs(v[start] + v[end]);
            sol.first = v[start];
            sol.second= v[end];
        }

        if (v[start] + v[end] > 0)
            end--;
        else
            start++;
    }

    cout << sol.first << ' ' << sol.second << endl;
}
