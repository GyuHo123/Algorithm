#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int weights[31];
bool dp[31][40001];

void DFS(int count, int weight) {
    if(dp[count][weight]) return;
    dp[count][weight] = true;

    if(count == n) return;

    DFS(count + 1, weight + weights[count]);  // 현재 추를 오른쪽에 올린 경우
    DFS(count + 1, weight);                   // 현재 추를 올리지 않은 경우
    DFS(count + 1, abs(weight - weights[count]));  // 현재 추를 왼쪽에 올린 경우
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    memset(dp, false, sizeof(dp));
    DFS(0, 0);

    cin >> m;
    vector<int> marbles(m);
    for(int i = 0; i < m; i++) {
        cin >> marbles[i];
    }

    for(int i = 0; i < m; i++) {
        if(marbles[i] > 40000 || !dp[n][marbles[i]]) cout << "N ";
        else cout << "Y ";
    }

    return 0;
}
