#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 200001

using namespace std;

int n, c, ans;

vector<int> v1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    loop(i, 1, n){
        int t;
        cin >> t;
        v1.push_back(t); 
    }

    sort(v1.begin(), v1.end());

    int st = 1, en = v1[n - 1] - v1[0];

    while(st <= en){
        int cnt = 1;
        int mid = (st + en) / 2;
        int last_position = v1[0];

        loop(i, 1, n - 1){
            if(v1[i] - last_position >= mid){
                cnt++;
                last_position = v1[i];
            }
        }

        if(cnt >= c){
            ans = mid;
            st = mid + 1;
        } else {
            en = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
