#include <bits/stdc++.h>
#define endl '\n'

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

    int m, n;

    cin >> m >> n;

    vector<int> prime;

    for(int i = m; i <= n; i++){
        if(isPrime(i)) prime.push_back(i);
    }

    sort(prime.begin(), prime.end());

    for(int i = 0; i < prime.size(); i++){
        cout << prime[i] << endl;
    }

}