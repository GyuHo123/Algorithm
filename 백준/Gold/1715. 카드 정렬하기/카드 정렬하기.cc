#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001

using namespace std;

int n, temp, sum, a, b;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    loop(i, 1, n){
        cin >> temp;
        pq.push(temp);
    }

    while(pq.size() > 1){
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        pq.push(a + b);
        sum += a + b;
    }
    cout << sum;
}