#include <bits/stdc++.h>
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
 
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m; cin >> n >> m;
    int v[m] = {0, }, used[n] = {0, };
    loop(i, 0, m - 1) cin >> v[i];
    int ans = 0;
    loop(i, 0, m - 1) {
        int exch = -1; int pos = 0;
        loop(j, 0, n - 1) if(used[j] == v[i]) goto jump;
        loop(j, 0, n - 1) if(!used[j]) { used[j] = v[i]; goto jump; }
        loop(j, 0, n - 1) {
            int p = m;
            loop(k, i + 1, m - 1) if(used[j] == v[k]) { p = k; break; }
            if(p > pos) {
                exch = j; pos = p;
            }
        }
        used[exch] = v[i]; ans++;
        jump:;
    }
    cout << ans << '\n';
}