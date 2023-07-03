#include <bits/stdc++.h>
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long int
#define MAXN 10001

using namespace std;
ll n, cost[MAXN] = {0, };
vector<ll> arr[MAXN], tree[MAXN];
ll dp[MAXN][2];
vector<ll> ans;

void dfs(ll cur, ll prev) {
    for(ll nv : arr[cur])
        if(nv != prev)
            tree[cur].push_back(nv), dfs(nv, cur);
}

void f(ll node, ll prev) {
    vector<ll> child;
    dp[node][0] = cost[node];
    for (ll next : tree[node]) {
        if (next == prev) continue;
        f(next, node);
        dp[node][0] += dp[next][1];
        dp[node][1] += max(dp[next][0], dp[next][1]);
    }
}

void trace(ll node, ll prev, bool include) {
    if (include) {
        ans.push_back(node);
        for (ll next : tree[node]) {
            if (next == prev) continue;
            trace(next, node, false);
        }
    } else {
        for (ll next : tree[node]) {
            if (next == prev) continue;
            if (dp[next][0] > dp[next][1]) {
                trace(next, node, true);
            } else {
                trace(next, node, false);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    loop(i, 1, n) cin >> cost[i];
    loop(i, 1, n - 1) {
        ll a, b; cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1, 1);
    f(1, 0);
    if (dp[1][0] > dp[1][1]) {
        trace(1, 0, true);
    } else {
        trace(1, 0, false);
    }

    sort(ans.begin(), ans.end());
    cout << max(dp[1][0], dp[1][1]) << "\n";
    for (ll v : ans) {
        cout << v << " ";
    }
    return 0;
}