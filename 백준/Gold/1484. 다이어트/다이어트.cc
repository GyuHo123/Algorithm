#include<bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll G;
    cin >> G;

    ll start = 1, end = 2;
    vector<ll> answer;

    while (true) {
        ll diff = end * end - start * start;
        if (diff == G)
            answer.push_back(end);

        if (diff > G && end - start == 1)
            break;

        if (diff > G)
            start++;
        else
            end++;
    }

    if (!answer.size())
        cout << -1 << endl;
    else {
        for(auto a : answer)
            cout << a << endl;
    }
}
