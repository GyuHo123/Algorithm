#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 1000001

using namespace std;

int primeNum[MAXN], n, chk;

void chkPrime(){
    for (int i = 2; i * i <= MAXN; i++){
        if(primeNum[i] == 0){
            for(int j = i * i; j <= MAXN; j += i){
                primeNum[j] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    chkPrime();

    while(true){
        cin >> n;
        if(n == 0) break;
        for(int i = 3; i < n; i++) {
            if (primeNum[i] == 0 && primeNum[n - i] == 0) {
                cout << n << " = " << i << " + " << n - i << endl;
                chk = 1;
                break;
            }
        }
        if(!chk) cout << "Goldbach's conjection is wrong" << endl;
    }
}
