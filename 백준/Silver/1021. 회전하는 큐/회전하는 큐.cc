#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 51

using namespace std;

int n, m, temp, cnt, arr[MAXN];

deque<int> dq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    loop(i, 1, n) dq.push_back(i);
    loop(i, 1, m) cin >> arr[i];

    loop(i, 1, m){
        if(dq.size() == 1) continue;
        LOOP(j, 0, n){
            if(arr[i] == dq.at(j)){
                temp = j;
                break;
            }
        }
        if(temp <= dq.size() / 2){
            LOOP(j, 0, temp){
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
            dq.pop_front();
        }
        else{
            LOOP(j, 0, dq.size() - temp){
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
            dq.pop_front();
        }
    }
    cout << cnt;
}