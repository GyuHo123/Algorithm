#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 10000

using namespace std;

int d(int n) {
    int sum = n;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
bool self_numbers[MAXN + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    loop(i, 1, MAXN) {
        int idx = d(i);
        if (idx <= MAXN) {
            self_numbers[idx] = 1;
        }
    }

    loop(i, 1, MAXN) if (!self_numbers[i])cout << i << endl;
}
