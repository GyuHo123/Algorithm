#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 30001

using namespace std;

int n, d, k, c, arr[MAXN], cnt, kindCnt;
map<int, int> m1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;

    loop(i, 0, n - 1){
        cin >> arr[i];
    }

    loop(i, 0, k - 1){
        if(!m1[arr[i]]) kindCnt++;
        m1[arr[i]]++;
    }
    cnt = kindCnt;
    loop(i, k, n + k - 1){
        int idx = i % n;
        int remove_idx = (i - k) % n;
        if(m1[arr[remove_idx]] == 1) kindCnt--;
        m1[arr[remove_idx]]--;
        if(!m1[arr[idx]]) kindCnt++;
        m1[arr[idx]]++;
        if(!m1[c]) cnt = max(cnt, kindCnt + 1);
        else cnt = max(cnt, kindCnt);
   }
   cout << cnt;

}