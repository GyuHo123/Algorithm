#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N, K, removed;
string num;
deque<char> dq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    cin >> num;

    for (int i = 0; i < N; ++i) {
        while (removed < K && !dq.empty() && dq.back() < num[i]) {
            dq.pop_back();
            removed++;
        }
        dq.push_back(num[i]);
    }

    while (removed < K) {
        dq.pop_back();
        removed++;
    }

    for (char c : dq) cout << c;
}
