#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(ll i = s; i <= n; i++)
#define LOOP(i, s, n) for(ll i = s; i < n; i++)
#define ll long long int
#define MAXN 2001
 
using namespace std;
 
int arr[MAXN][MAXN], n;
int isRange(int x) {
    return 1 <= x && x <= n;
}
int chkRange(int minX, int maxX, int minY, int maxY) {
    if(isRange(minX) && isRange(maxX) && isRange(minY) && isRange(maxY));
    else return 0;

    int xmid = (minX + maxX) / 2, ymid = (minY + maxY) / 2;

    loop(j, minY, maxY) {
        if(j == minY || j == maxY) {
            loop(i, minX, maxX) {
                if(i == xmid && arr[i][j]);
                else if(i != xmid && !arr[i][j]);
                else return 0;
            }
        }
        else if(j == ymid) {
            if(arr[minX][j] == 1 && arr[maxX][j] == 1);
            else return 0;
        }
        else {
            if(arr[minX][j] == 0 && arr[maxX][j] == 0);
            else return 0;
        }
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    cin >> n;
    loop(i, 1, n) {
        string s;
        cin >> s;
        loop(j, 1, n) arr[i][j] = s[j - 1] - '0';
    }

    int ans = 0;
    vector<pair<int, int>> v[1010];
    loop(i, 1, n)
        loop(j, 1, n)
            if(arr[i][j] && chkRange(i - 1, i + 1, j - 1, j + 1))
                v[0].push_back({i, j});

    ans += v[0].size();

    int idx = 0;
    while(!v[idx].empty()) {
        for(auto t : v[idx]) {
            int x = t.first, y = t.second;
            if(chkRange(x - 2 - idx, x + 2 + idx, y - 2 - idx, y + 2 + idx))
                v[idx + 1].push_back({x, y});
        }
        ans += v[idx + 1].size();
        idx++;
    }
    cout << ans << endl;
}