#include <bits/stdc++.h>
using namespace std;

#define loop(i, s, n) for(int i = s; i < n; i++)
#define MAXN 10000

int K, N;
long long cable[MAXN];

bool cable_possible(long long length) {
    int count = 0;
    
    loop(i, 0, K) {
        count += cable[i] / length;
    }

    return (count >= N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;
    long long max_length = 0;
    
    loop(i, 0, K) {
        cin >> cable[i];
        max_length = max(max_length, cable[i]);
    }

    long long low = 1, high = max_length, ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (cable_possible(mid)) {
            ans = max(ans, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
