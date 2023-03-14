#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001

using namespace std;

int n, temp;
priority_queue<int, vector<int>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    loop(i, 1, n){
        cin >> temp;
        if(!temp){
            if(pq.empty()) cout << 0 << endl;
            else{
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else pq.push(temp);
    }
}