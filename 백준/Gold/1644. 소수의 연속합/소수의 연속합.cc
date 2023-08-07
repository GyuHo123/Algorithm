#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 4000001

using namespace std;

int prime[MAXN], n, s, e, sum, cnt;
vector<int> arr;

void primeD(){
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i < MAXN; i++){
        if(prime[i] == 0) continue;
        for(int j = i + i; j < MAXN; j += i){
            prime[j] = 0;
        }
        if(prime[i]) arr.push_back(i);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    primeD();

    while(e <= arr.size()){
        if(sum >= n){
            sum -= arr[s++];
        }
        if(sum < n){
            sum += arr[e++];
        }
        if(sum == n) cnt++;
    }
    cout << cnt;
}