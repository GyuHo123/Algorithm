#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1500000

using namespace std;

bool prime[MAXN];
string str;
int n;

void primeD(){
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i < MAXN; i++){
        if(prime[i] == 0) continue;
        for(int j = i + i; j < MAXN; j += i){
            prime[j] = 0;
        }
    }
}

bool isPelin(int num1){
    str = to_string(num1);
    LOOP(i, 0, str.size() / 2){
        if(str[i] != str[str.size() - i - 1]){
            return false;
        }
    }
    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    primeD();

    for(int i = n; i <= MAXN; i++){
        if(!prime[i]) continue;
        if(isPelin(i)){
            cout << i;
            break;
        }
    }
}