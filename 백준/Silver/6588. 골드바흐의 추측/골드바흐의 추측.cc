#include <bits/stdc++.h>
#define endl '\n'

bool isPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    bool b;

    while(true){
        b = false;
        cin >> n;
        if(n == 0) break;
        for(int i = 3; i < n; i++){
            int a = 0;
            if(isPrime(i)){
                a = n - i;
            }
            if(isPrime(a)) {
                cout << n << " = " << i << " + " << a << endl;
                b = true;
                break;
            }
        }
        if(!b) cout << "Goldbach's conjection is wrong" << endl;
    }
}