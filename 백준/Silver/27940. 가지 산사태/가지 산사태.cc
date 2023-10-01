#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 100001

using namespace std;

struct p{
    ll idx, floor;
};

ll n, m, k, t, r;
ll arr[MAXN];
bool collapse = false;
vector<p> floors;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    loop(i, 1, m) {
        if(collapse) break;
        cin >> t >> r;
        loop(j, 0, 0){
            arr[j] += r;
            if(arr[j] > k){
                p t1 = {i, j};
                floors.push_back(t1);
                collapse = 1;
            }
        }
    }
    if(!collapse) cout << -1 << endl;
    else cout << floors[floors.size() - 1].idx << " " << floors[floors.size() - 1].floor + 1;
}
