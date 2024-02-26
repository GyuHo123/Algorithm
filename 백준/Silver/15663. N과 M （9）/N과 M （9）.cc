#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n, m;
vector<int> arr, selected;
vector<vector<int>> results;
bool visited[8];

void dfs(int cnt) {
    if (cnt == m) {
        results.push_back(selected);
        return;
    }
    int prev = -1;
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && arr[i] != prev) {
            visited[i] = true;
            selected.push_back(arr[i]);
            dfs(cnt + 1);
            selected.pop_back();
            visited[i] = false;
            prev = arr[i];
        }
    }
}

int main() {
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end()); 

    dfs(0);

    sort(results.begin(), results.end());
    results.erase(unique(results.begin(), results.end()), results.end()); // 중복 결과 제거

    for (const auto& seq : results) {
        for (int num : seq) {
            cout << num << ' ';
        }
        cout << endl;
    }
}
