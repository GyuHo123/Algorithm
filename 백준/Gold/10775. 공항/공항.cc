#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001

using namespace std;

int find(int x, int arr[]) {
    if(arr[x] == x) return x;
    return arr[x] = find(arr[x], arr);
}

int g, p, cnt, temp, emptyGate, gates[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> g >> p;
    loop(i, 1, g) gates[i] = i;
    loop(i, 1, p){
        cin >> temp;
        emptyGate = find(temp, gates);
        if(emptyGate == 0) break;
        gates[emptyGate] = emptyGate - 1;
        cnt++;
    }
    cout << cnt;
}