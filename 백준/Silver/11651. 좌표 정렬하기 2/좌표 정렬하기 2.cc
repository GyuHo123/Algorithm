#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

// 비교 함수
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end(), compare);

    for (int i = 0; i < n; i++) {
        cout << points[i].first << " " << points[i].second << endl;
    }
    
}