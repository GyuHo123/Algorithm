#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int x, nu, deno, n = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x;

    while(x > n){
        x -= n;
        n++;
    }

    if(n % 2 == 0){
        nu = x;
        deno = n + 1 - x;
    }
    else{
        nu = n + 1 - x;
        deno = x;
    }

    cout << nu << '/' << deno << endl;
}