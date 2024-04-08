#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 10001

using namespace std;

int n, arr[MAXN];
ll cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    loop(i, 0, n - 1) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    loop(i, 0, n - 3) {
        int st = i + 1;
        int e = n - 1;

        while (st < e) {
            int left = arr[st];
            int right = arr[e];

            if (!(arr[i] + left + right)) {
                if (left == right) {
                    cnt += e - st;
                    st++;
                } else {
                    int rcnt = 1, lcnt = 1;
                    while (st + lcnt < e && arr[st] == arr[st + lcnt]) lcnt++;
                    while (e - rcnt > st && arr[e] == arr[e - rcnt]) rcnt++;
                    cnt += lcnt * rcnt;
                    st += lcnt;
                    e -= rcnt;
                }
            } else if (arr[i] + right + left < 0) st++;
            else e--;
        }
    }
    cout << cnt;
}