#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

long long func(int n, int x)
{
    int num = 0;

    for (long long i = x; n / i >= 1; i *= x) {
        num += n / i;
    }

    return num;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;

    long long cnt = 0;
    long long cnt1 = 0;

    cin >> n;
    cin >> m;

    cnt = func(n, 5) - func(n - m, 5) - func(m, 5);
    cnt1 = func(n, 2) - func(n - m, 2) - func(m, 2);

    cout << min(cnt, cnt1) << endl;

    return 0;
}