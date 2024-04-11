#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 601

using namespace std;

int n, arr[MAXN];

struct p{
    int sum, x, y;
};

int cmp(p t1, p t2){
    return t1.sum < t2.sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int st = 0, en = 0, min1 = INT_MAX;

    vector<p> arrsum;

    cin >> n;

    loop(i, 0, n - 1) cin >> arr[i];

    sort(arr, arr + n);

    loop(i, 0, n - 4) {
        loop(j, i + 3, n - 1) {
            st = i + 1, en = j - 1;
            while (st < en) {
                int ansum = arr[i] + arr[j], elsum = arr[st] + arr[en];
                int res = elsum - ansum;
                min1 = min(min1, abs(res));
                if (res > 0) en--;
                else st++;
            }
        }
    }
    cout << min1;
}