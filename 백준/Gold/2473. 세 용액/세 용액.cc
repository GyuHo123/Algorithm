#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 10001

using namespace std;

ll n, arr[MAXN], min1 = LLONG_MAX;
vector<int> v1;

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
        int en = n - 1;

        while (st < en) {
            int left = arr[st];
            int right = arr[en];
            ll sum = arr[i] + left + right;
            if(abs(sum) <= min1) {
                min1 = abs(sum);
                v1.clear();
                v1.push_back(arr[i]);
                v1.push_back(left);
                v1.push_back(right);
                sort(v1.begin(), v1.end());
                if(!(arr[i] + left + right)) break;
            }
            if(arr[i] + left + right < 0) st++;
            else en--;
        }
    }
    loop(i, 0, 2){
        cout << v1[i] << " ";
    }
}