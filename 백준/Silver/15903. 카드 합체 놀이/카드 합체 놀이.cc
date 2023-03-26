#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 200001

using namespace std;

priority_queue<ll, vector<ll>, greater<ll>> pq;

ll n, m, temp, a, b, sum;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    loop(i, 1, m){
        cin >> temp;
        pq.push(temp);
    }
    loop(i, 1, n){
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        loop(i, 1, 2) {
            pq.push(a + b);
        }
    }
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
}