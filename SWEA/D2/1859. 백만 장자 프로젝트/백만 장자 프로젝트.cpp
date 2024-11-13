#include <iostream>
#include <climits>
#include <string.h>
#define loop(i, s, n) for (int i = s; i <= n; i++)
#define ll long long
#define MAXN 1000001

using namespace std;

int t, n;

ll arr[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    int test = 0;

    while(t--) {
        memset(arr, 0, sizeof(arr));
        ll max1 = INT_MIN, ans = 0;
        cin >> n;
        loop(i, 1, n) {
            cin >> arr[i];
        }

        for(int i = n; i > 0; i--) {
            max1 = max(max1, arr[i]);
            ans += max1 - arr[i];
        }

        test++;

        cout << "#" << test << " " <<  ans << endl;
    }
}