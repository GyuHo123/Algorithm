#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 501

using namespace std;

ll arr[MAXN], dp[MAXN]; //dp[i] = "i번째 건물을 짓는 데 소요되는 시간"
vector<ll> v[MAXN];
ll n;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    loop(i, 1, n) {
        cin >> arr[i];
        while(1) {
            int temp;
            cin >> temp;
            if(temp == -1) break;
            v[i].push_back(temp);
        }
        if(v[i].size() == 0) dp[i] = arr[i];
    }

    while(true) {
        loop(i, 1, n){
            bool b1;
            if(!dp[i]) b1 = true;
                if(b1) {
                    loop(i, 1, n) {
                        ll maxVal = 0;
                        for (ll val: v[i]) {
                            if (!dp[val]) goto fail;
                            maxVal = max(maxVal, dp[val]);
                        }
                        dp[i] = maxVal + arr[i];
                        fail:;
                    }
                }
        }
        break;
    }
    loop(i, 1, n) cout << dp[i] << endl;
}