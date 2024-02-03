#include <bits/stdc++.h>
#define endl '\n'
#define LOOP(i, s, n) for(int i = s; i < n; i++)
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    vector<int> v(N, 0);

    LOOP(i, 0, M) {
        v[i] = 1;
    }

    do {
        LOOP(i, 0, N) {
            if (v[i]) cout << i + 1 << ' ';
        }
        cout << endl;
    } while (prev_permutation(v.begin(), v.end()));
}
