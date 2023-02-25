#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1001
#define ll long long

using namespace std;
ll arr[40];

ll fibonacci(int n) {
    arr[0] = 0, arr[1] = 1;
    if (n == 0 || n == 1) return arr[n];
    if (arr[n] == 0) arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return arr[n];
}

int n, input;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n--) {
        cin >> input;
        if(input == 0){
            cout << 1 << " " << 0 << endl;
        }
        else cout << fibonacci(input - 1) << " " << fibonacci(input) << endl;
    }

}

