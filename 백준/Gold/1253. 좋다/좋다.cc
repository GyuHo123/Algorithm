#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 2001

using namespace std;

int n, sum, st, en, t, cnt = 0, arr[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    loop(i, 0, n - 1){
        cin >> t;
        arr[i] = t;
    }
    sort(arr, arr + n);
    loop(i, 0, n - 1) {
        st = 0;
        en = n - 1;
        while (st < en) {
            if (arr[st] + arr[en] == arr[i] && st != i && en != i) {
                cnt++;
                break;
            }
            if (arr[st] + arr[en] == arr[i]) {
                if (st == i) {
                    st++;
                    continue;
                }
                if (en == i) {
                    en--;
                    continue;
                }
            }
            if (arr[st] + arr[en] < arr[i]) st++;
            else en--;
        }
    }
    cout << cnt;
}