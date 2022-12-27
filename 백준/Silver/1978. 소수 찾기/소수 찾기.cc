#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num;

    cin >> n;

    vector<int> v;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }
    while(n--){
        if(isPrime(v[n])){
            cnt++;
        }
    }

    cout << cnt;
}