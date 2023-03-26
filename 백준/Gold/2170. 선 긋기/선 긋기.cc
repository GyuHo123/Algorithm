#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1000001

using namespace std;

ll t, x, y, len;

pair<int, int> arr[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    LOOP(i, 0, t) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + t);
    x = arr[0].first, y = arr[0].second;
    LOOP(i, 1, t) {
        if (arr[i].first <= y && arr[i].second >= y) {
            y = arr[i].second;
        } else if(arr[i].first > y){
            len += y - x;
            x = arr[i].first;
            y = arr[i].second;
        }
    }
    cout << len + y - x;
}